/////////////////////////////////////////////////////////////////////
//
//Name: Steve Tu
//Partner: Peter Shin
//Partner Score: 5
//Date: 03/20/17
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;
bool contains_month(string &birthday);
int mainMenu(); void addMenu(); void removeMenu(); void modifyMenu();  void searchMenu(); int category();

int main(){

	BST<string> name(new Node<string>());
	BST<string> birthday(new Node<string>());

	ifstream dataFile;
	ofstream nameFile, birthdayFile;
	nameFile.open("name.txt");
	birthdayFile.open("birthday.txt");

	int user_choice = 0, tree;
	string lines, entry, editt;
	std::cout << "Opening database..." << endl;
	if (!dataFile){
		dataFile.close();
		std::cout << "Error could not open file\n";
		return 0;
	}
	dataFile.open("data.txt");
	cout << "Data base successfully opened\n" << endl;
	while (getline(dataFile, lines)){
		if (contains_month(lines)){
			//cout << lines << endl;
			birthday.insert(lines);
			birthdayFile << lines << endl;
		}
		else {
			//cout << lines << endl;
			name.insert(lines);
			//nameFile << lines << endl;
		}
	}

	do{
		user_choice = mainMenu();
		switch (user_choice){
		case 1:
			//add stuff
			addMenu();
			cin.ignore();
			getline(cin, entry);
			tree = category();
			cin.ignore();
			if (tree == 1){
				name.insert(entry);
			}
			else if (tree == 2){
				birthday.insert(entry);
			}
			break;
		case 2:
			//delete stuff
			cout << "Name BST: " << endl;
			name.print_postOrder();
			cout << "\n" << endl;;
			cout << "\nBirthday BST: " << endl;
			birthday.print_preOrder();
			removeMenu();
			cin.ignore();
			getline(cin, entry);
			tree = category();
			cin.ignore();
			if (tree == 1){
				name.remove(entry);
			}
			else if (tree == 2){
				birthday.remove(entry);
			}
			break;
		case 3:
			//Modify stuff
			cout << "Name BST: " << endl;
			name.print_postOrder();
			cout << "\n" << endl;;
			cout << "\nBirthday BST: " << endl;
			birthday.print_preOrder();
			modifyMenu();
			cin.ignore();
			getline(cin, entry);
			cout << "Enter the new node" << endl;
			cout << ">>> ";
			cin.ignore();
			getline(cin, editt);
			tree = category();
			cin.ignore();
			if (tree == 1){
				name.remove(entry);
				name.insert(editt);
			}
			else if (tree == 2){
				birthday.remove(entry);
				birthday.insert(editt);
			}
			break;
		case 4:
			//Search stuff
			searchMenu();
			cin.ignore();
			getline(cin, entry);
			tree = category();
			cin.ignore();
			if (tree == 1){
				if (name.search(entry)){
					cout << "\nYour entry has been found." << endl;
					cout << "Your data is inside the database" << endl;
				}
				else{
					cout << "Sorry your data could not be found" << endl;
				}

			}
			else if (tree == 2){
				if (birthday.search(entry)){
					cout << "\nYour entry has been found." << endl;
					cout << "Your data is inside the database" << endl;
				}
				else{
					cout << "Sorry your data could not be found" << endl;
				}
			}
			break;
		}
	} while (user_choice != 5);

	cout << "Name BST: " << endl;
	name.print_postOrder();
	cout << "\n" << endl;;
	cout << "\nBirthday BST: " << endl;
	birthday.print_preOrder();

	//save name and birthday BST to file save.txt
	
	name.writeToFile(nameFile);
	nameFile.close();
	birthdayFile.close();
	dataFile.close();
	system("pause");
	return 0;
}

bool contains_month(string &birthday){
	if (birthday.find("January") != string::npos){
		return true;
	}
	else if (birthday.find("February") != string::npos)
	{
		return true;
	}
	else if (birthday.find("March") != string::npos)
	{
		return true;
	}
	else if (birthday.find("April") != string::npos)
	{
		return true;
	}
	else if (birthday.find("May") != string::npos)
	{
		return true;
	}
	else if (birthday.find("June") != string::npos)
	{
		return true;
	}
	else if (birthday.find("July") != string::npos)
	{
		return true;
	}
	else if (birthday.find("August") != string::npos)
	{
		return true;
	}
	else if (birthday.find("September") != string::npos)
	{
		return true;
	}
	else if (birthday.find("October") != string::npos)
	{
		return true;
	}
	else if (birthday.find("November") != string::npos)
	{
		return true;
	}
	else if (birthday.find("December") != string::npos)
	{
		return true;
	}
	else{
		return false;
	}
	return false;
}

int mainMenu(){
	int main;

	cout << "\n--------------------Main Menu--------------------" << endl;
	cout << "1. Enter data into the database" << endl;
	cout << "2. Remove data from the database" << endl;
	cout << "3. Modify the data from the database" << endl;
	cout << "4. Search the data in database" << endl;
	cout << "5. Exit the program" << endl;
	cout << ">>> ";
	cin >> main;

	return main;
}

void addMenu(){

	cout << "\n\n--------------------Add Menu--------------------" << endl;
	cout << "What would you like to add to the database?" << endl;
	cout << ">>> ";
}

void removeMenu(){
	cout << "\n\n--------------------Delete Menu--------------------" << endl;
	cout << "What would you like to delete from the database?" << endl;
	cout << ">>> ";
}

void modifyMenu(){
	cout << "\n\n--------------------Modify Menu--------------------" << endl;
	cout << "What would you like to modify from the database?" << endl;
	cout << ">>> ";
}

void searchMenu(){
	cout << "\n\n--------------------Search Menu--------------------" << endl;
	cout << "What would you like to search from the database?" << endl;
	cout << ">>> ";
}

int category(){
	int cat;

	cout << "\n\n--------------------Picking Category--------------------" << endl;
	cout << "Where would you like to add/remove/modify/search? " << endl;
	cout << "1. Name" << endl;
	cout << "2. Birthday" << endl;
	cout << ">>> ";

	cin >> cat;
	return cat;
}