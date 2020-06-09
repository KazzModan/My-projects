#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	stack<int> st;
	for (size_t i = 0; i < 4; i++)
	{
		cout << "in stack" << i + 1 << endl;
		st.push(i + 1);
	}
	

	return 0;
}
