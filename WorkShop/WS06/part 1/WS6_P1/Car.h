#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include <sstream>
#include <string>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle 
	{
		std::string m_maker;
		std::string m_condition;
		double m_topSpeed;

	public:

		Car(std::istream& input);

		
		std::string condition() const;

		double topSpeed() const;

		void display(std::ostream& out) const;
		
	};
}
#endif 
