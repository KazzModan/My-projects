#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define PHONE_CHECK number[0] != '+' || number[1] != '3' || number[2] != '8' || number[3] != '0' || number.length() != 13 

class Phone
{
private:
	string fullName;
	string homePhone;
	string workPhone;
	string mobilePhone;
public:
	Phone()
	{
		fullName = "Smith Smith Smith";
		homePhone = "+380--------";
		workPhone = "+380--------";
		mobilePhone = "+380--------";
	}
	void print()
	{
		cout << "Full name: " << this->fullName << endl;
		cout << "Home phone: " << this->homePhone << endl;
		cout << "work phone: " << this->workPhone << endl;
		cout << "mobile phone: " << this->mobilePhone << endl;
	}
	void setName(string name)
	{
		this->fullName = name;
	}
	bool setHomePhNumber(string number)
	{
		if (!(PHONE_CHECK))
		{
			this->homePhone = number;
			return true;
		}
		else
		{
			cout << "Wtf dude?\n";
			return false;
		}
	}
	bool setWorkPhNumber(string number)
	{
		if (!(PHONE_CHECK))
		{
			this->workPhone = number;
			return true;

		}
		else
		{
			cout << "Wtf dude?\n";
			return false;
		}
	}
	bool setMobilePhNumber(string number)
	{
		if (!(PHONE_CHECK))
		{
			this->mobilePhone = number;
			return true;
		}
		else
		{
			cout << "Wtf dude?\n";
			return false;
		}
	}
	string getFName() const
	{
		return this->fullName;
	}
	void findByName(size_t size, Phone* phone)
	{
		string name;
		string surname;
		string fName;
		string fullName;
		int index = -1;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter Father name: ";
		cin >> fName;
		fullName = name + " " + surname + " " + fName;
		for (size_t i = 0; i < size; i++)
		{
			if (fullName == phone[i].fullName)
			{
				index = i;
				break;
			}
			else
			continue;
		}
		if (index == -1)
		{
			cout << "Sorry, i didn't find this user in phonebook\n";
			return;
		}
		phone[index].print();
	}
	
	string getHnumber() const
	{
		return this->homePhone;
	}
	string getWnumber() const
	{
		return this->workPhone;
	}
	string getMnumber() const
	{
		return this->mobilePhone;
	}
	
};
void CreatePhone(Phone& phone);
Phone* AddNewPhone(Phone* phones, size_t& size, Phone& phone);
void ShowAllUser(size_t size, Phone* phones);
Phone* DeleteUser(Phone* phones, size_t& size);
void Menu();
void PutInfoInFile( Phone* phone, size_t size);
string getLineFF(ifstream& file);
Phone* ReadFromFile(size_t& size);
size_t GetCountsFromFile();
int main()
{
	Phone* phones = nullptr;
	Phone phone;
	size_t size = 0;
	int choise;
	bool isExit = false;
	do
	{
		Menu();
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			CreatePhone(phone);
			phones = AddNewPhone(phones, size, phone);
			break;
		case 2:
			phones->findByName(size, phones);
			break;
		case 3:
			ShowAllUser(size, phones);
			break;
		case 4:
			phones = DeleteUser(phones, size);
			break;
		case 5:
			PutInfoInFile( phones, size);
		default:
			cout << "Incorrect choose\n";
			break;
		case 6:
			phones = ReadFromFile(size);
		case 7:
			cout << "Goodbye\n";
			isExit = true;
		}
	} while (!isExit);
	delete[] phones;
	return 0;
}
Phone* AddNewPhone(Phone* phones, size_t& size, Phone& phone)
{
	if (size == 0)
	{
		Phone* nPhone = new Phone[1];
		nPhone[0] = phone;
		size++;
		return nPhone;
	}
	Phone* newPhones = new Phone[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newPhones[i] = phones[i];
	}
	newPhones[size] = phone;
	size++;
	delete[] phones;
	return newPhones;
	delete[]newPhones;
}
void ShowAllUser(size_t size, Phone* phones)
{
	if (size == 0)
	{
		cout << "List is empty\n";
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		phones[i].print();
		cout << "--------------\n";
	}
}
void CreatePhone(Phone& phone)
{
	string name;
	string surname;
	string fName;
	string hPhone;
	string wPhone;
	string mPhone;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter Father name: ";
	cin >> fName;
	phone.setName((name + " " + surname + " " + fName));
	do
	{
		cout << "Enter home phone:";
		cin >> hPhone;
		phone.setHomePhNumber(hPhone);
		cout << "Enter work phone:";
		cin >> wPhone;
		phone.setWorkPhNumber(wPhone);
		cout << "Enter mobile phone:";
		cin >> mPhone;
		phone.setMobilePhNumber(mPhone);
	}while(!phone.setHomePhNumber(hPhone)|| !phone.setWorkPhNumber(wPhone)|| !phone.setMobilePhNumber(mPhone));
}
void Menu()
{
	cout << "Choose\n";
	cout << "(1) Add new User\n";
	cout << "(2) Find number by FIO\n";
	cout << "(3) Show all users\n";
	cout << "(4) Delete user\n";
	cout << "(5) Save information to file\n";
	cout << "(6) Exit\n";
}
void PutInfoInFile(Phone* phone, size_t size)
{
	ofstream fs("text.txt", ofstream::app);
	for (size_t i = 0; i < size; i++)
	{
		fs << "Full name: " << phone[i].getFName() << endl;
		fs << "Work ph number: " << phone[i].getWnumber() << endl;
		fs << "Mobile ph number: " << phone[i].getMnumber() << endl;
		fs << "Home ph number: " << phone[i].getHnumber() << endl;
		fs << "-------------------\n";
	}
	fs.close();
}
Phone* DeleteUser(Phone* phones, size_t& size)
{
	string name;
	string surname;
	string fName;
	string fullName;
	
	int index = -1;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter Father name: ";
	cin >> fName;
	fullName = name + " " + surname + " " + fName;
	for (size_t i = 0; i < size; i++)
	{
		if (fullName == phones[i].getFName())
		{
			index = i;
			break;
		}
		else
			continue;
	}
	if (index == -1)
	{
		cout << "Sorry, i didn't find this user in phonebook\n";
		return phones;
	}
	Phone* newUser = new Phone[size - 1];
	for (size_t i = 0; i < index;i++)
	{
		newUser[i] = phones[i];
	}
	for (size_t i = index + 1; i < size; i++)
	{
		newUser[i-1] = phones[i];

	}
	size--;
	delete[] phones;
	return newUser;
}
Phone* ReadFromFile(size_t& size)
{
	size = GetCountsFromFile();
	Phone* newBook = new Phone[size];
	ifstream file("text.txt");
	for (size_t i = 0; i < size; i++)
	{
		newBook[i].setName(getLineFF(file));
		newBook[i].setWorkPhNumber(getLineFF(file));
		newBook[i].setMobilePhNumber(getLineFF(file));
		newBook[i].setHomePhNumber(getLineFF(file));
		getLineFF(file);
	}
	file.close();
	
	return newBook;
}
size_t GetCountsFromFile()
{
	ifstream file("text.txt");
	size_t count = 0;
	string temp;
	string endOfAcc = "-------------------\n";

	while (!file != EOF)
	{
		getline(file, temp);
		if (temp == endOfAcc)
			count++;
	}
	return count;
}
string getLineFF(ifstream& file)
{
	string temp;
	getline(file, temp);
	return temp;
}