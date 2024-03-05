// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/15
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <cstring>
#include "event.h"

unsigned int g_sysClock;
namespace sdds {

	Event::Event() {
		setEmpty();
	}
	void Event::setEmpty() {
		description = nullptr;
		startTime = 0u;
	}

	void Event::display() {
		static unsigned int counter = 1;//static variable space for it gets allocated for the lifetime of the program
		if (description != nullptr && std::strlen(description) > 0) {
			unsigned int hours, minutes, seconds;
			seconds = startTime % 60;//get number of seconds thats not enough to fill a whole minute
			minutes = startTime / 60;//get the number of whole minutes
			hours = minutes / 60;//get the number of whole hours
			minutes = minutes % 60;//get the number of minutes that is not enough to fill a whole hour

			std::cout<< std::setw(2) << counter << ". " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2)
				<< minutes << ":" << std::setw(2) << seconds << " => " << description << std::setfill(' ') << std::endl;
		}
		else
		{
			std::cout << std::setw(2) << counter << ". | No Event |" << std::endl;
		}
		++counter;//incremented by one for the next time the function is called
	}

	void Event::set(char* arrayOfCharacters) {

		if (arrayOfCharacters != nullptr) {// check if arrayOfCharacters is available
			if (this->description != nullptr)//check if memory is allocated to description
				delete[] description;// delete description if memory is allocated to it

			
			description = new char[std::strlen(arrayOfCharacters) + 1];
			
			std::strcpy(description, arrayOfCharacters);
			startTime = g_sysClock;
		}
		else
		{
			if(this->description != nullptr);
			delete[] description;
			setEmpty();
		}
	}

	Event::Event(Event& src) {
		setEmpty();
		*this = src;
	}

	Event& Event::operator=(Event& src) {
		if (this != &src) {//check if the addresses are not the same, if not the same start copying
			//shallow copy
			startTime = src.startTime;

			//delete previously allocated memory for description
			delete[] description;

			if (src.description != nullptr) {//if src.description is available, allocate dynamic memory to description and copy src.description to this->description
				description = new char[std::strlen(src.description) + 1];
				std::strcpy(description, src.description);
			}
			else
			{
				setEmpty();
			}
		}
		return *this;
	}
	Event::~Event() { delete[] description; description = nullptr; }
}