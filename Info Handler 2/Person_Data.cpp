#include<iostream>
#include"Person_Data.h"

void Person_Data::set(string n, string f, string a, string p, string i)
{
	name = n;
	fname = f;
	address = a;
	prof = p;
	id = i;
}

string Person_Data::get_name()
{
	return name;
}

string Person_Data::get_fathername()
{
	return fname;
}

string Person_Data::get_address()
{
	return address;
}

string Person_Data::get_professional()
{
	return prof;
}

void Person_Data::console_display()
{
	cout << "\n----------------- Person's Data --------------------" << endl;
	cout << "\tName:  " << name << endl;
	cout << "\tFather's Name:  " << fname << endl;
	cout << "\tCity:  " << address << endl;
	cout << "\tProfession: " << prof << endl;
	cout << "\tId:  " << id << endl;
	cout << "------------------------------------------------------" << endl;
}

string Person_Data::toString()
{
	string ret;
	ret = name + "\n" + fname + "\n" + address + "\n" + prof + "\n" + id;
	return ret;
}

bool Person_Data::isEmpty()
{
	if (name == "" && fname == "" && address == "" && prof == "" && id == "")
		return true;
	return false;
}

ostream& operator<<(ostream& opr, Person_Data& data)
{
	data.console_display();
	return opr;
}
