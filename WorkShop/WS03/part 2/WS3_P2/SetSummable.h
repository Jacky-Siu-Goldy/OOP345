// Chun Kit Jacky Siu - 2021/10/01
// email: jsiu5@myseneca.ca
// ID:134663186
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {
	template<size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		SetSummable() : Set<N, T>() {};
		
		T accumulate(const std::string& filter)const {
			T temp(filter);
			for (auto i = 0u; i < this->getNumOfEle(); ++i)
			{
				if (this->get(i).isCompatibleWith(temp)) {
					temp += this->get(i);
				}
			}
			return temp;
		}
	};
}
#endif