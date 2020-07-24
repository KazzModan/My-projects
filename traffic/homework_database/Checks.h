#pragma once
#include <iostream>
using std::string;

inline bool CheckPeopleName(string name)
{
	if (name.empty())
		return false;

	size_t quantity = 0;
	size_t length = name.length();

	for (size_t i = 0; i < length; i++)
		if ((name[i] >= 'A' && name[i] <= 'Z') || 
			(name[i] >= 'a' && name[i] <= 'z') || 
			name[i] == ' ')
			quantity++;

	if (quantity == length)
		return true;
	else
		return false;
}

inline bool CheckPhoneNumber(string number)
{
	size_t tempLenght = 0;
	size_t lenght = 0;
	size_t numLenght = number.length();
	if (!numLenght)
		return false;

	if (number.find('+') == -1)
		lenght = 12;
	else
		lenght = 13;

	if (numLenght != lenght)
		return false;

	for (size_t i = 0; i < numLenght; i++)
		if ((number[i] >= '0' && number[i] <= '9') ||
			number[i] >= '+')
			tempLenght++;

	if ((numLenght == tempLenght) && numLenght == lenght)
		return true;
	else
		return false;
}

inline bool CheckTitle(string title)
{
	size_t tempLenght = 0;
	size_t titleLenght = title.length();
	if (!titleLenght)
		return false;

	for (size_t i = 0; i < titleLenght; i++)
		if ((title[i] >= 'A' && title[i] <= 'Z') ||
			(title[i] >= 'a' && title[i] <= 'z') ||
			(title[i] >= '0' && title[i] <= '9') ||
			title[i] >= ' ')
			tempLenght++;

	if (titleLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckNumber(string number)
{
	size_t tempLenght = 0;
	size_t numberLenght = number.length();
	if (!numberLenght)
		return false;

	for (size_t i = 0; i < numberLenght; i++)
		if (number[i] >= '0' && number[i] <= '9')
			tempLenght++;

	if (numberLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckUpperLetters(string text)
{
	if (text.empty())
		return false;

	size_t quantity = 0;
	size_t length = text.length();

	for (size_t i = 0; i < length; i++)
		if (text[i] >= 'A' && text[i] <= 'Z')
			quantity++;

	if (quantity == length)
		return true;
	else
		return false;
}

inline bool CheckLowerLetters(string text)
{
	if (text.empty())
		return false;

	size_t quantity = 0;
	size_t length = text.length();

	for (size_t i = 0; i < length; i++)
		if (text[i] >= 'a' && text[i] <= 'z')
			quantity++;

	if (quantity == length)
		return true;
	else
		return false;
}