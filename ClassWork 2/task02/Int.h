#pragma once
#include <iostream>
class Int
{
private:
	int number;
public:
	Int(int number);
	Int();
	~Int();
	int getRes()const ;
	Int div(Int number);
	Int sum(Int number);
	Int sub(Int number);
	Int mult(Int number);
	Int SumArr(Int number);
};
