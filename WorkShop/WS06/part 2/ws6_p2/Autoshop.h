// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"
#include "Car.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto i = 0u; i < m_vehicles.size(); ++i)
			{
				if (test(m_vehicles[i]))
				{
					vehicles.push_back(m_vehicles[i]);
				}
			}
		}
	};
}
#endif
