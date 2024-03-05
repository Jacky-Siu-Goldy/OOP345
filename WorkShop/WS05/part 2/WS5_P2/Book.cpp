// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book() {
		setEmpty();
	}

	void Book::setEmpty() {
		m_author = "";
		m_title = "";
		m_country_of_publication = "";
		m_year = 0u;
		m_book_price = 0.00;
		m_description = "";
	}

	const string& Book::title() const {
		return m_title;
	}

	const string& Book::country() const {
		return m_country_of_publication;
	}

	const size_t& Book::year() const {
		return m_year;
	}

    double& Book::price() {
		return m_book_price;
	}

	void Book::trim(string& str) {
		size_t end = str.find_last_not_of(' ');
		str = (end == std::string::npos) ? "" : str.substr(0, end + 1);
		
		str.erase(0, str.find_first_not_of(' '));

		/*size_t start = s.find_first_not_of(' ')
		str = (start == std::string::npos) ? "" : str.substr(start);*/
	}

	Book::Book(const string& strBook) {
		setEmpty();

		string temp = strBook, year, price;

		m_author = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(m_author);

		m_title = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(m_title);

		m_country_of_publication = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(m_country_of_publication);

		

		price = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(price);
		
		year = temp.substr(0, temp.find(','));
		temp.erase(0, temp.find(',') + 1);
		trim(year);
		
		m_description = temp;
		trim(m_description);

		m_year = stoi(year);

		m_book_price = stod(price);
	}

	Book& Book::operator=(const Book& src) {
		if (this != &src) {
			m_author = src.m_author;
			m_title = src.m_title;
			m_country_of_publication = src.m_country_of_publication;
			m_year = src.m_year;
			m_book_price = src.m_book_price;
			m_description = src.m_description;
			
		}
		return *this;
	}

	Book& Book::operator=(Book&& src) noexcept {
		if (this != &src) {
			m_author = src.m_author;
			m_title = src.m_title;
			m_country_of_publication = src.m_country_of_publication;
			m_year = src.m_year;
			m_book_price = src.m_book_price;
			m_description = src.m_description;

		}
		return *this;
	}

	ostream& operator<<(ostream& os, const Book& book) {
		os << setw(20) << right << book.m_author << " | ";
		os << setw(22) << right << book.m_title << " | ";
		os << setw(5) << right << book.m_country_of_publication << " | ";
		os << setw(4) << left << book.m_year << " | ";
		os << setw(6) << right << setprecision(2) << std::fixed << book.m_book_price << " | ";
		os << left << book.m_description << endl;
		
		return os;

	}
}