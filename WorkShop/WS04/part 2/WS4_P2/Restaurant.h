#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__
#include <iostream>
#include "Reservation.h"
namespace sdds {
	class Restaurant {
		Reservation* m_reservation;
		size_t m_reserve_cnt;
	public:
		Restaurant();
		Restaurant(const Reservation* reservation[], size_t cnt);/*a constructor that receive as a parameter an array of pointers
																to objects of type Reservation Reservation* (each element of the array is a pointer).
																(chapter Abstract Base Casses, section Array of pointers).

																this constructor should store all copies of all reservations*/
		void setEmpty();

		size_t size() const; //a query that returns the number of reservations in the system.

		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant& operator=(Restaurant&& src);
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& restaurant);
		~Restaurant();
	};
}
#endif