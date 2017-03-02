//////////////////////////////////////////////////////////////////////////////////////////
//                                                                                      //
//	Names: Steve Tu and Peter Shin                                                      //
//	Date: 02/11/17                                                                      //
//	Class: CIS 22C                                                                      //
//	Teacher: Manish Goel                                                                //
//  Partner Evaluation of Peter Shin = 3                                                //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Stack.h"
#include "LinkedList.h"
#include "Node.h"

//prototyping
int main_menu();
int linked_menu();
int stack_menu();
int typedata_menu();

int main_menu()
{
	int main;

	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tMain Menu\n";
	std::cout << "\n-----------------------------------------------------\n";

	std::cout << "\nWelcome! Which will you be working with?" << std::endl;
	std::cout << "1. Linked List\n2. Stack\n3. Exit\n>>>";
	std::cin >> main;

	return main;
}

int linked_menu()
{
	int linked;

	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tLinked List Operations\n";
	std::cout << "\n-----------------------------------------------------\n";

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
	std::cin >> linked;

	return linked;
}

int stack_menu()
{
	int stack;

	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tStack Operations\n";
	std::cout << "\n-----------------------------------------------------\n";

	std::cout << "1. Push data into Stack" << std::endl;
	std::cout << "2. Pop data out of Stack" << std::endl;
	std::cout << "3. Clear the Stack" << std::endl;
	std::cout << "4. View the data of Stack" << std::endl;
	std::cout << "5. Return to previous menu" << std::endl;
	std::cout << ">>> ";
	std::cin >> stack;

	return stack;
}

int typedata_menu()
{
	int typedata;

	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "\t\tType of Data\n";
	std::cout << "\n-----------------------------------------------------\n";

	std::cout << "1. INT" << std::endl;
	std::cout << "2. DOUBLE" << std::endl;
	std::cout << "3. CHAR" << std::endl;
	std::cout << "4. STRING" << std::endl;
	std::cout << "5. Return to previous menu" << std::endl;
	std::cout << ">>> ";
	std::cin >> typedata;

	return typedata;
}

int main()
{
	int main_menu_choice = 0;
	int linked_menu_choice = 0;
	int stack_menu_choice = 0;
	int typedata_menu_choice = 0;
	int intdata, position;
	double doubledata;
	char chardata;
	std::string stringdata;

	LinkedList<int> listInt(new Node<int>());
	LinkedList<double> listDouble(new Node<double>());
	LinkedList<char> listChar(new Node<char>());
	LinkedList<std::string> listString(new Node<std::string>());

	Stack<int> stackInt(new Node<int>());
	Stack<double> stackDouble(new Node<double>());
	Stack<char> stackChar(new Node<char>());
	Stack<std::string> stackString(new Node<std::string>());

	do
	{
		main_menu_choice = main_menu();
		if (main_menu_choice == 1) //This is for the Linked List menu.
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
		else if (main_menu_choice == 2) //This is for the Stack menu.
		{
			do 
			{
				stack_menu_choice = stack_menu();
				if (stack_menu_choice == 1) //push data to top of stack
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPushing INT to top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackInt.print();
						std::cout << "\nWhat INT value would you like to push to top of Stack: ";
						std::cin >> intdata;
						stackInt.push(intdata);
						std::cout << "\nNew Stack: ";
						stackInt.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPushing DOUBLE to top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackDouble.print();
						std::cout << "\nWhat DOUBLE value would you like to push to top of Stack: ";
						std::cin >> doubledata;
						stackDouble.push(doubledata);
						std::cout << "\nNew Stack: ";
						stackDouble.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPushing CHAR to top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackChar.print();
						std::cout << "\nWhat CHAR value would you like to push to top of Stack: ";
						std::cin >> chardata;
						stackChar.push(chardata);
						std::cout << "\nNew Stack: ";
						stackChar.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPushing STRING to top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackString.print();
						std::cout << "\nWhat STRING value would you like to push to top of Stack: ";
						std::cin.ignore();
						getline(std::cin, stringdata);
						stackString.push(stringdata);
						std::cout << "\nNew Stack: ";
						stackString.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						stack_menu_choice = 0;
					}
				}
				else if (stack_menu_choice == 2) //pops out the data from top of the stack.
				{
					typedata_menu_choice = typedata_menu();
					if (typedata_menu_choice == 1) //int
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPopping INT off top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackInt.print();
						stackInt.pop();
						std::cout << "\nNew Stack: ";
						stackInt.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 2) //double
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPopping DOUBLE off top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackDouble.print();
						stackDouble.pop();
						std::cout << "\nNew Stack: ";
						stackDouble.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 3) //char
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPopping CHAR off top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackChar.print();
						stackChar.pop();
						std::cout << "\nNew Stack: ";
						stackChar.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 4) //string
					{
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "\t\tPopping STRING off top of Stack";
						std::cout << "\n-----------------------------------------------------\n";
						std::cout << "Original Stack: ";
						stackString.print();
						stackString.pop();
						std::cout << "\nNew Stack: ";
						stackString.print();
						stack_menu_choice = 0;
					}
					if (typedata_menu_choice == 5) //go back
					{
						stack_menu_choice = 0;
					}
				}
				else if (stack_menu_choice == 3) //Clears the Stack
				{
					int choice = 0;
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tClearing the Stack";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "Which Stack do you want to clear?";
					std::cout << "\n1. ";
					stackInt.print();
					std::cout << "\n2. ";
					stackDouble.print();
					std::cout << "\n3. ";
					stackChar.print();
					std::cout << "\n4. ";
					stackString.print();
					std::cout << "\nMy choice: ";
					std::cin >> choice;
					if (choice == 1)
					{
						std::cout << "\nClearing INT Stack now...";
						stackInt.clear();
						std::cout << "\n... Done!";
						stack_menu_choice = 0;
					}
					else if (choice == 2)
					{
						std::cout << "\nClearing DOUBLE Stack now...";
						stackDouble.clear();
						std::cout << "\n... Done!";
						stack_menu_choice = 0;
					}
					else if (choice == 3)
					{
						std::cout << "\nClearing CHAR Stack now...";
						stackChar.clear();
						std::cout << "\n... Done!";
						stack_menu_choice = 0;
					}
					else if (choice == 4)
					{
						std::cout << "\nClearing STRING Stack now...";
						stackString.clear();
						std::cout << "\n... Done!";
						stack_menu_choice = 0;
					}
					else
					{
						std::cout << "\nInvalid Input. Going back...";
						linked_menu_choice = 0;
					}
				}
				else if (stack_menu_choice == 4) //view contents of Stack
				{
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "\t\tViewing the Contents of Stack";
					std::cout << "\n-----------------------------------------------------\n";
					std::cout << "INT Stack: ";
					stackInt.print();
					std::cout << "\nDOUBLE Stack: ";
					stackDouble.print();
					std::cout << "\nCHAR Stack: ";
					stackChar.print();
					std::cout << "\nString Stack: ";
					stackString.print();
					stack_menu_choice = 0;
				}
				else if (stack_menu_choice == 5) //go back to stack operations menu
				{
					main_menu_choice = 0;
					stack_menu_choice == 0;
				}
			} while (stack_menu_choice != 5);
		}
		else if (main_menu_choice == 3)
		{
			std::cout << "\nGoodbye.";
			system("PAUSE");
			return 0;
		}
	} while (main_menu_choice != 3);
	std::cout << "\nGoodbye.";
	system("PAUSE");
	return 0;
}