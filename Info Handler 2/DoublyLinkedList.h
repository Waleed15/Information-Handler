#ifndef DOUBLY_LINKEDLIST_
#define DOUBLY_LINKEDLIST_

#include"Person_Data.h"
using namespace std;

struct Node
{
	Person_Data person;
	Node* next;
	Node* previous;
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;

public:
	DoublyLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void insertAtEnd(Person_Data);
	
    DoublyLinkedList(const DoublyLinkedList& dObj)
	{
		head = NULL;
		tail = NULL;
		Node* temp = dObj.head;
		while (temp != NULL)
		{
			insertAtEnd(temp->person);
			temp = temp->next;
		}
	}

	void insertAtStart(Person_Data);

	void insertAt(int, Person_Data);
	
	void traverse();
	
	void reverse();
	
	void deleteAtStart();
	
	void deleteAtEnd();

	void deleteAt(int);
	
	bool delete_by_name(string n);
	
	Person_Data get_at(int);
	
	Person_Data search_by_name(string);
	
	DoublyLinkedList search_by_location(string);
	
	int size();
	
	bool isEmpty();
	
	~DoublyLinkedList()
	{
		while (!isEmpty())
		{
			deleteAtEnd();
		}
	}
};

#endif DOUBLY_LINKEDLIST_