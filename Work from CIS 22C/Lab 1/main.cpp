/////////////////////////////////////////////////////////////////////////////////////////////
//Name: Steve Tu
//Date: 1/23/17
//Class: CIS 22C
//Teacher: Goel
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Wallet.h"
#include "Currencies.h"

using namespace std;

int main()
{
	cout << "-----------------------------------------------------\n";
	cout << "\t\tInitialization of Wallet\n";  /////////Here, we begin to initlialize the contents of the wallets including the names and values.
	cout << "-----------------------------------------------------\n";
	cout << "Welcome! Let's begin by having you initialize the contents of your wallet." << endl;
	cout << "How many currencies are you planning to add to your wallet? ";
	int currencyamount;
	cin >> currencyamount;
	cout << "Now we need you to enter the whole and the part name of the currencies seperately." << endl;
	int counter = 0;
	string wholename;
	string partname;
	vector <Wallet *> myWallet;  ////////////Creates a vector of base pointers.
	do
	{
		myWallet.push_back(new Currencies()); /////////The do while loop will make sure that there are enough Currencies objects in the vector.
			cout << "\nPlease enter the whole name of the currency in your wallet.";
			do
			{
				cout << "\nWhole name: ";
				cin >> wholename;
				if (myWallet[counter]->CheckCurrencyExists(myWallet, wholename) == true) 
				{       //////This will check to see if the following names are already inside the wallet.
					cout << "You entered a whole name of a currency that already exists in your wallet. Please try again." << endl;
				}
			} while (myWallet[counter]->CheckCurrencyExists(myWallet, wholename) == true);
			do
			{
				cout << "\nPart name: ";
				cin >> partname;
				if (myWallet[counter]->CheckCurrencyExists(myWallet, partname) == true)
				{
					cout << "You entered a part name of a currency that already exists in your wallet. Please try again." << endl;
				}
			} while (myWallet[counter]->CheckCurrencyExists(myWallet, partname) == true);
			myWallet[counter]->setwholeName(wholename); //////////... if not, then the vector will call functions to set the names.
			myWallet[counter]->setpartName(partname);
			cout << endl << "You have successfully added in " << myWallet[counter]->getwholeName() << " and " << myWallet[counter]->getpartName() << endl; 	//This line is to check if input was successful in Currencies derived class and that I can access it.
			counter = counter + 1;
	} while (counter != currencyamount);
	cout << "-----------------------------------------------------\n";
	cout << "\t\tAdding in your Currencies\n";      ////////////// Now we add in the values for our cuurrencies.
	cout << "-----------------------------------------------------\n";
	cout << "\nGood! You are now done adding in your " << currencyamount << " Currencies." << endl;
	cout << "Now let's add in how many of each Currency is in your wallet. Please enter them seperately." << endl;
	counter = 0;
	do ////////This do while loop will loop through every currency in the wallet.
	{
		int wholevalue = 0;
		int partvalue = 0;
		cout << "\nPlease enter the amount of " << myWallet[counter]->getwholeName() << ": ";
		cin >> wholevalue;
		cout << "\nNow enter the amount of " << myWallet[counter]->getpartName() << ": ";
		cin >> partvalue;
		myWallet[counter]->setwholeValue(wholevalue);
		myWallet[counter]->setpartValue(partvalue);
		myWallet[counter]->setpos(counter);
		myWallet[counter]->Checkfor100();  ////////////This will check to see if our partValue is over 100 and adjusts both wholeValue and partValue accordingly.
		cout << "You now have " << myWallet[counter]->getwholeValue() << " " << myWallet[counter]->getwholeName() << " and " << myWallet[counter]->getpartValue() << " " << myWallet[counter]->getpartName();
		counter = counter + 1;
	} while (counter != currencyamount);
	cout << "\n\nNow that you have successfully added in your currencies into your wallet, what would you like to do now?" << endl;
	int choice = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	do
	{
		cout << "-----------------------------------------------------\n";
		cout << "\t\tMain Menu\n";
		cout << "-----------------------------------------------------\n";
		cout << "\n1. Add more money" << "\n2. Remove some money" << "\n3. Remove some or all currencies" << "\n4. Check status of wallet" << "\n5. Exit out";
		cout << "\nMy choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1://////////////////////////////////////////////////////////Deposit into the wallet.
			if (currencyamount != 0)
			{
				do
				{
					cout << "\n";
					cout << "-----------------------------------------------------\n";
					cout << "\t\tDeposit into Wallet\n";
					cout << "-----------------------------------------------------\n";
					counter1 = 0;
					for (counter = 0; counter < currencyamount; counter++) ////////////Loop to display the available currencies to add to.
					{
						cout << "\n" << counter << ". " << myWallet[counter]->getwholeName() << " and " << myWallet[counter]->getpartName();
						counter1++;
					}
					cout << "\n" << counter1 << ". Back to Main Menu";
					cout << endl << "Your choice: ";
					cin >> choice1;
				} while (choice1 > currencyamount + 1 || choice1 < 0);
				if (choice1 < currencyamount && choice1 != counter1) ////////This condition will lead the user to adding some amount into their currency.
				{
					string amount;
					cout << "\nHow much do you want to add to " << myWallet[choice1]->getwholeName() << " and " << myWallet[choice1]->getpartName() << "?";
					cout << "\nYour choice: ";
					cin >> amount;
					size_t pos = amount.find("."); ////////////Finds the decimal point in the string.
					string sub = amount.substr(0, pos);
					string sub2 = amount.substr(pos + 1); ////////Seperates the wholeValue and partValue.
					int whole = 0;
					unsigned int part = 0;
					stringstream convert(sub);
					convert >> whole;
					stringstream convert2(sub2);
					convert2 >> part;
					int x = myWallet[choice1]->getwholeValue() + whole;
					int y = myWallet[choice1]->getpartValue() + part;
					myWallet[choice1]->setwholeValue(x);
					myWallet[choice1]->setpartValue(y);
					myWallet[choice1]->Checkfor100();
					cout << "\nYou now have " << myWallet[choice1]->getwholeValue() << " " << myWallet[choice1]->getwholeName() << " and " << myWallet[choice1]->getpartValue() << " " << myWallet[choice1]->getpartName() << "\n";
					break;
				}
				else if (choice1 == counter1)  ///////////This is for if the user wants to go back to the main menu.
				{
					break;
				}
				else ////////This catches any wrong choice inputs.
				{
					cout << "You entered a wrong choice number." << endl;
					break;
				}
			}
			else ////////////This catches if your wallet is currently empty.
			{
				cout << "\nYou cleared out your wallet already. You can't add any more.\n";
				break;
			}
		case 2: ////////////////////////////////////////////////////Withdraw from the wallet.
			if (currencyamount != 0)
			{
				do
				{
					cout << "-----------------------------------------------------\n";
					cout << "\t\tWithdraw from Wallet\n";
					cout << "-----------------------------------------------------\n";
					cout << "\n";
					counter2 = 0;
					for (counter = 0; counter < currencyamount; counter++)
					{
						cout << "\n" << counter << ". " << myWallet[counter]->getwholeName() << " and " << myWallet[counter]->getpartName();
						counter2++;
					}
					cout << "\n" << counter2 << ". Back to Main Menu";
					cout << endl << "Your choice: ";
					cin >> choice2;
				} while (choice2 > currencyamount + 1 || choice2 < 0);
				if (choice2 < currencyamount && choice2 != counter2)
				{
					string amount;
					cout << "\nHow much do you want to remove from " << myWallet[choice2]->getwholeName() << " and " << myWallet[choice2]->getpartName() << "?";
					cout << "\nYour choice: ";
					cin >> amount;
					size_t pos = amount.find(".");
					string sub = amount.substr(0, pos);
					string sub2 = amount.substr(pos + 1);
					int whole = 0;
					unsigned int part = 0;
					stringstream convert(sub);
					convert >> whole;
					stringstream convert2(sub2);
					convert2 >> part;
					int x = myWallet[choice2]->getwholeValue() - whole;
					int y = myWallet[choice2]->getpartValue() - part;
					myWallet[choice2]->setwholeValue(x);
					myWallet[choice2]->setpartValue(y);
					myWallet[choice2]->Checkfor100();
					myWallet[choice2]->CheckforNegative();
					cout << "\nYou now have " << myWallet[choice2]->getwholeValue() << " " << myWallet[choice2]->getwholeName() << " and " << myWallet[choice2]->getpartValue() << " " << myWallet[choice2]->getpartName() << "\n";
					break;
				}
				else if (choice2 == counter2)
				{
					break;
				}
				else
				{
					cout << "You entered a wrong choice number." << endl;
					break;
				}
			}
			else
			{
				cout << "\nYou cleared out your wallet already. You can't take anything out anymore.\n";
			}
		case 3: ///////////////////////////////fulfills the condition of the lab to offer options to remove currencies from wallet.
			if (currencyamount != 0)
			{
				do
				{
					cout << "-----------------------------------------------------\n";
					cout << "\tRemoving Currencies from Wallet\n";
					cout << "-----------------------------------------------------\n";
					counter3 = 0;
					cout << "\n\nWhat would you like to remove?";
					for (counter = 0; counter < currencyamount; counter++)
					{
						cout << "\n" << counter << ". " << myWallet[counter]->getwholeName() << " and " << myWallet[counter]->getpartName();
						counter3++;
					}
					cout << "\n" << counter3 << ". Remove all Currencies from the Wallet";
					cout << "\n" << counter3 + 1 << ". Back to Main Menu" << endl;
					cin >> choice3;
				} while (choice3 > currencyamount + 1 || choice3 < 0);
				if (choice3 != counter3 + 1)
				{
					if (choice3 != counter3) ///////This will remove the currency that you chose.
					{
						cout << "Removing " << myWallet[choice3]->getwholeName() << " and " << myWallet[choice3]->getpartName() << " now...\n";
						myWallet[choice3]->removeCurrency(myWallet, choice3);
						myWallet[choice3] = myWallet.back(); ///////Moves the now empty element to the end of the vector....
						myWallet.pop_back();      //////////////////... so that I can remove it here.
						currencyamount = currencyamount - 1; ///////Decrements the amount of currency left inside the wallet.
						cout << "Done!\n";
						break;
					}
					else
					{
						cout << "Removing all Currencies from wallet now..." << endl;
						for (int i = 0; i < currencyamount; i++) ////////for loop to loop through each element of the vector so that they can delete themselves.
						{
							myWallet[i]->removeCurrency(myWallet, i);
						}
						currencyamount = 0; ///////Sets the number of currencies left in the wallet to zero.
						cout << "All currencies have been deleted." << endl;
						break;
					}
				}
				else /////////Catches a wrong input.
				{
					cout << "\nYou have entered a wrong option.\n";
					break;
				}
			}
			else ////////////Catches if you don't have any currency left in your wallet to remove.
			{
				cout << "\nYou don't have any currency left inside your wallet.\n";
				break;
			}
		case 4: /////////////////////////////checks the status of the wallet and its currencies including names and amounts.
			if (currencyamount == 0)
			{
				cout << "\n\nYou don't have any currency left in your wallet.\n";
				break;
			}
			else
			{
				cout << endl;
				cout << myWallet; ///////////operator overload for << to print out the names and values of each currency.
				break;
			}
		case 5: /////////////////////////////Emptys the wallet and exit out the program.
			myWallet.clear(); ///////////////clears the container.
			cout << "\nHave a nice day.\n\n";
			system("pause");
			return 0; // Exit the program. Does it delete memory correctly?
		default: /////////////////////////////Catches a wrong input.
			cout << "\n\nInvalid menu choice. Please try again.\n";
		}
	} while (choice != 5);
}
