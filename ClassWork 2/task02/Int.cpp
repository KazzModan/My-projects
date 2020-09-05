#include <iostream>
#include "Int.h"
using namespace std;

Int::Int(int number)
{
	this->number = number;
}
Int::~Int()
{
	number = 0;
}
int Int::getRes() const
{
	return this->number;
}
Int::Int()
{
	this->number = 0;
}
Int Int::sum(Int number)
{
	return this->number + number.number;
}
Int Int::div(Int number)
{
	if(number.number !=0)
	return this->number / number.number;
}
Int Int::mult(Int number)
{
	return this->number * number.number;

}
Int Int::sub(Int number)
{
	return this->number - number.number;
}
Int Int::SumArr(Int number)
{
		 return this->number += number.number;
}