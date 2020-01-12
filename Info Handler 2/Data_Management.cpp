#include"Data_Management.h"
#include"DoublyLinkedList.h"
#include"File_Handling.h"

void Data_Management::set(string m_file)
{
	main_file = m_file;
	string names = read(main_file);
	if (names != "")
	{
		istringstream stream(names);
		string temp, data;
		while (getline(stream, temp))
		{
			if (temp != "")
			{
				istringstream sub(read(temp));
				string curr[5];
				getline(sub, curr[0]);
				getline(sub, curr[1]);
				getline(sub, curr[2]);
				getline(sub, curr[3]);
				getline(sub, curr[4]);
				Person_Data person(curr[0], curr[1], curr[2], curr[3], curr[4]);
				person_list.insertAtEnd(person);
			}
		}
	}
	else
	{
		cout << "No record stored" << endl;
	}
}

void Data_Management::display_records()
{
	person_list.traverse();
}

string Data_Management::get_filename()
{
	return main_file;
}

void Data_Management::add_person(Person_Data& person)
{
	person_list.insertAtEnd(person);
	append(person.get_name(), main_file);
	write(person.toString(), person.get_name());
}

void Data_Management::search_by_location(string loc)
{
	DoublyLinkedList persons = person_list.search_by_location(loc);
	if (persons.isEmpty())
		cout << "No records found with location: " << loc << endl;
	else
	{
		int x;
		cout << "Enter number of the record you want to display" << endl;
		cin >> x;
		if (x > persons.size() || x < 1)
			cout << "Wrong index" << endl;
		else
		{
			Person_Data pd = persons.get_at(x);
			cout << pd << endl;
		}
	}
}

void Data_Management::remove_record(string name)
{
	if (person_list.delete_by_name(name))
	{
		delete_file(name);
		reappend(name, main_file);
	}
	else
	{
		cout << "Record doesn't exist" << endl;
	}
}

void Data_Management::display_by_name(string name)
{
	Person_Data person = person_list.search_by_name(name);
	if (person.isEmpty())
	{
		cout << "Record of person named " << name << " does not exist" << endl;
	}
	else
	{
		cout << person << endl;
	}
}