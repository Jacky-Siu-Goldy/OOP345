/*
Date: 2021 - 11 - 13
Name : Chun Kit Jacky Siu
id : 134663186
email : jsiu5@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{
	void trim(std::string& str);
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		std::string m_price;
		std::string m_release_year;
		std::string m_length_of_song;
		size_t mins, seconds , length;
		Song();
	};

	class SongCollection
	{
		
		std::vector<Song> m_SongCollection;

	public:
		SongCollection(const char* filename);
		
		void sort(const char* str);
		void cleanAlbum();
		bool inCollection(const char* name)const;
		std::list<Song> getSongsForArtist(const char* name) const;
		
		void display(std::ostream& out);
		
	};
	bool replace2(Song& song);
	std::ostream& operator<<(std::ostream& out, const Song theSong);
}
#endif
