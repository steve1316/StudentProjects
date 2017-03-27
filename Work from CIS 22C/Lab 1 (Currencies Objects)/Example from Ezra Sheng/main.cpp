/*
CIS 22C
Lab 1: This program emulates a wallet, allowing the user to hold and manipulate value for up to 5 predefined currency objects
Author: Ezra Sheng
*/

#include <iostream>
#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Franc.h"
#include "Pound.h"
#include "Ruble.h"

using namespace std;

//The main serves as a menu for allowing the user to interact with the Wallet
int main()
{
	//initializing variables
	enum {USD, EUR, CHF, GBP, RUB};
	Wallet dosh = Wallet();
	Currency* d = new Dollar(0, 0);
	Currency* e = new Euro(0, 0);
	Currency* f = new Franc(0, 0);
	Currency* p = new Pound(0, 0);
	Currency* r = new Ruble(0, 0);
	bool loop = true;

	//declaring variables
	int choice, asub, addc, remove;
	double amount;

	//Menu
	do
	{
		cout << "Welcome to Wallet Manager" << endl
			<< "How can we help you?" << endl
			<< "(Choose an option by entering a number)" << endl;
		cout << "1. Add or subtract to a currency" << endl
			<< "2. Add a currency" << endl
			<< "3. Remove a currency" << endl
			<< "4. Print out the total value in the wallet" << endl
			<< "5. Remove everything in the wallet" << endl
			<< "6. See how many types of currency are in the wallet" << endl
			<< "7. Quit" << endl;
		cin >> choice;

		//Adding or subtracting to a currency
		if (choice == 1)
		{
			cout << "Choose a currency:" << endl;
			for (int x = 0; x < 5; x++)
			{
				if (dosh[x] != nullptr)
				{
					cout << x + 1 << ". " << dosh[x]->getCode() << " " << dosh[x]->getName() << '-' << dosh[x]->getFractName() << endl;
				}
			}

			if (!dosh.isEmpty())
			{
				do
				{
					cin >> asub;
					asub--;
					if (asub > 4 || asub < 0 || dosh[asub] == nullptr)
						cout << "Invalid input, please try again" << endl;
				} while (asub > 4 || asub < 0 || dosh[asub] == nullptr);
				cout << "The current value in this currency is " << dosh[asub]->getTotal() << endl;
				cout << "How much do you want to add or subtract? Enter one value up to the hundredths place" << endl << "(To subtract, input a negative number)" << endl;
				cin >> amount;
				dosh[asub]->addAmount(amount);
				cout << "The current value in this currency is now " << dosh[asub]->getTotal() << endl << endl;
			}
			else
			{
				cout << "There is no currency in your wallet" << endl << endl;
			}
		}

		//Adding a type of currency to the wallet
		else if (choice == 2)
		{
			cout << "Choose a currency to add" << endl
				<< "1. USD dollar-cent" << endl
				<< "2. EUR euro-cent" << endl
				<< "3. CHF franc-centime" << endl
				<< "4. GBP pound-pence" << endl
				<< "5. RUB ruble-kopek" << endl;
			cin >> addc;
			addc--;
			switch (addc)
			{
				case USD:
					dosh.addCurrency(USD, d);
					cout << endl << endl;
					break;
				case EUR:
					dosh.addCurrency(EUR, e);
					cout << endl << endl;
					break;
				case CHF:
					dosh.addCurrency(CHF, f);
					cout << endl << endl;
					break;
				case GBP:
					dosh.addCurrency(GBP, p);
					cout << endl << endl;
					break;
				case RUB:
					dosh.addCurrency(RUB,  r);
					cout << endl << endl;
					break;
				default:
					cout << "Invalid input, please try again" << endl << endl;
			}
		}

		//Removing a currency from the wallet
		else if (choice == 3)
		{
			for (int x = 0; x < 5; x++)
			{
				if (dosh[x] != nullptr)
				{
					cout << x + 1 << ". " << dosh[x]->getCode() << " " << dosh[x]->getName() << endl;
				}
			}
			if (!dosh.isEmpty())
			{
				cout << "Choose a currency" << endl;
				do
				{
					cin >> remove;
					remove--;
					if (remove > 4 || remove < 0 || dosh[asub] == nullptr)
						cout << "Invalid input, please try again" << endl;
				} while (remove > 4 || remove < 0 || dosh[asub] == nullptr);
				cout << "The current value in this currency is " << dosh[remove]->getTotal() << endl;
				dosh[remove]->setTotal(0);
				dosh.removeCurrency(remove);
				cout << "The currency has been removed" << endl << endl;
			}
			else
			{
				cout << "There is no currency in your wallet" << endl << endl;
			}
		}

		//Printing out the total value in the wallet
		else if (choice == 4)
		{
			dosh.printTotal();
			cout << endl;
		}

		//Removing everything in the wallet
		else if (choice == 5)
		{
			dosh.removeAll();
			cout << endl;
		}

		//Prints out the number and types of currency in the wallet
		else if (choice == 6)
		{
			cout << "The number of currency in the wallet is " << dosh.getCurrencyNumber() << endl;
			for (int x = 0; x < 5; x++)
			{
				if (dosh[x] != nullptr)
				{
					cout << dosh[x]->getCode() << " " << dosh[x]->getName() << '-' << dosh[x]->getFractName() << endl;
				}
			}
			cout << endl;
		}

		//Quits the menu
		else if (choice == 7)
		{
			loop = false;
		}

		//Tells the user that the value input is invalid
		else
		{
			cout << "Invalid input, please try again" << endl << endl;
		}

	}while (loop);  //end menu

	//Deleting dynamically allocated currencies
	delete d, e, f, p, r;

	return 0;
}