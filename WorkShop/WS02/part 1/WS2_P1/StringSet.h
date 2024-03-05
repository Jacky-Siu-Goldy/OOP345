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
		~StringSet();
	};
}
#endif