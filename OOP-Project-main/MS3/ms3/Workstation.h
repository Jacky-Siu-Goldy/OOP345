#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds {
	
// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
	
	class Workstation : public Station {
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation;
	public:
		Workstation();
		Workstation(const std::string str) : Station(str) { m_pNextStation = nullptr; };
		Workstation(Workstation& station) = delete;
		Workstation(Workstation&& station) = delete;
		Workstation& operator=(Workstation& station) = delete;
		Workstation& operator=(Workstation&& station) = delete;
		std::deque<CustomerOrder>& getm_orders();
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
	extern std::deque<CustomerOrder> pending;
	extern std::vector<CustomerOrder> completed;
	extern std::vector<CustomerOrder> incomplete;
}
#endif
