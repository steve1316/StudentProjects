//CIS 22C
//Lab 01-Design a wallet that can hold and manage up to five different currency types
//Name: Syed Tihami

/*
 Pseudocode:
 int main
 First displays introductory messages
 Defines variables and creates wallet class
 Prompts user with list of operations and asks for selection
 Follows corresponding path based on user selection
 Case 1: Add new currency type to wallet:
 First asks user for desired currency type, and then calls the
 add currency method of the wallet class to dynamically allocate it
 If it cannot be created, the program returns an error message
 Case 2: Add money to wallet
 First prompts user with list of currencies available and asks for selection
 Sends selection string to checkString method to return the appropriate index
 If index not found, returns an error message
 Else, it asks the user whether to add or subtract money
 Then it asks the user for amount of money (whole and fractional) to add or subtract
 Then it sends the choices to the appropriate method to add/subtract
 Case 3: Display contents of wallet
 Begin for
 Displays each currency available in the wallet
 If reached end of wallet, exit loop
 Case 4:
 Calls the empty wallet method of the wallet class
 Checks to see if wallet properly emptied.
 If not properly emptied, throws an error
 */

#include <string>
#include <iostream>
#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Pound.h"
#include "Euro.h"
#include "PKRupee.h"
#include "Riyal.h"


using namespace std;

int Currency::instances = 0;

int main() {
    cout << "CIS 22C\nLab 01-Design a wallet that can hold and manage up to five different currency types\nName: Syed Tihami\n\n\n";
    
    Wallet wallet;
    string choice;
    cout << "Welcome!\n";
    try {
        do {
            cout << "\nPlease select from the following options:\n1)Add a new currency type to your wallet\n2)Add money to your wallet or subtract money from it\n3)Display the contents of your wallet\n4)Empty your wallet\n5)Exit\nSelection: ";
            cin >> choice;
            cin.ignore();
				switch (choice[0]) {
				case '1': /* Add a new currency type to wallet */ {
							  string selection;
							  cout << "\nPlease enter the name of the currency you would like to add. Listed below are the currencies you may add:\nA)Dollar\nB)British Pound\nC)Euro\nD)Pakistani Rupee\nE)Saudi Riyal\nSelection: ";
							  getline(cin, selection);
							  if (wallet.addCurrency(selection)) {
								  cout << "ERROR: The requested currency was not found or is already being used\n";
							  }
							  else {
								  cout << "Successfully added " << wallet[wallet.getNumCurrencies() - 1]->getWholeName() << " to wallet.\n";
							  }
							  break;
				}
				case '2': /* Add money to wallet */ {
							  Currency temp;
							  string entry;
							  int index;
							  cout << "Please enter the name of the currency you would like to add money to/subtract money from:\n";
							  for (int i = 0; i < wallet.getNumCurrencies(); i++) {
								  cout << static_cast<char>(i + 65) << ") " << wallet[i]->getWholeName() << endl;
							  }
							  getline(cin, entry);
							  index = wallet.checkCurrency(entry);
							  if (index == -1) {
								  cout << "Sorry, the requested currency was not found. Please try again.\n";
							  }
							  else {
								  char addSubtract;
								  cout << "Would you like to add to (Y) or subtract from (N) this currency?\n";
								  cin >> addSubtract;
								  cin.ignore();
								  cout << "Please enter the number of " << wallet[index]->getWholeName() << "s and " << wallet[index]->getFractName() << "s you would like to add:\n";
								  cin >> temp;
								  cin.ignore();
								  addSubtract == 'Y' ? wallet.addByCurrency(temp, index) : wallet.subtractByCurrency(temp, index);
							  }
							  break;
				}
				case '3': /*Print all available currencies*/ {
							  for (int i = 0; i < wallet.getNumCurrencies(); i++)
								  cout << wallet[i]->getWholeName() << ": " << *(wallet[i]) << endl;
							  break;
				}
				case '4': /* Empty Wallet */ {
							  wallet.emptyWallet();
							  if (wallet.isEmpty()) {
								  cout << "Your wallet is now empty.\n";
							  }
							  else throw "ERROR: Wallet not properly emptied\n";
							  break;
				}
				}
        } while (choice[0] != '5');
    }
    catch (string s) {
        cout << s << endl;
    }
    catch (const char *s) {
        cout << s << endl;
    }
	cin.ignore();
    return 0;
}
