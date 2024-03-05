// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <vector>
#include "Autoshop.h"


namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto i = 0u; i < m_vehicles.size(); ++i)
		{
			m_vehicles[i]->display(out);
			out << std::endl;
		}
		out << "--------------------------------" << std::endl;
	}

	Autoshop::~Autoshop() {
		for (auto i = 0u; i < m_vehicles.size(); ++i)
		{
			delete m_vehicles[i];
			m_vehicles[i] = nullptr;
		}
	}
}