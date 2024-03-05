// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Station.h"

using namespace std;

namespace sdds
{
	size_t Station::m_widthField = 0u;
	int Station::id_generator = 0;
	
	Station::Station() {
		setEmpty();
	}
	void Station::setEmpty() {
		m_id = 0;
		m_itemName = "";
		m_description = "";
		m_serialNum = 0u;
		m_numInStock = 0u;
	}

	Station::Station(const std::string str)
	{
		setEmpty();
		++id_generator;
		m_id = id_generator;

		bool more = true;
		size_t pos = 0u;

		Utilities util;

		m_itemName = util.extractToken(str, pos, more);
		
		string serial = util.extractToken(str, pos, more);
		string quatity = util.extractToken(str, pos, more);
		if (m_widthField < util.getFieldWidth())
			m_widthField = util.getFieldWidth();
		m_description = util.extractToken(str, pos, more);
		
		m_serialNum = std::stoi(serial);
		m_numInStock = std::stoi(quatity);
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		m_serialNum++;
		return m_serialNum - 1;
	}

	size_t Station::getQuantity() const {
		return m_numInStock;
	}

	void Station::updateQuantity() {
		--m_numInStock;
	}

	void Station::display(std::ostream& os, bool full) const {

		if (full)
		{

			os << "[" << setw(3) << right << setfill('0') << m_id << "]" << setfill(' ');
			os << " Item: " << setw(m_widthField) << left << m_itemName;
			os << " [" << setw(6) << right << setfill('0') << m_serialNum << "]" << setfill(' ');
			os << " Quantity: " << setw(m_widthField) << left << m_numInStock;
			os << " Description: " << m_description << endl;
		}
		else
		{
			os << "[" << setw(3) << right << setfill('0') << m_id << "]" << setfill(' ');
			os << " Item: " << setw(m_widthField) << left << m_itemName;
			os << " [" << setw(6) << right << setfill('0') << m_serialNum << "]" << setfill(' ') << endl;
		}
	}
}