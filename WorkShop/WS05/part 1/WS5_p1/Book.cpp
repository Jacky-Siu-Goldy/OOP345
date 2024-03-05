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
		m_book_price = 0;
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
		
		m_description = temp.substr(0, temp.find(','));
		trim(m_description);

		m_year = stoul(year);

		m_book_price = stod(price);
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