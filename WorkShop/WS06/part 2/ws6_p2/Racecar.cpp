// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string booster;
		in >> booster;
		
		m_booster = std::stod(booster);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed()const {
		double topSpeed = Car::topSpeed();
		topSpeed = topSpeed * (1 + m_booster);
		return topSpeed;
	}
}