#include <utility>
#include "Restaurant.h"

namespace sdds {
	Restaurant::Restaurant() { setEmpty(); }

	void Restaurant::setEmpty() {
		m_reservation = nullptr;
		m_reserve_cnt = 0u;
	}

	Restaurant::Restaurant(const Reservation** reservation, size_t cnt) {
		setEmpty();
		if (reservation != nullptr) {
			m_reservation = new Reservation  [cnt];
			for (auto i = 0u; i < cnt; ++i) {
				m_reservation[i] = *reservation[i];
			}
			m_reserve_cnt = cnt;
		}
	}

	size_t Restaurant::size()const {
		return m_reserve_cnt;
	}

	Restaurant::Restaurant(const Restaurant& src) {
		setEmpty();
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src && src.m_reservation != nullptr) {
			delete[] m_reservation;
			setEmpty();
			m_reservation = new Reservation [src.m_reserve_cnt];
			for (auto i = 0u; i < src.m_reserve_cnt; ++i) {
				m_reservation[i] = src.m_reservation[i];
			}
			m_reserve_cnt = src.m_reserve_cnt;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) {
		setEmpty();
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (this != &src) {
			m_reserve_cnt = src.m_reserve_cnt;
			delete[] m_reservation;
			
			m_reservation = src.m_reservation;

			src.m_reservation = nullptr;
			
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		delete[] m_reservation;
		m_reservation = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant) {
		static size_t CALL_CNT = 1u;
		os << "--------------------------" << std::endl;
		os << "Fancy Restaurant (" << CALL_CNT << ")" << std::endl;
		os << "--------------------------" << std::endl;
		if (restaurant.m_reservation != nullptr && restaurant.m_reserve_cnt > 0) {
			for (auto i = 0u; i < restaurant.m_reserve_cnt; ++i) {
				os << restaurant.m_reservation[i];
			}
			os << "--------------------------" << std::endl;
		}
		else {
			os << "This restaurant is empty!" << std::endl;
			os << "--------------------------" << std::endl;
		}
		++CALL_CNT;
		return os;
	}
}