// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include <sstream>
#include "Utilities.h"

using namespace std;

namespace sdds
{

	char Utilities::m_delimiter = ' ';
	Utilities::Utilities() {
		m_widthField = 0u;
	};

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {

		static string remaining_str;
		string token = "";


		if (more)
		{
			if (next_pos == 0)
				remaining_str = str;
			else
				remaining_str = str.substr(next_pos + 1, str.size() - next_pos - 1);

			token = str.substr(next_pos, str.find(m_delimiter, next_pos) - next_pos);
			if (next_pos == 0 && str.find(m_delimiter) == 0)
			{
				more = false;
				if (token.length() > this->getFieldWidth())
					this->setFieldWidth(token.length());

				if (token == "")
				{
					throw ("error");
				}
			}
			else if (next_pos == 0 && str.find(m_delimiter) == string::npos)
			{
				more = false;
				if (token.length() > this->getFieldWidth())
					this->setFieldWidth(token.length());

				if (token == "")
				{
					throw ("error");
				}
			}
			else if (next_pos == 0 && str.find(m_delimiter) > 0)
			{
				next_pos = next_pos + token.size();
				more = true;
				if (token.length() > this->getFieldWidth())
					this->setFieldWidth(token.length());

				if (token == "")
				{
					more = false;
					throw ("error");
				}
			}
			else if (str.find(m_delimiter, next_pos + 1) != string::npos && next_pos != 0)
			{
				token = str.substr(next_pos + 1, str.find(m_delimiter, next_pos + 1) - next_pos - 1);

				next_pos = next_pos + token.size();
				next_pos++;

				more = true;
				if (token.length() > this->getFieldWidth())
					this->setFieldWidth(token.length());

				if (token == "")
				{
					more = false;
					throw ("error");
				}
				
			}
			else if (str.find(m_delimiter, next_pos + 1) == string::npos && next_pos < str.length())
			{
				token = remaining_str;
				next_pos = next_pos + token.size();
				next_pos++;
				more = false;
				if (token.length() > this->getFieldWidth())
					this->setFieldWidth(token.length());

				if (token == "")
				{
					
					throw ("error");
				}
				
			}


		}
		
		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}

/*else if (next_pos > 0 && str.find(m_delimiter, next_pos + 1) == next_pos + 1)
{
				if (token == "")
				{
					more = false;
					throw ("error");
				}
}*/