// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include<deque>
#include "Workstation.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	std::deque<CustomerOrder> pending;
	std::vector<CustomerOrder> completed;
	std::vector<CustomerOrder> incomplete;
	
	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}
	bool Workstation::attemptToMoveOrder() {
		
		if (m_orders.empty())
			return false;

		CustomerOrder& order = m_orders.front();
		if (order.isItemFilled(this->getItemName()) || this->getQuantity() == 0)
		{
			if (m_pNextStation) {
				*m_pNextStation += std::move(order);
			}
			else if (order.isFilled()) {
				completed.push_back(std::move(order));
				
			}
			else {
				incomplete.push_back(std::move(order));
			}
				m_orders.pop_front();
				return true;
		}
		else {
			return false;
		}
		//mistake
		/*if (m_orders.front().isItemFilled(getItemName()) == true) {
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				
				
				moved = true;
			}
			else if (m_pNextStation == nullptr) {
				completed.push_back(std::move(m_orders.front()));
				
				m_orders.pop_front();
				moved = true;
			}
		}
		else {
			if (m_pNextStation != nullptr) {
				*m_pNextStation += std::move(m_orders.front());
				
				
				moved = true;
			}
			else if (m_pNextStation == nullptr) {
				incomplete.push_back(std::move(m_orders.front()));
				m_orders.pop_front();
				moved = true;
			}
		}
		return moved;*/
	}
	std::deque<CustomerOrder>& Workstation::getm_orders() {
		return m_orders;
	}
	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation) {
			os << getItemName() << " --> " << getNextStation()->getItemName() << endl;
		}
		else if (m_pNextStation == nullptr) {
			os << getItemName() << " --> End of Line" << endl;
		}
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

	
}
