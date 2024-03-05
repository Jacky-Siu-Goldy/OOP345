#ifndef _SDDS_RACECAR_H
#define _SDDS_RACECAR_H 
#include <iostream>
// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out)const;
		double topSpeed() const;
	};
}
#endif
