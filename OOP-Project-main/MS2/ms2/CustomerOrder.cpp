#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0u;

	CustomerOrder::CustomerOrder() {
		setEmpty();
	}

	void CustomerOrder::setEmpty() {
		m_name = "";
		m_product = "";
		m_cntItem = 0u;
		m_1stItem = nullptr;
	}
	CustomerOrder::CustomerOrder(const std::string str) {
		setEmpty();
		bool more = true;
		size_t next_pos = 0u;
		Utilities util;
		try {
			m_name = util.extractToken(str, next_pos, more);
			m_product = util.extractToken(str, next_pos, more);

			Item* items[1000]{};
			while (more) {
				items[m_cntItem] = new Item(util.extractToken(str, next_pos, more));
				++m_cntItem;
			}

			m_1stItem = new Item * [m_cntItem];
			for (auto i = 0u; i < m_cntItem; ++i) {
				m_1stItem[i] =std::move(items[i]);
			}

			m_widthField = max(util.getFieldWidth(), m_widthField);
		}
		catch (string& msg)
		{
			cout << msg;
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
		setEmpty();
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)noexcept {
		if (this != &src) {
			m_name = src.m_name;
			src.m_name = "";
			m_product = src.m_product;
			src.m_product = "";

			if (this->m_1stItem)
			{
				for (auto i = 0u; i < m_cntItem; ++i)
				{
					delete m_1stItem[i];
				}
				delete[] m_1stItem;


			}

			m_cntItem = src.m_cntItem;
			m_1stItem = new Item * [m_cntItem];
			src.m_cntItem = 0u;
			for (auto i = 0u; i < m_cntItem; ++i)
			{
				m_1stItem[i] = src.m_1stItem[i];
				
			}
			

		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
	
		for (auto i = 0u; i < m_cntItem; ++i) {
			delete m_1stItem[i];
		}
		delete[] m_1stItem;
		m_1stItem = nullptr;
	}

	bool CustomerOrder::isFilled() const {
		bool status = true;
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			if (!m_1stItem[i]->m_isFilled)
				status = false;

		}

		return status;
	}

	bool CustomerOrder::isItemFilled(const std::string& ItemName)const {
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			if (m_1stItem[i]->m_itemName == ItemName) {
				
				return m_1stItem[i]->m_isFilled;
					
			}
		}

		return true;

	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (auto i = 0u; i < m_cntItem; ++i) {
			if (m_1stItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					m_1stItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_1stItem[i]->m_isFilled = true;
					os << setw(11) << right << "Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
				}
				else {
					os << setw(10) << right << "Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os)const {
		os << m_name << " - " << m_product << endl;
		for (auto i = 0u; i < m_cntItem; ++i)
		{
			os << "[" << setw(6) << setfill('0') << right << m_1stItem[i]->m_serialNumber << "] " << setfill(' ') << setw(m_widthField) << left << m_1stItem[i]->m_itemName;
			if (m_1stItem[i]->m_isFilled) {
				os << " - FILLED" << endl;
			}
			else {
				os << " - TO BE FILLED" << endl;
			}
		}
	}


}