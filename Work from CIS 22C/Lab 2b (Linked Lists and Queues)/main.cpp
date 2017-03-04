//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//	Names: Steve Tu                                                                     //
//  Partner: Peter Shin                                                                 //
//	Date: 02/13/17                                                                      //
//	Class: CIS 22C                                                                      //
//	Teacher: Manish Goel                                                                //
//	Partner Evaluation:                                                                 //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Queue.h"
#include "Node.h"
#include "LinkedList.h"

//prototyping
int main_menu();
int queue_menu();
int typedata_menu();
int linked_menu();

int main_menu()
{
	int main;
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tMain Menu\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\nWelcome! What would you like to do?" << std::endl;
	std::cout << "1. Queue\n2. Linked List\n3. Exit\n>>> ";
	std::cin >> main;
	return main;
}

int queue_menu()
{
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tQueue Operations\n";
	std::cout << "\n-----------------------------------------------------\n";
	int queue;
	std::cout << "1. Enqueue a piece of data to queue" << std::endl;
	std::cout << "2. Dequeue a piece of data out of queue" << std::endl;
	std::cout << "3. View front of queue" << std::endl;
	std::cout << "4. View rear of queue" << std::endl;
	std::cout << "5. Clear out the queue" << std::endl;
	std::cout << "6. Return to Main Menu" << std::endl;
	std::cout << ">>> ";
	std::cin >> queue;
	return queue;
}

int typedata_menu()
{
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tType of Data\n";
	std::cout << "\n-----------------------------------------------------\n";
	int typedata_menu;
	std::cout << "What data type do you want to work with?" << std::endl;
	std::cout << "1. Int\n2. Double\n3. Char\n4. String\n5. Return to previous menu\n>>> ";
	std::cin >> typedata_menu;
	return typedata_menu;
}

int linked_menu()
{
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tLinked List Operations\n";
	std::cout << "\n-----------------------------------------------------\n";
	int linked_menu;
	std::cout << "1. Add to the head" << std::endl;
	std::cout << "2. Add to the tail" << std::endl;
	std::cout << "3. Add anywhere in the linked list" << std::endl;
	std::cout << "4. Remove the first item" << std::endl;
	std::cout << "5. Remove the last item" << std::endl;
	std::cout << "6. Remove specific item in the linked list" << std::endl;
	std::cout << "7. Print the linked list" << std::endl;
	std::cout << "8. Clear the linked list" << std::endl;
	std::cout << "9. Search through the list" << std::endl;
	std::cout << "10. Return to previous menu" << std::endl;
	std::cout << ">>> ";
	std::cin >> linked_menu;

	return linked_menu;
}

