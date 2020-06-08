#include <iostream>
#include "Shop.h"

User::User()
{
	_money = 0;
	_login = "";
	_password = "";
	_phone = "";
}

User::~User()
{
	_money = 0;
	_login = "";
	_password = "";
	_phone = "";
}

bool User::setLoging(string login)
{
	if (!login.empty())
	{
		_login = login;
		return true;
	}
	return false;
}

bool User::setPass(string pass)
{
	int counter = 0;
	for (size_t i = 0; i < pass.length(); i++)
	{
		if (!(pass[i] >= '!' && pass[i] <= '}'))
		{
			counter++;
		}
	}
	if (counter == 0)
	{
		_password = pass;
		return true;
	}
	return false;
}

bool User::setMoney(int money)
{
	if (money >= 0)
	{
		_money = money;
		return true;
	}
	return false;
}

bool User::setPhone(string phone)
{
	if (phone.length() == 13 && phone[0] == '+' && phone[1] == '3' && phone[2] == '8' && phone[3] == '0')
	{
		_phone = phone;
		return true;
	}
	return false;
}

bool User::setMail(string mail)
{
	if (mail[mail.length() - 1] == 'm' && mail[mail.length() - 2] == 'O' && mail[mail.length() - 3] == 'C' && mail[mail.length() - 4] == '.')
	{
		_email = mail;
		return true;
	}
	return false;
}

bool User::Register()
{
	string login, pass, phone, mail,tempPass;
	int money;
		do
		{
			cout << "Enter login: ";
			cin >> login;
			cout << "Enter money: ";
			cin >> money;
			cout << "Enter email: ";
			cin >> mail;
			cout << "Enter phone: ";
			cin >> phone;
			cout << "enter pass: ";
			cin >> pass;
			do
			{
				cout << "enter pass again: ";
				cin >> tempPass;
			} while (tempPass != pass);
			set(login, pass, money, phone, mail);
		} while (!check);
}

bool User::check(string login, string pass, int money, string phone, string mail)
{
	if (!setLoging(login) || !setPass(pass) || !setMoney(money) || !setPhone(phone) || !setMail(mail))
	{
		return false;
	}
	return true;
}

void User::set(string login, string pass, int money, string phone, string mail)
{
	setLoging(login);
	setPass(pass);
	setMoney(money);
	setPhone(phone);
	setMail(mail);
}

void User::login()
{
	string login, password;
	do
	{
		cout << "enter login: ";
		cin >> login;
		if (login != _login)
			cout << "Wrong login, enter again";
	} while (login!=_login);
	do
	{
		cout << "enter password: ";
		cin >> password;
		if (password != _password)
			cout << "Wrong password, enter again";
	} while (password != _password);
}

void User::addMoney(int money)
{
	if (money > 0)
		setMoney(_money + money);
}
