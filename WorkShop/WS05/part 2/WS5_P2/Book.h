// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include <string>
namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country_of_publication;
		size_t m_year;
		double m_book_price;
		std::string m_description;

	public:

		Book();
		void setEmpty();
		void trim(std::string& str);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year()const;
		double& price();
		Book(const std::string& strBook);
		Book& operator=(const Book& src);
		Book& operator=(Book&& src)noexcept;
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
		template<typename T>
		void fixSpelling(T& spellchecker) {
			spellchecker(m_description);
		}
	};
}
#endif