int main()
{
	LinkedList<int> listInt(new Node<int>());
	LinkedList<double> listDouble(new Node<double>());
	LinkedList<char> listChar(new Node<char>());
	LinkedList<std::string> listString(new Node<std::string>());
	Queue<int> QueueInt(new Node<int>());
	Queue<double> QueueDouble(new Node<double>());
	Queue<char> QueueChar(new Node<char>());
	Queue<std::string> QueueString(new Node<std::string>());
	int main_menu_choice = 0;
	int queue_menu_choice = 0;
	int linked_menu_choice = 0;
	int typedata_menu_choice = 0;
	int intdata, position;
	double doubledata;
	char chardata;
	std::string stringdata;

	// The following will clear out the null terminations when initializing the Queues and Lists.
	QueueInt.clear();
	QueueDouble.clear();
	QueueChar.clear();
	QueueString.clear();
	listInt.clear();
	listDouble.clear();
	listChar.clear();
	listString.clear();

	do
	{
		main_menu_choice = main_menu();
		if (main_menu_choice == 1) //This is for Queue Operations Menu
		{
			do 
			{
				queue_menu_choice = queue_menu();
				if (queue_menu_choice == 1) //Enqueue operation
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tEnqueue a INT into the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueInt.print();
						std::cout << "\nWhat INT value would you like to enqueue into the Queue?\n>>> ";
						std::cin >> intdata;
						QueueInt.enqueue(intdata);
						std::cout << "\nNew Queue: ";
						QueueInt.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tEnqueue a DOUBLE into the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueDouble.print();
						std::cout << "\nWhat DOUBLE value would you like to enqueue into the Queue?\n>>> ";
						std::cin >> doubledata;
						QueueDouble.enqueue(doubledata);
						std::cout << "\nNew Queue: ";
						QueueDouble.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tEnqueue a CHAR into the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueChar.print();
						std::cout << "\nWhat CHAR value would you like to enqueue into the Queue?\n>>> ";
						std::cin >> chardata;
						QueueChar.enqueue(chardata);
						std::cout << "\nNew Queue: ";
						QueueChar.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tEnqueue a STRING into the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueString.print();
						std::cout << "\nWhat STRING value would you like to enqueue into the Queue?\n>>> ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						QueueString.enqueue(stringdata);
						std::cout << "\nNew Queue: ";
						QueueString.print();
						queue_menu_choice = 0;
					}
					else
					{
						queue_menu_choice = 0;
					}
				}
				if (queue_menu_choice == 2) //Dequeue operation
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tDequeue a INT from the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueInt.print();
						std::cout << "\nDequeuing...";
						QueueInt.dequeue();
						std::cout << "\nNew Queue: ";
						QueueInt.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tDequeue a DOUBLE from the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueDouble.print();
						std::cout << "\nDequeuing...";
						QueueDouble.dequeue();
						std::cout << "\nNew Queue: ";
						QueueDouble.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tDequeue a CHAR from the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueChar.print();
						std::cout << "\nDequeuing...";
						QueueChar.dequeue();
						std::cout << "\nNew Queue: ";
						QueueChar.print();
						queue_menu_choice = 0;
					}
					else if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tDequeue a STRING from the Queue";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Queue: ";
						QueueString.print();
						std::cout << "\nDequeuing...";
						QueueString.dequeue();
						std::cout << "\nNew Queue: ";
						QueueString.print();
						queue_menu_choice = 0;
					}
					else
					{
						queue_menu_choice = 0;
					}
				}
				if (queue_menu_choice == 3) //view the front of Queue
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tThe Contents in Front of Queue";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Int Queue: ";
					QueueInt.front();
					std::cout << "\nDouble Queue: ";
					QueueDouble.front();
					std::cout << "\nChar Queue: ";
					QueueChar.front();
					std::cout << "\nString Queue: ";
					QueueString.front();
					queue_menu_choice = 0;
				}
				if (queue_menu_choice == 4) //view rear of Queue
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tThe Contents in Rear of Queue";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Int Queue: ";
					QueueInt.rear();
					std::cout << "\nDouble Queue: ";
					QueueDouble.rear();
					std::cout << "\nChar Queue: ";
					QueueChar.rear();
					std::cout << "\nString Queue: ";
					QueueString.rear();
					queue_menu_choice = 0;
				}
				if (queue_menu_choice == 5) //clears the Queue
				{
					int choice = 0;
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tClearing the Queue";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Which Queue do you want to clear?";
					std::cout << "\n1. Int: ";
					QueueInt.print();
					std::cout << "\n2. Double: ";
					QueueDouble.print();
					std::cout << "\n3. Char: ";
					QueueChar.print();
					std::cout << "\n4. String: ";
					QueueString.print();
					std::cout << "\nMy choice: ";
					std::cin >> choice;
					if (choice == 1) //clears the int queue
					{
						std::cout << "\nClearing int Queue now...";
						QueueInt.clear();
						std::cout << "\n... Done!";
						queue_menu_choice = 0;
					}
					else if (choice == 2) //clears the double queue
					{
						std::cout << "\nClearing double Queue now...";
						QueueDouble.clear();
						std::cout << "\n... Done!";
						queue_menu_choice = 0;
					}
					else if (choice == 3) //clears the char queue
					{
						std::cout << "\nClearing char Queue now...";
						QueueChar.clear();
						std::cout << "\n... Done!";
						queue_menu_choice = 0;
					}
					else if (choice == 4) //clears the string queue
					{
						std::cout << "\nClearing string Queue now...";
						QueueString.clear();
						std::cout << "\n... Done!";
						queue_menu_choice = 0;
					}
					else
					{
						std::cout << "Invalid Input. Returning to Operations Menu...";
					}
				}
			} while (queue_menu_choice != 6);
		}
		else if (main_menu_choice == 2) //Linked List Operations.
		{
			do
			{
				linked_menu_choice = linked_menu();
				if (linked_menu_choice == 1) //add to head
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding INT to head of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listInt.print();
						std::cout << "\nWhat INT value would you like to add to head of list: ";
						std::cin >> intdata;
						listInt.addToHead(intdata);
						std::cout << "\nNew List: ";
						listInt.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding DOUBLE to head of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listDouble.print();
						std::cout << "\nWhat DOUBLE value would you like to add to head of list: ";
						std::cin >> doubledata;
						listDouble.addToHead(doubledata);
						std::cout << "\nNew List: ";
						listDouble.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding CHAR to head of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listChar.print();
						std::cout << "\nWhat CHAR value would you like to add to head of list: ";
						std::cin >> chardata;
						listChar.addToHead(chardata);
						std::cout << "\nNew List: ";
						listChar.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding STRING to head of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listString.print();
						std::cout << "\nWhat STRING value would you like to add to head of list: ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						listString.addToHead(stringdata);
						std::cout << "\nNew List: ";
						listString.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 2) //add to tail
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding INT to tail of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listInt.print();
						std::cout << "\nWhat INT value would you like to add to tail of list: ";
						std::cin >> intdata;
						listInt.addToTail(intdata);
						std::cout << "\nNew List: ";
						listInt.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding DOUBLE to tail of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listDouble.print();
						std::cout << "\nWhat DOUBLE value would you like to add to tail of list: ";
						std::cin >> doubledata;
						listDouble.addToTail(doubledata);
						std::cout << "\nNew List: ";
						listDouble.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding CHAR to tail of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listChar.print();
						std::cout << "\nWhat CHAR value would you like to add to tail of list: ";
						std::cin >> chardata;
						listChar.addToTail(chardata);
						std::cout << "\nNew List: ";
						listChar.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding STRING to tail of List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listString.print();
						std::cout << "\nWhat STRING value would you like to add to tail of list: ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						listString.addToTail(stringdata);
						std::cout << "\nNew List: ";
						listString.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 3) //add anywhere to list
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding INT to anywhere in List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listInt.print();
						std::cout << "\nWhat INT value would you like to add to list: ";
						std::cin >> intdata;
						std::cout << "\nat position: ";
						std::cin >> position;
						listInt.AddAnywhere(intdata, position);
						std::cout << "\nNew List: ";
						listInt.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding DOUBLE to anywhere in List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listDouble.print();
						std::cout << "\nWhat DOUBLE value would you like to add to list: ";
						std::cin >> doubledata;
						std::cout << "\nat position: ";
						std::cin >> position;
						listDouble.AddAnywhere(doubledata, position);
						std::cout << "\nNew List: ";
						listDouble.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding CHAR to anywhere in List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listChar.print();
						std::cout << "\nWhat CHAR value would you like to add to list: ";
						std::cin >> chardata;
						std::cout << "\nat position: ";
						std::cin >> position;
						listChar.AddAnywhere(chardata, position);
						std::cout << "\nNew List: ";
						listChar.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tAdding STRING to anywhere in List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listString.print();
						std::cout << "\nWhat STRING value would you like to add to list: ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						std::cout << "\nat position: ";
						std::cin >> position;
						listString.AddAnywhere(stringdata, position);
						std::cout << "\nNew List: ";
						listString.print();
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 4) //remove the first item
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tRemoving item from head of List";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Original List: ";
					listInt.print();
					listInt.removeLast();
					std::cout << "\nThe first item at head of list has been removed.\n" << std::endl;
					std::cout << "\nNew List: ";
					listInt.print();
					linked_menu_choice = 0;
				}
				else if (linked_menu_choice == 5) //remove the last item
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tRemoving item from tail of List";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Original List: ";
					listInt.print();
					listInt.removeLast();
					std::cout << "\nThe last item at tail of list has been removed.\n" << std::endl;
					std::cout << "\nNew List: ";
					listInt.print();
					linked_menu_choice = 0;
				}
				else if (linked_menu_choice == 6) //Remove specific item in list
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tRemoving a specific INT from List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listInt.print();
						std::cout << "\nWhich INT would you like to remove: ";
						std::cin >> intdata;
						position = listInt.searchfordata(intdata);
						if (position != 0)
						{
							listInt.RemoveAnywhere(position);
							std::cout << "\n" << intdata << " has been removed from position " << position << ".";
							std::cout << "\nNew List: ";
							listInt.print();
							linked_menu_choice = 0;
						}
						else if (position == 0)
						{
							std::cout << "\n...We did not find " << intdata << " anywhere in the list.";
							linked_menu_choice = 0;
						}
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tRemoving a specific DOUBLE from List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listDouble.print();
						std::cout << "\nWhich DOUBLE would you like to remove: ";
						std::cin >> doubledata;
						position = listDouble.searchfordata(doubledata);
						if (position != 0)
						{
							listDouble.RemoveAnywhere(position);
							std::cout << "\n" << doubledata << " has been removed from position " << position << ".";
							std::cout << "\nNew List: ";
							listDouble.print();
							linked_menu_choice = 0;
						}
						else if (position == 0)
						{
							std::cout << "\n...We did not find " << doubledata << " anywhere in the list.";
							linked_menu_choice = 0;
						}
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tRemoving a specific CHAR from List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listChar.print();
						std::cout << "\nWhich CHAR would you like to remove: ";
						std::cin >> chardata;
						position = listChar.searchfordata(chardata);
						if (position != 0)
						{
							listChar.RemoveAnywhere(position);
							std::cout << "\n" << chardata << " has been removed from position " << position << ".";
							std::cout << "\nNew List: ";
							listChar.print();
							linked_menu_choice = 0;
						}
						else if (position == 0)
						{
							std::cout << "\n...We did not find " << chardata << " anywhere in the list.";
							linked_menu_choice = 0;
						}
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tRemoving a specific STRING from List";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original List: ";
						listString.print();
						std::cout << "\nWhich STRING would you like to remove: ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						position = listString.searchfordata(stringdata);
						if (position != 0)
						{
							listString.RemoveAnywhere(position);
							std::cout << "\n" << stringdata << " has been removed from position " << position << ".";
							std::cout << "\nNew List: ";
							listString.print();
							linked_menu_choice = 0;
						}
						else if (position == 0)
						{
							std::cout << "\n...We did not find " << stringdata << " anywhere in the list.";
							linked_menu_choice = 0;
						}
					}
					if (typedata_menu_choice == 5) //go back
					{
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 7) //prints out the list
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tThe Contents of Linked List";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Int List: ";
					listInt.print();
					std::cout << "\nDOUBLE List: ";
					listDouble.print();
					std::cout << "\nChar List: ";
					listChar.print();
					std::cout << "\nString List: ";
					listString.print();
					linked_menu_choice = 0;
				}
				else if (linked_menu_choice == 8) //clears out the list
				{
					int choice = 0;
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tClearing the Linked List";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Which Linked List do you want to clear?";
					std::cout << "\n1. ";
					listInt.print();
					std::cout << "\n2. ";
					listDouble.print();
					std::cout << "\n3. ";
					listChar.print();
					std::cout << "\n4. ";
					listString.print();
					std::cout << "\nMy choice: ";
					std::cin >> choice;
					if (choice == 1)
					{
						std::cout << "\nClearing INT List now...";
						listInt.clear();
						std::cout << "\n... Done!";
						linked_menu_choice = 0;
					}
					else if (choice == 2)
					{
						std::cout << "\nClearing DOUBLE List now...";
						listDouble.clear();
						std::cout << "\n... Done!";
						linked_menu_choice = 0;
					}
					else if (choice == 3)
					{
						std::cout << "\nClearing CHAR List now...";
						listChar.clear();
						std::cout << "\n... Done!";
						linked_menu_choice = 0;
					}
					else if (choice == 4)
					{
						std::cout << "\nClearing STRING List now...";
						listString.clear();
						std::cout << "\n... Done!";
						linked_menu_choice = 0;
					}
					else
					{
						std::cout << "\nInvalid Input. Going back...";
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 9) //searches for a specific data in list
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tSearching for a INT in the Linked List";
						std::cout << "\n-----------------------------------------------------\n";
						listInt.search(0);
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tSearching for a DOUBLE in the Linked List";
						std::cout << "\n-----------------------------------------------------\n";
						listDouble.search(0);
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tSearching for a CHAR in the Linked List";
						std::cout << "\n-----------------------------------------------------\n";
						listChar.search(0);
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tSearching for a STRING in the Linked List";
						std::cout << "\n-----------------------------------------------------\n";
						listString.search(1);
						linked_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						linked_menu_choice = 0;
					}
				}
				else if (linked_menu_choice == 10) //go back to selecting either Linked List, Stack or Exit out the program.
				{
					main_menu_choice = 0;
					linked_menu_choice == 0;
				}
			} while (linked_menu_choice != 10);
		}
		else if (main_menu_choice == 3) //Exits out the program.
		{
			std::cout << "\nGoodbye.\n";
			system("PAUSE");
			return 0;
		}
	} while (main_menu_choice != 3);
	std::cout << "\nGoodbye.\n";
	system("PAUSE");
	return 0;
}
