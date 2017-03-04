////////////////////////////////////////////
// Midterm Project
// Name: Steve Tu
// Teacher: Manish Goel
// Date: 02/15/17 modified for makeup on 02/22/17
////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Array
{
private:
	int counter = 0;
	int arrsize;
	T * myarray;
public:
	Array(int i) : arrsize(i), myarray(new T[i]) {}
	~Array();
	void add(const T & newData);
	void print();
	void recursiveSelectionSort(int startIndex);
};

template<class T>
void Array<T>::recursiveSelectionSort(int startIndex)
{
	//sorts the array myarray[counter] through myarray[arrsize - 1] recursively.
	if (startIndex >= arrsize - 1)
	{
		return; // ends sort if startIndex is higher or equal to the max number of elements in array.
	}
	int minIndex = startIndex;
	for (int i = startIndex + 1; i < arrsize; i++)
	{
		if (myarray[i] > myarray[minIndex]) // sorts in descending order.
			minIndex = i;
	}
	T temp = myarray[startIndex]; // After being done with for loop sorting whatever it can, sets element at startIndex to minIndex and start over.
	myarray[startIndex] = myarray[minIndex];
	myarray[minIndex] = temp;
	cout << endl;
	print(); // print whatever we have sorted so far.
	recursiveSelectionSort(startIndex + 1); // start the sort all over again until startIndex is equal to or greater than the max elements in array.
}   

template<class T>
void Array<T>::print()
{
	for (int i = 0; i < arrsize; i++)
	{
		cout << i + 1 << ". " << myarray[i] << endl; // loop to print all elements in array.
	}
}

template<class T>
void Array<T>::add(const T & newData)
{
	myarray[counter] = newData;
	counter++;
}

template<class T>
Array<T>::~Array()
{
}

int main()
{
	int size = 0;
	int intdata;
	double doubledata;
	char chardata;
	string stringdata;
	cout << "Initializing the Arrays now for int, double, char and string.";
	cout << "\nSize for int Array: ";
	cin >> size;
	Array<int> intArray(size);
	cout << "\nSize for double Array: ";
	cin >> size;
	Array<double> doubleArray(size);
	cout << "\nSize for char Array: ";
	cin >> size;
	Array<char> charArray(size);
	cout << "\nSize for string Array: ";
	cin >> size;
	Array<string> stringArray(size);
	cout << "\nInitialization of Arrays complete.";

	bool flag = false;
	do //Beginning of main menu loop.
	{
		int choice = 0;
		int choice2 = 0;
		int startIndex = 0;
		cout << "\nWhat would you like to do?";
		cout << "\n1. Array\n2. Exit\n>>> ";
		cin >> choice;
		if (choice == 1) // Array operations menu.
		{
			do 
			{
				cout << "\n1. Add\n2. Sort\n3. Print\n4. Back out";
				cout << "\n>>> ";
				cin >> choice;
				switch (choice)
				{
				case 1: // ADD data
					cout << "\nWhat data type do you want to work with?";
					cout << "\n1. int\n2. double\n3. char\n4. string";
					cout << "\n>>> ";
					cin >> choice2;
					switch (choice2)
					{
					case 1: // int data type.
						cout << "\n\tInt Data Type.";
						cout << "\nData to put into Array: ";
						cin >> intdata;
						intArray.add(intdata);
						break;
					case 2: // double data type.
						cout << "\n\tDouble Data Type.";
						cout << "\nData to put into Array: ";
						cin >> doubledata;
						doubleArray.add(doubledata);
						break;
					case 3: // char data type.
						cout << "\n\Char Data Type.";
						cout << "\nData to put into Array: ";
						cin >> chardata;
						charArray.add(chardata);
						break;
					case 4: // string data type.
						cout << "\n\String Data Type.";
						cout << "\nData to put into Array: ";
						cin.ignore();
						getline(cin, stringdata);
						stringArray.add(stringdata);
						break;
					default:
						cout << "\nWrong option.";
						break;
					}
					break;
				case 2: // SORT the array
					cout << "\nWhat data type do you want to sort?";
					cout << "\n1. int\n2. double\n3. char\n4. string";
					cout << "\n>>> ";
					cin >> choice2;
					switch (choice2)
					{
					case 1:
						intArray.recursiveSelectionSort(startIndex);
						break;
					case 2:
						doubleArray.recursiveSelectionSort(startIndex);
						break;
					case 3:
						charArray.recursiveSelectionSort(startIndex);
						break;
					case 4:
						stringArray.recursiveSelectionSort(startIndex);
						break;
					default:
						cout << "\nWrong option";
						break;
					}
					break;
				case 3: // print all of the arrays
					cout << "\nInt: \n";
					intArray.print();
					cout << "\nDouble: \n";
					doubleArray.print();
					cout << "\nChar: \n";
					charArray.print();
					cout << "\nString: \n";
					stringArray.print();
					break;
				case 4:
					// Exits out the menus and exits the program.
					cout << "\nExiting now...";
					break;
				default:
					cout << "\nWrong option entered.";
					break;
				}
			} while (choice != 4);
		}
		else if (choice == 2) // exits out the program.
		{
			flag = true;
		}
		else // if wrong choice is entered.
		{
			cout << "\nWrong choice entered";
		}
	} while (!flag); // loops until flag is set to true.

	return 0;
}
