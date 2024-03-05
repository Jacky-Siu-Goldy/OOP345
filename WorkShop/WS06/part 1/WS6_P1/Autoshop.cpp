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