// Workshop 9 - Multi-Threading
// SecureData.cpp
/*
date: 2021-11-24
Name: Chun Kit Jacky Siu
ID: 134663186
email: jsiu5@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <thread>
#include <memory>
#include <functional>
#include "SecureData.h"

using namespace std;


namespace w9 {

	SecureData::SecureData() {
		setEmpty();
	}

	void SecureData::setEmpty() {
		this->text = nullptr;
		this->ofs = nullptr;
		this->nbytes = 0;
		this->encoded = false;
	}
	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		setEmpty();
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {

		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		std::string ctext = text, str1, str2;
		for (int i = 0; i < nbytes; ++i)
		{
			if(i < nbytes/2)
			str1 += ctext[i];
			if(i >= nbytes /2)
			str2 += ctext[i];
		}

		char* temp1 = new char[nbytes / 2 + 1];
		char* temp2 = new char[nbytes - (nbytes / 2) + 1];

		strcpy(temp1, str1.c_str());
		strcpy(temp2, str2.c_str());

		auto f1 = std::bind(converter, std::placeholders::_1 , key, std::placeholders::_2, Cryptor());
		
		thread t1 = thread([&]() {f1(temp1, (nbytes / 2)); });
		thread t2 = thread([&]() {f1(temp2, (nbytes - (nbytes / 2))); });
		t1.join();
		t2.join();
		temp1[nbytes / 2] = '\0';
		temp2[nbytes - nbytes / 2] = '\0';
		str1 = temp1;
		str2 = temp2;
		str1 += str2;
		delete[] temp1;
		delete[] temp2;
		delete[] this->text;
		this->text = nullptr;
		this->text = new char[nbytes + 1];
		strcpy(this->text, str1.c_str());
		this->text[nbytes] = '\0';
		
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			std::ofstream f(file, std::ios::out | std::ios::binary);
			if (!f)
				throw string("\n***Failed to open file ") +
				string(file) + string(" ***\n");
			// TODO: write data into the binary file
			//         and close the file
			
			f.write(text, nbytes);
			f.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		std::ifstream f(file, std::ios::in|std::ios::binary);
		if (!f)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");
		// TODO: - allocate memory here for the file content
		f.clear();
		f.seekg(0, std::ios::end);
		nbytes = (int)f.tellg();
		delete[] this->text;
		this->text = nullptr;
		this->text = new char[nbytes + 1];


		// TODO: - read the content of the binary file
		f.seekg(0, std::ios::beg);
		f.read(text, nbytes);
		text[nbytes] = '\0';
		f.close();
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
