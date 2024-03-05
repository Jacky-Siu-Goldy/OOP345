#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include <iostream>
#include <string>
#include <cstring>

namespace sdds {
	class Reservation {
		std::string m_reservation_id;
		std::string m_name;
		std::string m_email;
		size_t m_num_of_people;
		int m_day;
		int m_hour;
	public:
		Reservation();
		Reservation(const Reservation& src);
		Reservation& operator=(const Reservation& src);
		void trim(std::string& str);
		void setEmpty();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
	};
}
#endif
