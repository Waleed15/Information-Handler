#include"Data_Handler.h"
#include"Data_Management.h"

void Data_Handler::run()
{
	menu();

	int option = 5;

	do
	{
		cin >> option;
		switch (option)
		{
		case 0:
			return;
		case 1:
			manager.display_records();
			menu();
			break;
		case 2:
			manager.display_by_name(get_name());
			menu();
			break;
		case 3:
			manager.search_by_location(get_location());
			menu();
			break;
		case 4:
			manager.add_person(get_person());
			menu();
			break;
		case 5:
			manager.remove_record(get_name());
			menu();
			break;
		default:
			cout << "Enter a valid option number" << endl;
		}
	} while (option != 0);
}

string Data_Handler::get_location()
{
	string loc;
	cout << "Enter location you want to search: " << endl;
	cin.ignore();
	getline(cin, loc);
	return loc;
}

string Data_Handler::get_name()
{
	string name;
	cout << "Enter the name of the person:  ";
	cin.ignore();
	getline(cin, name);
	return name;
}

Person_Data Data_Handler::get_person()
{
	Person_Data person;
	string temp[5];
	cout << "\n------ Enter Person's Data -------" << endl;
	cout << "Name:  ";
	cin.ignore();
	getline(cin, temp[0]);
	cout << "Father Name:  ";
	getline(cin, temp[1]);
	cout << "City:  ";
	getline(cin, temp[2]);
	cout << "Profession:  ";
	getline(cin, temp[3]);
	cout << "ID:  ";
	getline(cin, temp[4]);
	person.set(temp[0], temp[1], temp[2], temp[3], temp[4]);
	return person;
}

void Data_Handler::menu()
{
	cout << "\n\n--------------- Welcome To Info Handler ----------------\n" << endl;
	cout << "1. Display list of Stored Records" << endl;
	cout << "2. Display full record of a person (Search)" << endl;
	cout << "3. Search persons using city" << endl;
	cout << "4. Add record" << endl;
	cout << "5. Remove a record by name" << endl;
	cout << "0. Exit" << endl;
	cout << "\nSelect an option:  ";
}