#include "DoublyLinkedList.h"
#include "Person_Data.h"

void DoublyLinkedList::insertAtEnd(Person_Data val)
{
	Node* n = new Node();
	n->person = val;
	n->next = NULL;
	n->previous = tail;
	tail = n;
	if (head == NULL)
	{
		head = tail;
	}
	else
	{
		tail->previous->next = tail;
	}
}

void DoublyLinkedList::insertAtStart(Person_Data val)
{
	Node* n = new Node();
	n->person = val;
	n->previous = NULL;
	n->next = head;
	head = n;
	if (tail == NULL)
	{
		tail = head;
	}
	else
	{
		head->next->previous = head;
	}
}



void DoublyLinkedList::insertAt(int index, Person_Data val)
{
	if (index == 0)
	{
		insertAtStart(val);
	}
	else if (isEmpty())
	{
		cout << "Wrong index" << endl;
	}
	else
	{
		Node* temp = head;
		for (int x = 0; x < index - 1; x++)
		{
			if (temp->next == NULL)
			{
				cout << "Wrong index" << endl;
				return;
			}
			temp = temp->next;
		}
		if (temp->next == NULL)
		{
			insertAtEnd(val);
			return;
		}
		else
		{
			Node* n = new Node();
			n->person = val;
			n->next = temp->next;
			n->previous = temp;
			temp->next = n;
			n->next->previous = n;
		}
	}
}

void DoublyLinkedList::traverse()
{
	if (isEmpty())
	{
		cout << "Linked List is empty" << endl;
		return;
	}
	Node* temp = head;
	int x = 1;
	while (temp != NULL)
	{
		cout << "Value " << x++ << ": " << temp->person << endl;
		temp = temp->next;
	}
}

void DoublyLinkedList::reverse()
{
	if (isEmpty())
	{
		cout << "Linked List is empty" << endl;
		return;
	}
	Node* temp = tail;
	int x = 1;
	while (temp != NULL)
	{
		cout << "Value " << x++ << ": " << temp->person << endl;
		temp = temp->previous;
	}
}

void DoublyLinkedList::deleteAtStart()
{
	if (isEmpty())
	{
		cout << "Linked List is already empty" << endl;
		return;
	}
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	else
	{
		head = head->next;
		delete head->previous;
		head->previous = NULL;
	}
}

void DoublyLinkedList::deleteAtEnd()
{
	if (isEmpty())
	{
		cout << "Linked List is already empty" << endl;
		return;
	}
	if (tail->previous == NULL)
	{
		delete tail;
		head = NULL;
		tail = NULL;
		return;
	}
	else
	{
		tail = tail->previous;
		delete tail->next;
		tail->next = NULL;
	}
}

void DoublyLinkedList::deleteAt(int index)
{
	if (isEmpty() || index == 0)
	{
		deleteAtStart();
		return;
	}
	else
	{
		Node* temp = head;
		for (int x = 0; x < index; x++)
		{
			if (temp->next == NULL)
			{
				cout << "Wrong index" << endl;
				return;
			}
			temp = temp->next;
		}
		if (temp->next == NULL)
		{
			deleteAtEnd();
			return;
		}
		else
		{
			temp->previous->next = temp->next;
			temp->next->previous = temp->previous;
			delete temp;
		}
	}
}

bool DoublyLinkedList::delete_by_name(string n)
{
	if (isEmpty())
	{
		cout << "no records stored" << endl;
		return false;
	}
	else
	{
		if (head->person.get_name() == n)
		{
			deleteAtStart();
			return true;
		}
		Node* temp = head->next;
		int x = 1;
		while (temp != NULL)
		{
			if (temp->person.get_name() == n)
			{
				if (temp == tail)
				{
					deleteAtEnd();
					return true;
				}
				deleteAt(x);
				return true;
			}
			temp = temp->next;
			x++;
		}
		cout << "no such record exists" << endl;
		return false;
	}

}

Person_Data DoublyLinkedList::get_at(int index)
{
	Node* temp = head;
	int x = 1;
	while (temp != NULL)
	{
		if (x == index)
			return temp->person;
		temp = temp->next;
		x++;
	}
	return Person_Data();
}

Person_Data DoublyLinkedList::search_by_name(string name)
{
	if (isEmpty())
	{
		cout << "No record exists" << endl;
	}
	else
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->person.get_name() == name)
			{
				return temp->person;
			}
			temp = temp->next;
		}
		return Person_Data();
	}
}

DoublyLinkedList DoublyLinkedList::search_by_location(string loc)
{
	if (isEmpty())
	{
		cout << "no records stored" << endl;
		return DoublyLinkedList();
	}
	else
	{
		DoublyLinkedList ret;
		int x = 1;
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->person.get_address() == loc)
			{
				ret.insertAtEnd(temp->person);
				cout << x++ << ". " << temp->person.get_name() << endl;
			}
			temp = temp->next;
		}
		return ret;
	}
}

int DoublyLinkedList::size()
{
	int x = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		x++;
	}
	return x;
}

bool DoublyLinkedList::isEmpty()
{
	if (head == NULL)
		return true;
	return false;
}
