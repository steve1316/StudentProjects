#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

template <class itemType>
class LinkedList
{
private:
	Node <itemType> *headPtr; // Pointer to the first node
	Node <itemType> *tailPtr; // Pointer to the last node

public:

	// Constructor 
	LinkedList(const LinkedList& LL);
	LinkedList(Node<itemType>* newNode) : headPtr(newNode), tailPtr(newNode) {}

	// Destructor
	~LinkedList();

	// Accessors
	int getCurrentSize() const; // Gets the size of the linked list
	bool isEmpty() const; // Checks if the linked list is empty
	void addToHead(const itemType &newEntry); // Adds a new item to the front of list
	void addToTail(const itemType &newData); // Adds the item to the end of the list
	void AddAnywhere(const itemType &newData, int position);
	bool removeFirst(); // removes the item from the list
	bool removeLast(); // removes the last item from the list
	void RemoveAnywhere(int position);
	void clear(); // clears the list
	void print() const; // prints the item within the LinkedList
	void search(int x);
	int searchfordata(const itemType &searchdata);
};

template <class itemType>
LinkedList <itemType>::LinkedList(const LinkedList& LL) :
headPtr(NULL), tailPtr(NULL) // sets the head and tail to nothing because it's creating LL
{
	const Node<itemType>* curr = LL.headptr;
	if (!headPtr && curr) // While head doesn't exist
	{
		headPtr = new Node<itemType>(curr->data);
		tailPtr = headPtr;
		curr = curr->next;
	}
}

template <class itemType>
LinkedList<itemType>:: ~LinkedList()
{
	Node <itemType>* curr = headPtr;
	while (headPtr)
	{
		headPtr = headPtr->next;
		delete curr;
		curr = headPtr;
	}
}

template <class itemType>
int LinkedList <itemType>::getCurrentSize() const //Probably change but leave as of now.
{
	if (headPtr == NULL && tailPtr == NULL) { return 0; } // checks list to see if LL is empty and if it is returns 0

	Node<itemType>* temp = headPtr; // sets the temp to the head of the LL
	int count = 0;

	while (temp != nullptr)
	{
		count += 1;
		temp = temp->next; // sets the temp ptr to the next item in the LL
	}
	return count;
}

template <class itemType>
bool LinkedList <itemType>::isEmpty() const
{
	if (headPtr == NULL || tailPtr == NULL) { return true; }
	else { return false; }
}

template <class itemType>
void LinkedList<itemType>::addToHead(const itemType& newEntry)
{
	Node<itemType>* newNode = new Node<itemType>(newEntry);
	newNode->next = headPtr;
	headPtr = newNode;

	if (headPtr->next == NULL)
	{
		tailPtr = newNode;
	}
}

template <class itemType>
void LinkedList<itemType>::addToTail(const itemType& newEntry)
{
	Node<itemType>* newNode = new Node<itemType>(newEntry);
	if (tailPtr == NULL)
	{
		newNode->next = tailPtr;
		tailPtr = newNode;
		headPtr = newNode;
		return;
	}
	tailPtr->next = newNode;
	tailPtr = tailPtr->next;
}

template<class itemType>
void LinkedList<itemType>::AddAnywhere(const itemType & newData, int position)
{
	Node<itemType>* temp = new Node<itemType>(newData);
	temp->data = newData; //sets temp to equal to the data that you want to add into the list.
	temp->next = NULL;
	if (position == 1)
	{
		temp->next = headPtr; //simply add the data to the front of the list and move the 1st node forward.
		headPtr = temp;
		return;
	}
	Node<itemType>* temp2 = headPtr;
	for (int i = 0; i < position - 2; i++)
	{
		temp2 = temp2->next; //finds the specified position of the Node.
	}
	temp->next = temp2->next; //now it makes sure that the list will point correctly to the next node after it adds in the new node.
	temp2->next = temp; //adds in the new node.
}

template <class itemType>
bool LinkedList <itemType>::removeFirst()
{
	if (headPtr == nullptr && tailPtr == nullptr) { return false; } // checks to see if the LL is empty or not
	else {
		Node<itemType>* temp;
		temp = headPtr; // Sets temp to first item in the LL
		headPtr = headPtr->next; // Sets the head to the next item within the LL
		delete(temp); // Deletes the first item

		return true;
	}
}

template <class itemType>
bool LinkedList <itemType>::removeLast()
{
	if (headPtr == nullptr && tailPtr == nullptr) { return false; } // checks to see if the LL is empty or not

	else {
		Node<itemType> *curr, *temp;
		curr = headPtr; // sets the ptr to beg
		while (curr->next->next != NULL) { // traverse through the list until it hits the 2nd to last item in the LL
			curr = curr->next; // sets the 2nd to last item in the LL to the last item
		}
		temp = curr->next; // sets temp as the last item in the LL
		curr->next = NULL; // makes the 2nd to last item point to NULL
		delete(temp); //deletes the last item
		return true;
	}
}

template <class itemType>
void LinkedList<itemType>::RemoveAnywhere(int position)
{
	Node<itemType>* temp1 = headPtr;
	if (position == 1)
	{
		headPtr = temp1->next; //simply removes the first node and set headPtr to point to the next node.
		delete temp1;
		return;
	}
	for (int i = 0; i < position - 2; i++)
	{
		temp1 = temp1->next; //finds the specified position of the node you want to remove.
	}
	Node<itemType>* temp2 = temp1->next; //makes sure that the pointer won't point to NULL after deletion.
	temp1->next = temp2->next; //makes sure that the list will point to the correct node after deletion.
	delete temp2; //deletes the specified node.
}

