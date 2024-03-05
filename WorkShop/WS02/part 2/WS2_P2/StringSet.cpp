// Name: Jacky Chun Kit Siu
// Email: jsiu5@myseneca.ca
// ID: 134663186
// Date: 2021/09/24
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO WARNINGS
#include<string>
#include<cstring>
#include<fstream>
#include<utility>// for move()
#include "StringSet.h"

namespace sdds {
	StringSet::StringSet() {
		setEmpty();
	};

	void StringSet::setEmpty() {
		m_String_Array = nullptr;
		m_Max_Index = 0u;
	};

	StringSet::StringSet(const char* fileName) {
		setEmpty();

		std::ifstream fileIn;
		fileIn.open(fileName);
		std::string tempString;

		if (fileIn.is_open()) {
			while (getline(fileIn, tempString, ' ')) {
				m_Max_Index++;
			}
			fileIn.close();
		}

		m_String_Array = new std::string[m_Max_Index];
		std::ifstream fileIn2;
		fileIn2.open(fileName);
		if (fileIn2.is_open())
		{
			for (auto index = 0u; index < m_Max_Index; ++index) {
				getline(fileIn2, tempString, ' ');
				m_String_Array[index] = tempString;
			}

			fileIn2.close();
		}
	};

	StringSet::StringSet(const StringSet& src) {
		setEmpty();
		*this = src;
	}

	StringSet& StringSet::operator =(const StringSet& src) {
		if (this != &src) {
			m_Max_Index = src.m_Max_Index;//shallow copy

			delete[] m_String_Array;

			m_String_Array = new std::string[m_Max_Index];
			for (auto index = 0u; index < m_Max_Index; ++index)
			{
				m_String_Array[index] = src.m_String_Array[index];
			}
		}
		return *this;
	};

	size_t StringSet::size() {
		return m_Max_Index;
	}

	std::string StringSet::operator[](size_t stringArrayIndex) {
		if (m_String_Array != nullptr && stringArrayIndex < m_Max_Index)
		{
			return m_String_Array[stringArrayIndex];
		}
		else {
			return "";
		}
	}

	StringSet::StringSet(StringSet&& src) {
		setEmpty();

		*this = std::move(src);
	}

	StringSet& StringSet::operator=(StringSet&& src)noexcept {
		if (this != &src) {
			m_Max_Index = src.m_Max_Index;//shallow copy
			src.m_Max_Index = 0u;

			delete[]m_String_Array;

			m_String_Array = src.m_String_Array;

			src.m_String_Array = nullptr;

			
		}
		

		return *this;
	}

	StringSet::~StringSet() {
		delete[] m_String_Array;
	}
}