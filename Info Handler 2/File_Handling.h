#ifndef FILE_HANDLING_
#define FILE_HANDLING_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class File_Handling
{
public:
	File_Handling()
	{

	}

	string read(string filename);

	void write(string out, string filename);

	void append(string out, string filename);

	void reappend(string out, string filename);

	void delete_file(string filename);
};

#endif FILE_HANDLING_