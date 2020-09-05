#include "Wallet.h"

Wallet* Wallet::ptr = nullptr;
void Wallet::setMoney(size_t money)
{
	this->money = money;
}
Wallet Wallet::getWallet(size_t money)
{
	if (ptr == nullptr)
	{
		ptr = new Wallet(money);
	}
	return *ptr;
}
void Wallet::print()
{
	cout << "money: " << this->money;
}
Wallet::Wallet(size_t money)
{
	this->money = money;
}

