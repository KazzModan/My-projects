#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

#define MAX_SHORT "32767"
#define MAX_UNSIGNED_SHORT "65535"
#define MAX_INT "2147483647";
#define MAX_SIZE_T "4294967295";

class Enter
{
public:
	
	bool operator >> (string& text);
	bool operator >> (size_t& number);
	void format(string& text, string filters);
	void format(string& text, char low, char high);

private:
	string data;

	void enter();

	bool returnData(size_t& number);
	bool returnData(string& string);

	bool checkString(char low, char high, char plus);
	bool checkStringByFilters(string filters);
	bool checkStringToMax(const char type[]);
};

static Enter lcin;