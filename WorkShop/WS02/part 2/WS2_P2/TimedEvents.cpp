// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <chrono>
#include "TimedEvents.h"
namespace sdds {
	Event::Event() : em_event_name{}, em_duration {} {
		std::strcpy(em_predefined_units_of_time, "nanoseconds");
	};

	TimedEvents::TimedEvents() : m_start{}, m_end{}, m_event{}{
		m_numberOfRecord = 0;
	};

	void TimedEvents::startClock() {
		m_start = std::chrono::steady_clock::now();
	};

	void TimedEvents::stopClock() {
		m_end = std::chrono::steady_clock::now();
	};

	void TimedEvents::addEvent(const char* eventname) {
		if (eventname != nullptr && m_numberOfRecord < 10) {
			std::strcpy(m_event[m_numberOfRecord].em_event_name, eventname);
			m_event[m_numberOfRecord].em_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);
			++m_numberOfRecord;
		}
	};

	std::ostream& operator<<(std::ostream& os, const TimedEvents& timedevents) {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (int i = 0; i < timedevents.m_numberOfRecord; ++i)
		{
			os  << std::setw(21) << std::left << timedevents.m_event[i].em_event_name;
			os  << std::setw(13) << std::right << timedevents.m_event[i].em_duration.count() << " " << timedevents.m_event[i].em_predefined_units_of_time << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}