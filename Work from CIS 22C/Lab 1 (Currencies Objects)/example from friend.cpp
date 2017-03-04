#include <iostream>
#include <string>

using namespace std;

class ACC
{
private:
	string name;
	double ACCNO;
public:
	void setName(string n)
	{
		name = n;
	}
	void setACCNO(double A)
	{
		ACCNO = A;
	}
	string getName()
	{
		return name;
	}
	double getACCNO()
	{
		return ACCNO;
	}
};

class SavingACC : public ACC
{
private:
	double Deposit;
	double Balance = 500;
public:
	void setDeposit(double D)
	{
		Deposit = D;
	}
	void setBalance(double B)
	{
		Balance = B;
	}
	double getDeposit()
	{
		return Deposit;
	}
	double getBalance()
	{
		return Balance;
	}
	void Interest(int money)
	{
		float Sertax = 2;
		Balance = Balance - Sertax;
	}
	void Withdraw1()
	{
		int money;
		cout << "Enter the amount of Money to withdraw: ";
		cin >> money;
		if (Balance - money > 50)
		{
			if (Balance < 500)
			{
				cout << "We are imposing a penalty for being below the minimum balance" << endl << endl;
				int penalty = 50;
				Balance = Balance - (money + penalty);
				Interest(money);
				cout << "Transaction has been completed successfully" << endl;
			}
			else
			{
				Balance = Balance - money;
				Interest(money);
				cout << "Transcation has been completed" << endl;
			}
		}
		else
		{
			cout << "Transcation cannot be done" << endl;
		}
	}
	void Deposit1()
	{
		int money;
		cout << "Enter the amount of money to deposit: ";
		cin >> money;
		Balance = Balance + money;
	}
	void Display()
	{
		cout << "\n\nBalance: " << Balance << endl;
		cout << "The minimum Balance: 500\n\n" << endl;
	}
};

class CurrACC : public ACC
{
private:
	double Deposit;
	double Balance = 500;
public:
	void setDeposit(double D)
	{
		Deposit = D;
	}
	void setBalance(double B)
	{
		Balance = B;
	}
	double getDeposit()
	{
		return Deposit;
	}
	double getBalance()
	{
		return Balance;
	}
	void Check()
	{
		int money;
		string Bname;
		cout << "Enter the name of Check receiver: ";
		cin >> Bname;
		cout << "Enter the amount of money to send: ";
		cin >> money;
		if (Balance - money > 50)
		{
			if (Balance == 0)
			{
				cout << "You do not have enough funds to complete this transcation" << endl;
			}
			else
			{
				Balance = Balance - money;
				cout << "The Transcation has been completed successfully" << endl << endl;
				Display1(Bname, money);
			}
		}
	}
	void Deposit1()
	{
		int money;
		cout << "Enter the amount of money: ";
		cin >> money;
		Balance = Balance + money;
	}
	void Display()
	{
		cout << "\n\nBalance: " << Balance << endl;
		cout << "The minimum Balance: 500\n\n" << endl;
	}
	void Display1(string Bname, int money)
	{
		cout << "Check receiver: " << Bname << endl;
		cout << "Money: " << money << endl;
		cout << "Balance: " << Balance << endl;
	}
};

int main()
{
	int choice;
	cout << "Enter the type of the account " << endl << "1. Current" << endl << "2. Saving" << endl;
	cin >> choice;
	cout << "\n\n\n";
	switch (choice)
	{
	case 1:
	{
		CurrACC currentacc;
		string h;
		cout << "Enter the name of the Account holder: ";
		cin >> h;
		currentacc.setName(h);
		double k;
		cout << "Account Number: ";
		cin >> k;
		currentacc.setACCNO(k);
		cout << "\n\nAccount Name: " << currentacc.getName() << endl;
		cout << "Account Name: " << currentacc.getACCNO() << endl;
		cout << "Balance: " << currentacc.getBalance() << endl;
		do
		{
			cout << "\n\n1. Deposit" << endl << "2. Withdrawal through Check" << endl << "3. Exit" << endl << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				currentacc.Deposit1();
				currentacc.Display();
				break;
			}
			case 2:
			{
				currentacc.Check();
				currentacc.Display();
				break;
			}
			}
		} while (choice != 3);
		break;
	}
	case 2:
	{
		SavingACC savingacc;
		string h;
		cout << "Enter the name of the Account holder: ";
		cin >> h;
		savingacc.setName(h);
		double k;
		cout << "Account Number: ";
		cin >> k;
		savingacc.setACCNO(k);
		cout << "\n\nAccount Name: " << savingacc.getName() << endl;
		cout << "Account Name: " << savingacc.getACCNO() << endl;
		cout << "Balance: " << savingacc.getBalance() << endl;
		do
		{
			cout << "\n\n1. Deposit" << endl << "2. Withdrawal" << endl << "3. Exit" << endl << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				savingacc.Deposit1();
				savingacc.Display();
				break;
			}
			case 2:
			{
				savingacc.Withdraw1();
				savingacc.Display();
				break;
			}
			}
		} while (choice != 3);
		break;
	}
	}
	system("pause");
	return 0;
}