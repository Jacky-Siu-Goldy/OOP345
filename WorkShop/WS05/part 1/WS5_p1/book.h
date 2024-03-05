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
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}
#endif