/*
Date: 2021 - 11 - 13
Name : Chun Kit Jacky Siu
id : 134663186
email : jsiu5@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include<iomanip>
#include <algorithm>
#include<functional>
#include<sstream>
#include "SongCollection.h"

using namespace std;

namespace sdds
{
	Song::Song() {
		m_artist = "";
		m_title = "";
		m_album = "";
		m_price = "";
	    m_release_year = "";
	    m_length_of_song = "";
		mins = 0u;
		seconds = 0u;
		length = 0u;
	}

	void trim(std::string& str)
	{
		size_t end = str.find_last_not_of(' ');
		str = (end == std::string::npos) ? "" : str.substr(0, end + 1);

		str.erase(0, str.find_first_not_of(' '));

		/*size_t start = s.find_first_not_of(' ')
		str = (start == std::string::npos) ? "" : str.substr(start);*/
	}

	void SongCollection::sort(const char* str) {
		string title = "title", album = "album", length = "length";
		if (strcmp(title.c_str(), str) == 0)
		{
			std::sort(m_SongCollection.begin(), m_SongCollection.end() , [](const Song& s1, const Song& s2) { return s1.m_title < s2.m_title; });
		}
		else if (strcmp(album.c_str(), str) == 0)
		{
			std::sort(m_SongCollection.begin(), m_SongCollection.end(), [](const Song& s1,const Song& s2) { return s1.m_album < s2.m_album; });
		}
		else if (strcmp(length.c_str(), str) == 0)
		{
			std::sort(m_SongCollection.begin(), m_SongCollection.end(), [](const Song& s1,const Song& s2) { return s1.length < s2.length; });
		}

	}

	
	void SongCollection::cleanAlbum() {
		std::transform(m_SongCollection.begin(), m_SongCollection.end(), m_SongCollection.begin(), [](Song& song) {if (song.m_album == "[None]") 
			 song.m_album = ""; 
		return song;
		});
			
	}

	bool SongCollection::inCollection(const char* name)const {
		auto foundOrNot = std::find_if(m_SongCollection.begin(), m_SongCollection.end(), [=](Song song)->bool {return  strcmp(song.m_artist.c_str(), name) == 0; });
		return foundOrNot != m_SongCollection.end();
	}
	

	std::list<Song> SongCollection::getSongsForArtist(const char* name)const {
		
		int n = std::count_if(m_SongCollection.begin(), m_SongCollection.end(), [=](const Song song) { return strcmp(song.m_artist.c_str(), name) == 0; });

		std::list<Song> SongsOfArtist(n);
		std::copy_if(m_SongCollection.begin(), m_SongCollection.end(), SongsOfArtist.begin(), [=](const Song song) { return strcmp(song.m_artist.c_str(), name) == 0; });

		
		return SongsOfArtist;
		
	}

	SongCollection::SongCollection(const char* filename) {

		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			return;
		}
		while (file)
		{
			std::string temp;
			getline(file, temp);
			Song song;
			std::string t_title, t_artist, t_album, t_price, t_release_year, t_length_of_song;
				t_title = temp.substr(0, 25);
				temp.erase(0, 25);
				trim(t_title);
				song.m_title = t_title;
				t_artist = temp.substr(0, 25);
				temp.erase(0, 25);
				trim(t_artist);
				song.m_artist = t_artist;
				t_album = temp.substr(0, 25);
				temp.erase(0, 25);
				trim(t_album);
				song.m_album = t_album;
				t_release_year = temp.substr(0, 5);
				temp.erase(0, 5);
				trim(t_release_year);
				t_length_of_song = temp.substr(0, 5);
				temp.erase(0, 5);
				trim(t_length_of_song);
				t_price = temp.substr(0, 5);
				trim(t_price);

				stringstream ss(t_length_of_song);
				
				ss >> song.length;
				song.seconds = song.length;
				song.mins = song.seconds / 60;
				song.seconds = song.seconds % 60;
				string strmins, strseconds;
				song.m_release_year = t_release_year;

				if (t_length_of_song != "")
				{
					strmins = to_string(song.mins);
					strseconds = to_string(song.seconds);
					
				    if (song.seconds == 9 || song.seconds == 8 || song.seconds == 7 
						|| song.seconds == 6 || song.seconds == 5 || song.seconds == 4 
						|| song.seconds == 3 || song.seconds == 2 || song.seconds == 1 
						|| song.seconds == 0)
						song.m_length_of_song = strmins + ":" + "0" + strseconds;
					else 
						song.m_length_of_song = strmins + ":" + strseconds;
				}
				else
				{
					song.m_length_of_song = t_length_of_song;
				}

				
				song.m_price = t_price;

				m_SongCollection.push_back(song);
		}
		m_SongCollection.pop_back();
	}

	
    ostream& operator<<(ostream& out, const Song theSong) {
		out << "| " << setw(20) << left << theSong.m_title << " | ";
		out << setw(15) << left << theSong.m_artist << " | ";
		out << setw(20) << left << theSong.m_album << " | ";
		out << setw(6) << right << theSong.m_release_year << " | ";
		out << theSong.m_length_of_song << " | ";
		out << setprecision(2) << fixed << theSong.m_price << " |";
		return out;
	}

	

	void SongCollection::display(ostream& out) {
		size_t total_length = 0u, total_hours, total_mins, total_seconds;;
		for_each(m_SongCollection.begin(), m_SongCollection.end(), [&total_length, &out ](const Song& s1) { out << s1 <<endl; total_length += s1.length; });
		
		
		out << "----------------------------------------------------------------------------------------" << endl;
			string final_result, string_h, string_m, string_s;
			total_hours = total_length / 3600;
			total_mins = (total_length - 3600 * total_hours) / 60;
			string_h = to_string(total_hours);
			
			string_m = to_string(total_mins);
			total_seconds = (total_length - 3600 * total_hours) - (total_mins * 60);
			string_s = to_string(total_seconds);
			std::array<size_t, 10> MorSvalue = { 9u, 8u, 7u, 6u, 5u, 4u, 3u, 2u, 1u, 0u};
			if (total_length != 0u) {
				if (any_of(MorSvalue.begin(), MorSvalue.end(), [=](size_t min) { return total_mins == min; }))
				{
					if (any_of(MorSvalue.begin(), MorSvalue.end(), [=](size_t seconds) { return total_seconds == seconds; }))
					{
						final_result = "Total Listening Time: " + string_h + ":0" + string_m + ":0" + string_s;
						out << "| " << setw(84) << right << final_result << " |" << endl;
					}
					else
					{
						final_result = "Total Listening Time: " + string_h + ":0" + string_m + ":" + string_s;
						out << "| " << setw(84) << right << final_result << " |" << endl;
					}
				}
				else
				{
					if (any_of(MorSvalue.begin(), MorSvalue.end(), [=](size_t seconds) { return total_seconds == seconds; }))
					{
						final_result = "Total Listening Time: " + string_h + ":" + string_m + ":0" + string_s;
						out << "| " << setw(84) << right << final_result << " |" << endl;
					}
					else
					{
						final_result = "Total Listening Time: " + string_h + ":" + string_m + ":" + string_s;
						out << "| " << setw(84) << right << final_result << " |" << endl;
					}
				}
			
			
			}	
	    
		
		
	}

	
}