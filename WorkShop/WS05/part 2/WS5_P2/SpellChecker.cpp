// Chun Kit Jacky Siu - 2021/10/17
// email: jsiu5@myseneca.ca
// ID:134663186
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {
	void SpellChecker::setEmpty() {
		for (auto i = 0u; i < 6u; ++i) {
			m_badWords[i] = "";
			m_goodWords[i] = "";
			count[i] = 0;
		}
	}

	SpellChecker::SpellChecker(const char* filename) {
		setEmpty();

		std::ifstream file2(filename);

		if (!file2) {
			throw "Bad file name!";
		}

		size_t index = 0u;

		do
		{
			file2 >> m_badWords[index];
			file2 >> m_goodWords[index];
			++index;
		} while (file2 && index < 6);

	}

	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0u; i < 6; ++i)
		{
			size_t pos = text.find(m_badWords[i]);

			while (pos != std::string::npos) {

				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos = text.find(m_badWords[i], pos + m_goodWords[i].size());
				count[i]++;
			}

		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0u; i < 6; ++i)
		{
			out << std::setw(15) << std::right << m_badWords[i] << ": " << count[i] << " replacements" << std::endl;
		}
	}
}