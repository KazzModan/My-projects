#pragma once
#include <iostream>
using std::cout;
using std::cin;
class Wallet
{
private:
	Wallet(size_t money);
	static Wallet* ptr;
	size_t money;
public:
	void setMoney(size_t money);
	size_t getMoney() { return this->money; }
	static Wallet getWallet(size_t money);
	void print();
};

