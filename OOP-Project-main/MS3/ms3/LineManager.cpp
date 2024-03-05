// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <functional>
#include <algorithm>
#include "LineManager.h"
#include "Station.h"
#include "Workstation.h"
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		setEmpty();
		if (file == "") {
			throw string("ERROR: No filename provided.");
		}

		ifstream infile(file);
		if (!infile)
			throw string("Unable to open [" + file + "] file.");

		string record;
		for_each(stations.begin(), stations.end(), [](Workstation* s) {s->setNextStation(); });
		while (!infile.eof())
		{
			std::getline(infile, record);
			bool more = true;
			size_t pos = 0u;
			Utilities util;
			string itemname = util.extractToken(record, pos, more);
			
			auto CS = find_if(stations.begin(), stations.end(), [itemname](const Workstation* currentStation) {
				return  currentStation->getItemName() == itemname;

			});
			if (CS == stations.end()) {
				throw "Error: CurrentStation not found.";
			}
			activeLine.push_back(*CS);
			if (more) {
				string nextStation_str = util.extractToken(record, pos, more);

				auto NS = find_if(stations.begin(), stations.end(), [nextStation_str](const Workstation* nextStation) {
					return nextStation->getItemName() == nextStation_str;

				});

				if (NS == stations.end()) {
					throw "Error: NextStation not found.";
				}

				if (NS == CS) {
					throw "Error: CurrentStation = NextStation.";
				}
				(*CS)->setNextStation(*NS);
				
			}
		}
		
		infile.close();

		for_each(activeLine.begin(), activeLine.end(), [this](Workstation* t) {
			auto found = find_if(activeLine.begin(), activeLine.end(), [&t](const Workstation* s) {
				return s->getNextStation() == t;
				
			});
			if (found == activeLine.end())
			m_firstStation = t;
			
		});
		if (!m_firstStation) {
			throw "Error: m_firstStation = nullptr.";
		}
	}

	void LineManager::setEmpty() {
		m_cntCustomerOrder = 0u;
		filled = 0u;
		m_firstStation = nullptr;
	}

	void LineManager::linkStations() {
		
		vector<Workstation*> inOrder;
		auto iter = m_firstStation;
			
		while (iter) {
			inOrder.push_back(iter);
			iter = iter->getNextStation();
		}
		activeLine = inOrder;
		
	}

	bool LineManager::run(std::ostream& os) {
		static size_t iteration = 0;
		++iteration;
		
	
		if (!pending.empty()) {
			if (iteration == 1)
				for (auto it = pending.begin(); it != pending.end(); ++it) {
					m_cntCustomerOrder += it->getm_cntItem();
				}

			*m_firstStation += std::move(pending.front());
			pending.pop_front();

		}

			os << "Line Manager Iteration: " << iteration << endl;

			for (size_t i = 0u; i < activeLine.size(); ++i)
			{
				activeLine[i]->fill(os);
			}
			for (size_t i = 0u; i < activeLine.size(); ++i) {
				 activeLine[i]->attemptToMoveOrder();
				
			}
			size_t total_completed = 0u, total_incomplete = 0u;
			for (auto it_completed = completed.begin(); it_completed != completed.end(); ++it_completed) {
				total_completed += it_completed->getm_cntItem();
			}
			for (auto it_incomplete = incomplete.begin(); it_incomplete != incomplete.end(); ++it_incomplete) {
				total_incomplete += it_incomplete->getm_cntItem();
			}
			
			if (m_cntCustomerOrder == (total_completed + total_incomplete ))
				return true;
			else 
				return false;
		
	
	}

	void LineManager::display(std::ostream& os)const {
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* currentline) { currentline->display(os); });
	}

	
}