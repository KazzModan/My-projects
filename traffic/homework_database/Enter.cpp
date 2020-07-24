#include "Enter.h"

void Enter::enter()
{	
	if(char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail()) 
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
	
	getline(cin, data);
}

bool Enter::returnData(size_t& number)
{
	if (data.empty())
		return false;

	if (!checkString('0', '9', '0'))
		return false;

	const char MAX[] = MAX_SIZE_T;

	if (!checkStringToMax(MAX))
		return false;

	int temp = 0;
	int multiple = 1;

	for (int i = int(data.length()) - 1; i >= 0; i--)
	{
		const int CONST = 48;
		int ch = static_cast<int>(data[i]);
		temp += (ch - CONST) * multiple;
		multiple *= 10;
	}

	number = size_t(temp);
	return true;
}

bool Enter::returnData(string& string)
{
	string = this->data;
	return true;
}

bool Enter::checkString(char low, char high, char plus)
{
	size_t count = 0;

	for (size_t i = 0; i < data.length(); i++)
		if (data[i] >= low && data[i] <= high || data[i] == plus)
			count++;

	if (count == data.length())
		return true;

	return false;
}

bool Enter::checkStringByFilters(string filters)
{
	size_t count = 0;

	for (size_t i = 0; i < data.length(); i++)
		if (filters.find(data[i]) != -1)
			count++;

	if (count == data.length())
		return true;

	return false;
}

bool Enter::checkStringToMax(const char type[])
{
	if (data[0] != '-') 
	{
		size_t length = data.length();

		if (length > strlen(type))
			return false;

		for (size_t i = 0; i < length; i++)
			if (data[i] > type[i])
				return false;
	}
	else 
	{
		size_t length = data.length();

		if (length > strlen(type) + 1)
			return false;

		for (size_t i = 1; i < length; i++)
			if (data[i] > type[i - 1])
				return false;
	}

	return true;
}

bool Enter::operator>>(string& text)
{
	enter();
	text = this->data;
	return true;
}

bool Enter::operator>>(size_t& number)
{
	enter();
	return returnData(number);
}

void Enter::format(string& text, string filters)
{
	enter();
	
	if (!checkStringByFilters(filters))
		return;

	text = this->data;
}

void Enter::format(string& text, char low, char high)
{
	enter();

	if (!checkString(low, high, low))
		return;

	text = this->data;
}
