// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include "Utilities.h"

namespace sdds
{
	class Station
	{
		int m_id;
		std::string m_itemName;
		std::string m_description;
		size_t m_serialNum;
		size_t m_numInStock;
		static size_t m_widthField;
		static int id_generator;

	public:
		Station();

		void setEmpty();
		Station(const std::string str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();

		size_t getQuantity() const;
		void updateQuantity();

		void display(std::ostream& os, bool full) const;
	};

	

}
#endif