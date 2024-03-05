#ifndef _SDDS)UTILITIES_H
#define _SDDS_UTILITIES_H
#include <iostream>
#include"Vehicle.h"
namespace sdds {
	
		void trim(std::string& str);
		Vehicle* createInstance(std::istream& in);

}
#endif