// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include <iostream>
#include"Vehicle.h"
namespace sdds {
	
		void trim(std::string& str);
		Vehicle* createInstance(std::istream& in);

}
#endif