// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
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
