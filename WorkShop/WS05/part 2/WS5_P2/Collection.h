// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H__
#define SDDS_COLLECTION_H__

#include <string>
namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name_of_collection;
		T* m_array_of_items;
		size_t  m_size_of_array;
		void (*m_observer)(const Collection<T>& arr, const T& element);
	public:
		Collection<T>(const std::string& name) {
			m_name_of_collection = name;
			m_array_of_items = nullptr;
			m_size_of_array = 0u;
			m_observer = nullptr;
		}

		~Collection<T>()
		{
			delete[] m_array_of_items;
		}

		Collection<T>(const Collection<T>& src) = delete;
		Collection<T>& operator=(const Collection<T>& src) {
			if (this != &src)
			{
				m_name_of_collection = src.m_name_of_collection;
				delete[] m_array_of_items;
				m_array_of_items = nullptr;
				m_array_of_items = new T[src.m_size_of_array];
				for (size_t i = 0u; i < src.m_size_of_array; ++i)
				{
					m_array_of_items[i] = src.m_array_of_items[i];
				}
				m_size_of_array = src.m_size_of_array;
			}

			return *this;
		};

		Collection<T>(Collection<T>&& src) = delete;

		Collection<T>& operator=(Collection<T>&& src) {
			if (this != &src) {
				m_name_of_collection = src.m_name_of_collection;
				delete[] m_array_of_items;
				m_array_of_items = nullptr;
				m_array_of_items = src.m_array_of_items;
				src.m_array_of_items = nullptr;
				m_size_of_array = src.m_size_of_array;
				src.m_size_of_array = 0u;
			}
			return *this;
		}

		const std::string& name() const {
			return m_name_of_collection;
		}

		size_t size() const {
			return m_size_of_array;
		}

		void setObserver(void (*observer)(const Collection<T>& arr, const T& element)) {
			m_observer = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			if (this->size() == 0u)
			{
				m_array_of_items = new T[1];
				m_array_of_items[0] = item;
				++m_size_of_array;
			}
			else
			{
				for (auto i = 0u; i < this->size(); ++i)
				{
					if (m_array_of_items[i].title() == item.title())
						return*this;
				}

				T* temp = new T[m_size_of_array];
				for (auto i = 0u; i < m_size_of_array; ++i)
				{
					temp[i] = m_array_of_items[i];
				}

				delete[] m_array_of_items;
				m_array_of_items = new T[m_size_of_array + 1];

				for (auto i = 0u; i < m_size_of_array; ++i)
				{
					m_array_of_items[i] = temp[i];
				}

				m_array_of_items[m_size_of_array] = item;
				++m_size_of_array;

				if (m_observer != nullptr) {
					m_observer(*this, item);
				}

				delete[] temp;
			}

			return *this;
		}

		T& operator[](size_t idx)const {
			if (idx >= this->size())
			{
				std::string what_arg = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(this->size()) + "] items.";
				throw std::out_of_range((what_arg));
			}
			else {
				return m_array_of_items[idx];
			}
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
			for (auto i = 0u; i < collection.size(); ++i)
			{
				os << collection.m_array_of_items[i];
			}
			return os;
		}

		T* operator[](const std::string& title)const {
			bool foundTitle = false;
			size_t foundIndex = 0u;
			for (auto i = 0u; i < this->size(); ++i)
			{
				if (m_array_of_items[i].title() == title) {
					foundTitle = true;
					foundIndex = i;
				}
			}
			if (foundTitle) {
				return& m_array_of_items[foundIndex];
			}
			else {
				return nullptr;
			}
		}

	};
}
#endif
