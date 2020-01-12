#ifndef DATA_MANAGEMENT_
#define DATA_MANAGEMENT_

#include<sstream>
#include"File_Handling.h"
#include"DoublyLinkedList.h"

using namespace std;

class Data_Management: public File_Handling
{
private:
	DoublyLinkedList person_list;
	string main_file;

public:
	Data_Management() : main_file("")
	{}

	Data_Management(string m_file)
	{
		set(m_file);
	}

	void set(string);
	
	void display_records();
	
	string get_filename();
	
	void add_person(Person_Data&);
	
	void search_by_location(string);
	
	void remove_record(string);
	
	void display_by_name(string);
};

#endif DATA_MANAGEMENT_