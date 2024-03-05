// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <string>
#include <chrono>
namespace sdds {
	struct Event {
		char em_event_name[1024];
		char em_predefined_units_of_time[1024];
		std::chrono::steady_clock::duration em_duration;
		Event();
	};

	class TimedEvents {
		int m_numberOfRecord;
		std::chrono::time_point<std::chrono::steady_clock> m_start;
		std::chrono::time_point<std::chrono::steady_clock> m_end;
		Event m_event[10];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventname);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& timedevents);

	};
}
#endif
