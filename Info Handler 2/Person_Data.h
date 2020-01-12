#ifndef PERSON_HANDLER_
#define PERSON_HANDLER_

#include<iostream>
#include<string>

using namespace std;

class Person_Data
{
private:
	
	string name;
	string fname;
	string address;
	string prof;
	string id;

public:

	Person_Data() :name(""), fname(""), address(""), prof(""), id(""){}
	
	Person_Data(string n, string f, string a, string p, string i) :name(n), fname(f), address(a), prof(p), id(i){}
	
	Person_Data(const Person_Data &obj) : name(obj.name), fname(obj.fname), address(obj.address), prof(obj.prof), id(obj.id){}
	
	void set(string n, string f, string a, string p, string i);
	
	string get_name();
	
	string get_fathername();
	
	string get_address();
	
	string get_professional();
	
	void console_display();
	
	string toString();
	
	bool isEmpty();
	
	friend ostream& operator<<(ostream& opr, Person_Data& data);
};

#endif PERSON_HANDLER_