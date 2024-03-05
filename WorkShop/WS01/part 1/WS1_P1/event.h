#ifndef _SDDS_EVENT_H_
#define _SDDS_EVENT_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

static unsigned int g_sysClock;

namespace sdds
{
	class Event 
	{
		char description[128];
		unsigned int startTime;
	public:
		Event() {};
		void display() {
			static int counter = 1;
			if (description != nullptr && strlen(description) > 0) {
				unsigned int hours, minutes, seconds;
				seconds = startTime % 60;
				minutes = startTime / 60;
				hours = minutes / 60;
				minutes = minutes % 60;
				std::cout << std::setw(2) << counter << ". " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0')
					<< minutes << ":" << std::setw(2) << std::setfill('0') << seconds << " => " << description << std::endl;
			}
			else
			{
				std::cout << std::setw(2) << counter << ". | No Event |" << std::endl;
			}
		};

		void set(char* arrayOfCharacters = NULL) {
			if (arrayOfCharacters != NULL && strlen(arrayOfCharacters) > 0) {
				startTime = g_sysClock;
				strcpy(description, arrayOfCharacters);
			}
			else
			{
				strcpy(description,"");
				startTime = 0;
			}

		}

	};
}

#endif
