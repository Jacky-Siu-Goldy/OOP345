// Chun Kit Jacky Siu - 2021/10/01
// email: jsiu5@myseneca.ca
// ID:134663186
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template < size_t N, typename T >
	class Set {
		size_t capacity_of_collection;
	    size_t numberOfElements;
		static T* element_in_collection;
	public:
		Set<N, T>() : capacity_of_collection{ N } { numberOfElements = 0u; };
		
		size_t size() const { return numberOfElements; };
		
		const T& get(size_t index) const {
			
			return element_in_collection[index];
			
		}
		
		size_t getNumOfEle() const {
			return numberOfElements;
		}

		void operator+=(const T& item) {
			if ((numberOfElements + 1) <= capacity_of_collection) {
				
				T* tempArray = new T[numberOfElements + 1];
				for (size_t i = 0u; i < numberOfElements; ++i) {
					 tempArray[i] = element_in_collection[i];
				}

				delete[] element_in_collection;
				
				element_in_collection = tempArray;
				
				
				
				element_in_collection[numberOfElements] = item;
				
				++numberOfElements;
			}

		}

		~Set() { delete[] element_in_collection; };
	};

	template<size_t N, typename T>
	T* Set<N,T>::element_in_collection{};

	
}
#endif