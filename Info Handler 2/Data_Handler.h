#ifndef DATA_HANDLER_
#define DATA_HANDLER_

#include"Data_Management.h"

class Data_Handler
{
private:
	Data_Management manager;

public:
	Data_Handler()
	{}

	Data_Handler(string m_file) :manager(m_file)
	{}

	void run();

	string get_location();

	string get_name();

	Person_Data get_person();

	void menu();
};

#endif DATA_HANDLER_