template <class itemType>
void LinkedList <itemType>::clear()
{
	while (headPtr)
	{
		if (headPtr == NULL)
		{
			return;
		}
		else
		{
			Node<itemType>* temp = headPtr;
			if (headPtr == tailPtr)
			{
				headPtr = NULL;
				tailPtr = NULL;
			}
			else
			{
				headPtr = headPtr->next;
			}
			delete temp;
		}
	}
	/*Node<itemType>* temp = headPtr;
	while (temp != nullptr)
	{
		temp = temp->next;
		headPtr = temp;
		delete(temp);
	}*/
}

template <class itemType>
void LinkedList<itemType>::print() const
{
	int intOption;
	double doubleOption;
	char charOption;
	std::string stringOption;
	bool done = true;
	Node<itemType>* curr = headPtr;
	while (done)
	{
		if (curr)
		{
			if (typeid(curr->data) == typeid(intOption))
			{
				std::cout << curr->data << "--->";
				curr = curr->next;
			}
			else if (typeid(curr->data) == typeid(doubleOption))
			{
				std::cout << curr->data << "--->";
				curr = curr->next;
			}
			else if (typeid(curr->data) == typeid(charOption))
			{
				std::cout << curr->data << "--->";
				curr = curr->next;
			}
			else if (typeid(curr->data) == typeid(stringOption))
			{
				std::cout << curr->data << "--->";
				curr = curr->next;
			}
		}
		else
		{
			done = false;
		}
	}
	std::cout << "Null" << std::endl;
}
	//while (curr)
	//{
	//	std::cout << curr->data << "--->";
	//	curr = curr->next;
	//}
	//std::cout << "Null" << std::endl;

template <class itemType>
void LinkedList<itemType>::search(int x)
{
	if (x == 0)
	{
		int choice;
		int intOption;
		double doubleOption;
		char charOption;
		itemType searchdata;
		int counter = 1;
		Node <itemType>* temp = headPtr;
		std::cout << "\nWhat are you looking for?" << "\nSearch for: ";
		std::cin >> searchdata;
		if (typeid(searchdata) == typeid(intOption))
		{
			while (temp != NULL) //searches through each node till the end of the list.
			{
				std::cout << "\nSearching position " << counter << "...";
				if (temp->data == searchdata)
				{
					std::cout << "\nWe found your specified INT at position " << counter << " of the list.";
					return;
				}
				else
				{
					temp = temp->next; //if not, try again on the next node.
					counter++;
				}
			}
			std::cout << "\nWe didn't find your specified INT.";
			return;
		}
		if (typeid(searchdata) == typeid(doubleOption))
		{
			while (temp != NULL) //searches through each node till the end of the list.
			{
				std::cout << "\nSearching position " << counter << "...";
				if (temp->data == searchdata)
				{
					std::cout << "\nWe found your specified DOUBLE at position " << counter << " of the list.";
					return;
				}
				else
				{
					temp = temp->next; //if not, try again on the next node.
					counter++;
				}
			}
			std::cout << "\nWe didn't find your specified DOUBLE.";
			return;
		}
		if (typeid(searchdata) == typeid(charOption))
		{
			while (temp != NULL) //searches through each node till the end of the list.
			{
				std::cout << "\nSearching position " << counter << "...";
				if (temp->data == searchdata)
				{
					std::cout << "\nWe found your specified CHAR at position " << counter << " of the list.";
					return;
				}
				else
				{
					temp = temp->next; //if not, try again on the next node.
					counter++;
				}
			}
			std::cout << "\nWe didn't find your specified CHAR.";
			return;
		}
		else
		{
			std::cout << "\nInvalid choice entered. Returning to menu...\n";
			return;
		}
	}
	else if (x == 1)
	{
		int choice;
		std::string stringOption;
		std::string searchstring;
		int counter = 1;
		Node <itemType>* temp = headPtr;
		std::cout << "\nWhat string are you looking for?" << "\nSearch for: ";
		std::cin.ignore();
		getline(std::cin, searchstring);
			while (temp != NULL) //searches through each node till the end of the list.
			{
				std::cout << "\nSearching position " << counter << "...";
				if (typeid(temp->data) == typeid(searchstring))
				{
					stringOption = temp->data;
					if (stringOption == searchstring)
					{
						std::cout << "\nWe found your specified STRING at position " << counter << " of the list.";
						return;
					}
					else
					{
						temp = temp->next; //if not, try again on the next node.
						counter++;
					}
				}
				else
				{
					temp = temp->next;
					counter++;
				}
			}
			std::cout << "\nWe didn't find your specified STRING.";
			return;
		}
		else
		{
			std::cout << "\nInvalid choice entered. Returning to menu...\n";
			return;
		}
}


template <class itemType>
int LinkedList<itemType>::searchfordata(const itemType &searchdata)
{
	Node <itemType>* temp = headPtr;
	int counter = 1;
	while (temp != NULL) //searches through each node till the end of the list.
	{
		if (temp->data == searchdata)
		{
			return counter;
		}
		else
		{
			temp = temp->next; //if not, try again on the next node.
			counter++;
		}
	}
	return NULL;
}

#endif
