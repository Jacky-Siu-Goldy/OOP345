
#include "Utilities.h"
#include "Car.h"

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
			else
				throw std::string{ tag };
		}
		else
			return nullptr;
	}
}