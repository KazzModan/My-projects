#pragma once
#include <iostream>

using namespace std;

class User
{
public:
	User();
	~User();
	bool setLoging(string login);
	bool setPass(string pass);
	bool setMoney(int money);
	bool setPhone(string phone);
	bool setMail(string mail);
	bool Register();
	bool check(string login, string pass, int money, string phone, string mail);
	void set(string login, string pass, int money, string phone, string mail);
	void login();
	void addMoney(int money);
private:
	string _login;
	string _password;
	int _money;
	string _phone;
	string _email;
};
