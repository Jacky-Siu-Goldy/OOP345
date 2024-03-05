
#include "Utilities.h"
#include "Car.h"
// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Racecar.h"
namespace sdds {
	void trim(std::string& str) {
		size_t end = str.find_last_not_of(' ');
		str = (end == std::string::npos) ? "" : str.substr(0, end + 1);

		str.erase(0, str.find_first_not_of(' '));

		/*size_t start = s.find_first_not_of(' ')
		str = (start == std::string::npos) ? "" : str.substr(start);*/
	}

	Vehicle* createInstance(std::istream& in) {
		std::string tag, temp;
		
			getline(in, temp);
		
		
		std::stringstream input(temp);

		getline(input, tag, ',');
		trim(tag);
		if (in)
		{
			if (tag == "C" || tag == "c")
			{
				return new Car(input);
			}
			else if (tag == "R" || tag == "r")
			{
				return new Racecar(input);
			}
			else
				throw std::string{ tag };
		}
		else
			return nullptr;
	}
}