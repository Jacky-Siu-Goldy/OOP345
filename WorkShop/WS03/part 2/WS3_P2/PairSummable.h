// Chun Kit Jacky Siu - 2021/10/01
// email: jsiu5@myseneca.ca
// ID:134663186
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "Pair.h"

namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V,K> {
		static V initial;
		static size_t min_field_width;
	public:
		PairSummable() : Pair<V,K>() {};
		PairSummable(const K& key, const V& value = initial) : Pair<V,K>(key, value)  {
			size_t temp_field_width = key.size();
			if (temp_field_width > min_field_width) {
				min_field_width = temp_field_width;
			}
		};
		bool isCompatibleWith(const PairSummable<V, K>& b)const {
			return this->key() == b.key();
		};

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& src) {
			
			PairSummable<V,K> temp(this->key(), this->value() + src.value());
			*this = temp;
			
			return *this;
		}
		
		void display(std::ostream& os)const {
			os << std::setw(min_field_width) << std::left;
			Pair<V, K>::display(os);
			os << std::setw(0) << std::right;
		};
	};

	template<typename V, typename K>
	V PairSummable<V, K>::initial{};
	
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& src) {

		std::string temp;
		if (src.value() == "") {
			temp = this->value();
		}
		else if (this->value() == "") {
			temp = this->value() + src.value();
		}
		else {
			temp = this->value() + ", " + src.value();
		}
		PairSummable<std::string, std::string> tObj(this->key(), temp);
		
		*this = tObj;

		return *this;
	}
	
	

	template<typename V, typename K>
	size_t PairSummable<V, K>::min_field_width = 0u;
}
#endif