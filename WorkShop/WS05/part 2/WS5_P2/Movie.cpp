// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	Movie::Movie() {
		setEmpty();
	}

	void Movie::setEmpty() {
		m_title = "";
		m_year = 0u;
		m_description = "";
	}

	void Movie::trim(std::string& str) {
		size_t end = str.find_last_not_of(' ');
		str = (end == std::string::npos) ? "" : str.substr(0, end + 1);

		str.erase(0, str.find_first_not_of(' '));

		/*size_t start = s.find_first_not_of(' ')
		str = (start == std::string::npos) ? "" : str.substr(start);*/
	}

	const std::string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const std::string& strMovie) {
		setEmpty();
		std::string temp = strMovie, year;

		m_title = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(m_title);

		year = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(year);

		m_description = temp;
		trim(m_description);

		m_year = stoul(year);
	}

	Movie& Movie::operator=(const Movie& movie) {
		if (this != &movie)
		{
			m_title = movie.m_title;
			m_year = movie.m_year;
			m_description = movie.m_description;
		}
		return *this;
	}

	Movie& Movie::operator=(Movie&& movie)noexcept {
		if (this != &movie)
		{
			m_title = movie.m_title;
			m_year = movie.m_year;
			m_description = movie.m_description;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie) {
		os << std::setw(40) << std::right << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << std::left << movie.m_description << std::endl;

		return os;
	}

}