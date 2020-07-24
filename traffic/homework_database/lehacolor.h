#pragma once
#include <windows.h>

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

namespace cl 
{

	enum Colors
	{
		Black = 0,
		Blue,
		Green,
		Cyan,
		Red,
		Purple,
		Brown,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightPurple,
		Yellow,
		White = 15
	};
	
	inline void SetColor(Colors color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, WORD(color));
	}
}
