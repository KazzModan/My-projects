#include <iostream>

using namespace std;
enum
{
	MAX_MONEY = 9999999, MIN_MONEY = 0, MIN_CURRENCY = 0, MAX_CURRENCY = 2
};
class Account
{
private:
	string numberOfAccount;
	int money;
	int typeOfCurrency;

public:
	void setAccount(string account)
	{
		this->numberOfAccount = account;
	}
	void setMoney(int money)
	{
		this->money = money;
	}
	void setType(int type)
	{
		this->typeOfCurrency = type;
	}
	string getAccount() const
	{
		return this->numberOfAccount;
	}
	int getMoney() const
	{
		return this->money;
	}
	int getType() const
	{
		return this->typeOfCurrency;
	}
	Account()
	{
		this->numberOfAccount = "";
		this->money = 0;
		this->typeOfCurrency = 0;
	}
	Account(string number, int money, int type)
	{
		setAccount(number);
		setMoney(money);
		setType(type);
	}
	void print()
	{
		cout << "Account name: " << getAccount() << endl;;
		cout << "Money on the account: " << getMoney() << endl;
		switch (getType())
		{
		case 0:
			cout << "Account's type of currency: grivna\n";
			break;
		case 1:
			cout << "Account's type of currency: $\n";
			break;
		case 2:
			cout << "Account's type of currency: euro\n";
			break;
		}
	}
	void AddMoney()
	{
		int money;
		cout << "Enter money, that u want add: ";
		cin >> money;
		if (!(money<MIN_MONEY || money + this->money>MAX_MONEY))
		{
			setMoney(money + this->money);
			cout << "On ur account was add " << money << endl;
		}
	}
	void substractMoney()
	{
		int money;
		cout << "Enter money, that u want take on ur hands: ";
		cin >> money;
		if (!(money < MIN_MONEY || this->money - money < MIN_MONEY))
		{
			setMoney(this->money - money);
			cout << "u took: " << money << endl;;
		}
	}
	void transferMoney(Account* bank)
	{
		int money, firstIndex, secondIndex;
		cout << "Enter money, that u want transfer: ";
		cin >> money;
		cout << "Enter index of account, from that u want transfer money: ";
		cin >> firstIndex;
		cout << "Enter index of account, to that u want transfer money: ";
		cin >> secondIndex;
		if (!(money < MIN_MONEY || bank[firstIndex - 1].money - money < MIN_MONEY || money + bank[secondIndex - 1].money>MAX_MONEY))
		{
			if (bank[firstIndex - 1].typeOfCurrency == bank[secondIndex - 1].typeOfCurrency)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex].money - money);
				bank[firstIndex - 1].setMoney(bank[secondIndex - 1].money + money);
				cout << "u took: " << money;
			}
			else if (bank[firstIndex - 1].typeOfCurrency == 0 && bank[secondIndex - 1].typeOfCurrency == 1)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money / 27);
				cout << "u took: " << money / 27 << endl;
			}
			else if (bank[firstIndex - 1].typeOfCurrency == 0 && bank[secondIndex - 1].typeOfCurrency == 2)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex - 1].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money / 30);
				cout << "u took: " << money / 30 << endl;
			}
			else if (bank[firstIndex - 1].typeOfCurrency == 1 && bank[secondIndex - 1].typeOfCurrency == 0)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex - 1].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money * 27);
				cout << "u took: " << money * 27 << endl;
			}
			else if (bank[firstIndex - 1].typeOfCurrency == 1 && bank[secondIndex - 1].typeOfCurrency == 2)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex - 1].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money * 0.92);
				cout << "u took: " << money * 0.92 << endl;
			}
			else if (bank[firstIndex - 1].typeOfCurrency == 2 && bank[secondIndex - 1].typeOfCurrency == 0)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex - 1].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money * 30);
				cout << "u took: " << money * 30 << endl;

			}
			else if (bank[firstIndex - 1].typeOfCurrency == 2 && bank[secondIndex - 1].typeOfCurrency == 1)
			{
				bank[firstIndex - 1].setMoney(bank[firstIndex - 1].money - money);
				bank[secondIndex - 1].setMoney(bank[secondIndex - 1].money + money / 0.92);
				cout << "u took: " << money / 0.92 << endl;
			}
		}
		else
			cout << "Wrong choose\n";
	}
};
void CreateAccount(Account& acc);
Account* AddNewAccount(Account* acconts, size_t& size, Account& account);
void Menu();
int main()
{
	Account* bank = nullptr;
	Account acc;
	size_t size = 0;
	int choose;
	bool exit = false;
	do
	{
		system("cls");
		Menu();
		cin >> choose;
		switch (choose)
		{
		case 1:
			CreateAccount(acc);
			bank = AddNewAccount(bank, size, acc);
			break;
		case 2:
			cout << "Enter index in list of acc,to that u want add: ";
			cin >> choose;
			if (!(choose - 1 < 0 || choose - 1 > size))
				bank[choose - 1].AddMoney();
			else
				cout << "Wrong choose\n";
			break;
		case 3:
			cout << "Enter index in list of acc,from u want substract money: ";
			cin >> choose;
			if (!(choose - 1 < 0 || choose - 1 > size))
				bank[choose - 1].substractMoney();
			break;
		case 4:
			cout << "Enter index of acc, that u want see: ";
			cin >> choose;
			if (choose - 1 >= size)
			{
				cout << "Sorry, i didn't find this acc int list\n";
				break;
			}
			bank[choose - 1].print();
			break;
		case 5:
			bank->transferMoney(bank);
			break;
		case 6:
			exit = true;
			break;
		default:
			cout << "Wrong choose";
			break;
		}
	} while (!exit);
	return 0;
}
void CreateAccount(Account& acc)
{
	int money;
	int type;
	string name;
	int counter = 0;
	int counterOfErrors = 0;
	do
	{
		counterOfErrors++;
		if (counterOfErrors > 1)
			cout << "You entered wrong value, do it again\n";
		cout << "Enter money, that account have: ";
		cin >> money;
		acc.setMoney(money);
		cout << "Enter type currency of money that u have(0-grivni,1-$,2-euro): ";
		cin >> type;
		acc.setType(type);
		cout << "Enter number of account(tip: use ONLY numbers): ";
		cin >> name;
		acc.setAccount(name);
		for (size_t i = 0; i < name.length(); i++)
		{
			if (name[i] < '0' || name[i]>'9' || name[i] == ' ')
				counter++;
		}
	} while (money > MAX_MONEY || money < MIN_MONEY || counter>0);
}

Account* AddNewAccount(Account* accounts, size_t& size, Account& account)
{
	if (size == 0)
	{
		Account* newBank = new Account[1];
		size++;
		newBank[0] = account;
		return newBank;
	}
	Account* newBank = new Account[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newBank[i] = accounts[i];
	}
	newBank[size] = account;
	size++;
	delete[] accounts;
	return newBank;
}

void Menu()
{
	cout << "choose\n";
	cout << "(1) Add new user\n";
	cout << "(2) Add money on account\n";
	cout << "(3) Substract money for account\n";
	cout << "(4) Show Currect account\n";
	cout << "(5) Make transfer\n";
	cout << "(6) Exit\n";
}
