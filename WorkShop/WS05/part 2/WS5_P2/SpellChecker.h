// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_SPELLCHECKER_H__
#define SDDS_SPELLCHECKER_H__

#include <iostream>
#include <string>
namespace sdds {
	class SpellChecker {
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int count[6];
	public:
		void setEmpty();
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif