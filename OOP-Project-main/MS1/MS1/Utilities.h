// Name: Jacky Chun Kit Siu
// Seneca Student ID: 134663186
// Seneca email: jsiu5@myseneca.ca
// Date of completion: 2021-11-04
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
namespace sdds
{
	class Utilities
	{
		size_t m_widthField;
		static char m_delimiter;

	public:
		Utilities();
		void setFieldWidth(size_t newWidth); //sets the field width of the current object to the value of the parameter newWidth
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		

		static void setDelimiter(char newDelimiter);//sets the delimiter for this class to the character recieved
		static char getDelimiter();// returns the delimiter for this class
	};


}
#endif