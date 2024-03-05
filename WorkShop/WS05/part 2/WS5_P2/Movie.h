// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__
#include <iostream>
#include <string>
namespace sdds {
	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		void setEmpty();
		void trim(std::string& str);
		const std::string& title() const;

		Movie(const std::string& strMovie);
		Movie& operator=(const Movie& movie);
		Movie& operator=(Movie&& movie)noexcept;
		template<typename T>
		void fixSpelling(T& spellchecker) {
			spellchecker(m_description);
			spellchecker(m_title);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif
