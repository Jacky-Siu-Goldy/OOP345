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
		void display(std::ostream& os) const {
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
