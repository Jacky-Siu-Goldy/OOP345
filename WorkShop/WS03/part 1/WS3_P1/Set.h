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
		
		const T& get(size_t index) {
			T nothing{};
			if (element_in_collection != nullptr && index < capacity_of_collection) {
				return element_in_collection[index];
			}
			else {
				return nothing;
			}
		}
		
		void operator+=(const T& item) {
			if ((numberOfElements + 1) <= capacity_of_collection) {
				
				T* tempArray = new T[numberOfElements + 1];
				for (auto i = 0u; i < numberOfElements; ++i) {
					 tempArray[i] = element_in_collection[i];
				}

				delete[] element_in_collection;
				
				element_in_collection = tempArray;
				
				
				
				element_in_collection[numberOfElements] = item;
				
				++numberOfElements;
			}

		}
	};

	template<size_t N, typename T>
	T* Set<N,T>::element_in_collection{};

	
}
#endif