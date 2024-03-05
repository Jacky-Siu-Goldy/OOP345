// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include<string>
namespace sdds {
	class StringSet {
		std::string* m_String_Array;
		size_t m_Max_Index;
	public:
		StringSet();
		void setEmpty();
		StringSet(const char* fileName);
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		size_t size();
		std::string operator[](size_t stringArrayIndex);
		StringSet(StringSet&& src);
		StringSet& operator=(StringSet&& src)noexcept;
		~StringSet();
	};
}
#endif