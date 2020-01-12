#include "File_Handling.h"

string File_Handling::read(string filename)
{
	string read = "";
	string temp = "";
	ifstream inFile(filename);			//Opens the file
	if (inFile.fail())
	{
		cout << "Failed to open file: " << filename << endl;
		return "";
	}
	while (!inFile.eof())
	{
		getline(inFile, temp);
		read += temp;					//cancatenates the whole text
		read += "\n";					//cancatenates the end of line
	}
	inFile.close();						//closes the file
	return read;
}

void File_Handling::write(string out, string filename)
{
	ofstream ofFile(filename);
	ofFile << out;					//writes the string to the file
	ofFile.close();
}

void File_Handling::append(string out, string filename)
{
	ofstream ofFile(filename, ios_base::app);
	ofFile << out << endl;
	ofFile.close();
}

void File_Handling::reappend(string out, string filename)
{
	string str_write = read(filename);
	size_t nFPos = str_write.find(out);
	size_t secondNL = str_write.find('\n', nFPos);
	size_t firstNL = str_write.rfind('\n', nFPos);

	str_write.erase(firstNL, secondNL - firstNL);
	write(str_write, filename);
}

void File_Handling::delete_file(string filename)
{
	if (!remove(filename.c_str()))
		cout << "File Successfully deleted";
	else
		cout << "Error in file deletion" << endl;
}
