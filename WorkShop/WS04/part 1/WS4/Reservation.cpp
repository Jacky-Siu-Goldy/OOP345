#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	Reservation::Reservation() {
		setEmpty();
	}

	void Reservation::setEmpty() {
		m_reservation_id = "";
		m_name = "";
		m_email = "";
		m_num_of_people = 0u;
		m_day = 0;
		m_hour = 0;
	}

	void Reservation::update(int day, int time) {
		m_day = day;
		m_hour = time;
	}

	void Reservation::trim(std::string& str)
	{
		for (auto i = 0u; i < str.size(); ++i)
		{
			if (str[str.size() - 1] == ' ')
			{
				str.erase(str.size() - 1, str.size());
			}
		}
		for (auto i = 0u; i < str.size(); ++i)
		{
			if (str[0] == ' ')
			{
				str.erase(0, 1);
			}
		}
	}

	Reservation::Reservation(const std::string& res) {

		std::string str = res, party_size, day, hour;

		m_reservation_id = str.substr(0, str.find_first_of(':'));
		str.erase(0, str.find_first_of(':') + 1);
		trim(m_reservation_id);

		m_name = str.substr(0, str.find_first_of(','));
		str.erase(0, str.find_first_of(',') + 1);
		trim(m_name);

		m_email = str.substr(0, str.find_first_of(','));
		str.erase(0, str.find_first_of(',') + 1);
		trim(m_email);

		party_size = str.substr(0, str.find_first_of(','));
		str.erase(0, str.find_first_of(',') + 1);
		trim(party_size);

		day = str.substr(0, str.find_first_of(','));
		str.erase(0, str.find_first_of(',') + 1);
		trim(day);

		hour = str.substr(0, std::string::npos);
		trim(hour);

		m_num_of_people = std::stoul(party_size);

		m_day = std::stoi(day);

		m_hour = std::stoi(hour);
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& reservation) {
		os << "Reservation " << std::setw(10) << std::right << reservation.m_reservation_id;
		os << std::setw(20) << std::right << reservation.m_name<<" ";
		os << std::setw(20) << std::left << "<" + reservation.m_email + ">";

		if (reservation.m_hour >= 6 && reservation.m_hour <= 9) {
			os << "Breakfast on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for ";
		}
		else if (reservation.m_hour >= 11 && reservation.m_hour <= 15) {
			os << "Lunch on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for ";
		}
		else if (reservation.m_hour >= 17 && reservation.m_hour <= 21) {
			os << "Dinner on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for ";
		}
		else {
			os << "Drinks on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for ";
		}

		if (reservation.m_num_of_people > 1) {
			os << reservation.m_num_of_people << " people.\n";
		}
		else
		{
			os << reservation.m_num_of_people << " person.\n";
		}

		return os;
	}
}