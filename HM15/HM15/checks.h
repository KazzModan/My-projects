#pragma once
#include <iostream>
using std::string;

namespace ch
{
	inline bool CheckPeopleName(string& nameSet, string name)
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
		{
			nameSet = name;
			return true;
		}

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

	inline bool CheckTitle(string& setTitle, string title)
	{
		size_t tempLenght = 0;
		size_t titleLenght = title.length();
		if (!titleLenght)
			return false;

		for (size_t i = 0; i < titleLenght; i++)
			if ((title[i] >= 'A' && title[i] <= 'Z') ||
				(title[i] >= 'a' && title[i] <= 'z') ||
				(title[i] >= '0' && title[i] <= '9') ||
				title[i] == ' ' || title[i] == '-')
				tempLenght++;

		if (titleLenght == tempLenght)
		{
			setTitle = title;
			return true;
		}
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

	inline bool CheckRangeEnum(size_t& varSet, size_t var, size_t low, size_t high)
	{
		if (var < low || var > high)
			return false;

		varSet = var;
		return true;
	}
	inline bool CheckLettersAndNumbers(string text)
	{
		if (text.empty())
			return false;

		size_t quantity = 0;
		size_t length = text.length();

		for (size_t i = 0; i < length; i++)
			if (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' || text[i] >= '0' && text[i] <= '9')
				quantity++;

		if (quantity == length)
			return true;
		else
			return false;
	}
	inline bool CheckMail(string& text)
	{
		size_t counter = 0;
		string temp;

		for (size_t i = 0; i < text.size()-10; i++)
			temp += text[i];

		if (!CheckLettersAndNumbers(temp))
			counter++;
		temp.clear();
		for (size_t i =  (text.size() - 10); i < text.size(); i++)
			temp += text[i];

		if (!(temp == "@gmail.com"))
			counter++;

		if (counter != 0)
			return false;
		return true;
	}
}