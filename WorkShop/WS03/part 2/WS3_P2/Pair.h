// Chun Kit Jacky Siu - 2021/10/01
// email: jsiu5@myseneca.ca
// ID:134663186
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
namespace sdds {
	template<typename V, typename K>
	class Pair {
		 V value1;
		 K key1;
	public:
		Pair() {};
		Pair(const K& key, const V& value) : value1(value), key1(key) {};
		const V& value() const { return value1; };
		const K& key() const { return key1; };
		virtual void display(std::ostream& os) const {
			os << key1 << " : " << value1 << std::endl;
		}
	};
	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif
