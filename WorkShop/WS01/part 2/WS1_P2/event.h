#ifndef _SDDS_EVENT_H_
#define _SDDS_EVENT_H_
#define _CRT_SECURE_NO_WARNINGS
// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/15
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include<iostream>
#include<iomanip>

extern unsigned int g_sysClock;// set g_sysClock as a global variable with external linkage

namespace sdds {
	class Event
	{
		char* description;
		unsigned int startTime;
	public:
		Event();
		void setEmpty();
		void display();
		void set(char* arrayOfCharacters = nullptr);
		
		Event(Event& src);
		Event& operator=(Event& src);
		~Event();
	};
	
	
}
#endif