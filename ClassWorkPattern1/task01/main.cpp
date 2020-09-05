#include <iostream>
#include "Wallet.h"

int main()
{
	Wallet wallet=Wallet::getWallet(100);
	Wallet wallet1 = Wallet::getWallet(200);

	wallet.print();
	return 0;

}