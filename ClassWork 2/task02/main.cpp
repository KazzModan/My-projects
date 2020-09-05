#include <iostream>
#include "Int.h"
using namespace std;

int main()
{
	const int SIZE = 5;
	Int a(3), b(8), res;
	res = a.sum(b);
	cout << res.getRes() << endl;
	res = a.sub(b);
	cout << res.getRes() << endl;
	res = b.div(a);
	cout << res.getRes() << endl;
	res = a.mult(b);
	cout << res.getRes() << endl;
	Int arr[SIZE];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 4;
	res = 0;
	for(size_t i=0;i<SIZE;i++)
		res.SumArr(arr[i]);
	cout << res.getRes() << endl;

	return 0;
}