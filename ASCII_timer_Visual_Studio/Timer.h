#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

const int COLS = 10;
const int ROWS = 11;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
HWND handleWindow = GetConsoleWindow();


const char* const digits[COLS][ROWS] =
{
	{
	// digit 0 
	"0000000000",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0        0",
	"0000000000"
			},
	// digit 1 
	{
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1",
	"         1"
	},
	// digit 2 
	{
	"2222222222",
	"         2",
	"         2",
	"         2",
	"         2",
	"2222222222",
	"2         ",
	"2         ",
	"2         ",
	"2         ",
	"2222222222"
	},
	// digit 3 
	{
	"3333333333",
	"         3",
	"         3",
	"         3",
	"         3",
	"3333333333",
	"         3",
	"         3",
	"         3",
	"         3",
	"3333333333"
	},
	// digit 4 
	{
	"4        4",
	"4        4",
	"4        4",
	"4        4",
	"4        4",
	"4444444444",
	"         4",
	"         4",
	"         4",
	"         4",
	"         4"
	},
	// digit 5 
	{
	"5555555555",
	"5         ",
	"5         ",
	"5         ",
	"5         ",
	"5555555555",
	"         5",
	"         5",
	"         5",
	"         5",
	"5555555555"
	},
	// digit 6 
	{
	"6666666666",
	"6         ",
	"6         ",
	"6         ",
	"6         ",
	"6666666666",
	"6        6",
	"6        6",
	"6        6",
	"6        6",
	"6666666666"
	},
	// digit 7 
	{
	"7777777777",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7",
	"         7"
	},
	// digit 8 
	{
	"8888888888",
	"8        8",
	"8        8",
	"8        8",
	"8        8",
	"8888888888",
	"8        8",
	"8        8",
	"8        8",
	"8        8",
	"8888888888"
	},
	// digit 9 
	{
	"9999999999",
	"9        9",
	"9        9",
	"9        9",
	"9        9",
	"9999999999",
	"         9",
	"         9",
	"         9",
	"         9",
	"9999999999"
	}
};

struct Timer
{
	int minutes = 0;
	int seconds = 0;
	int hours = 0;
	int hourTens;
	int hourUnits;
	int minTens;
	int minUnits;
	int secTens;
	int secUnits;
	int randomColour;


	void ConvertSeconds(int seconds)
	{
		while (seconds > 60)
		{
			secToMin(seconds, minutes);
		}
		while (minutes > 60)
		{
			minToHours(minutes, hours);
		}
	}

	void hoursToMin(int& hoursInput, int& minsInput)
	{
		hoursInput--;
		minsInput += 60;
	}

	void minToHours(int& minsInput, int& hoursInput)
	{
		hoursInput++;
		minsInput -= 60;
	}

	void secToMin(int& secInput, int& minsInput)
	{
		minsInput++;
		secInput -= 60;
	}

	void minToSec(int& minInput, int& secInput)
	{
		minInput--;
		secInput += 60;
	}
	void EndOfTimer()
	{
		for (int i = 0; i < ROWS; i++)
		{
			cout << string(20, ' ');
			cout << digits[0][i];
			cout << " ";
			cout << digits[0][i];
			cout << " ";
			if (i == 4 || i == 7) cout << char(178);
			else cout << " ";
			cout << digits[0][i];
			cout << " ";
			cout << digits[0][i];
			cout << " ";
			if (i == 4 || i == 7) cout << char(178);
			else cout << " ";
			cout << " ";
			cout << digits[0][i];
			cout << " ";
			cout << digits[0][i];
			cout << " ";
			cout << endl;
		}
		PlaySound(TEXT("D:\\Домашни работи-ФМИ\\УП\\ASCII_timer_Visual_Studio\\ASCII_timer_Visual_Studio\\alarmsound.wav"), NULL, SND_SYNC);
	}

	void StartOfTimer()
	{
		SetWindowPos(handleWindow, 0, 0, 0, 800, 15 * 25, SWP_SHOWWINDOW | SWP_NOMOVE);
		if (seconds >= 60)
		{
			secToMin(seconds, minutes);
		}
		if (minutes >= 60)
		{
			minToHours(minutes, hours);
		}
		if (seconds < 0)
		{
			if (minutes > 0)
			{
				minToSec(minutes, seconds);
			}
			else if (hours > 0)
			{
				hoursToMin(hours, minutes);
				minToSec(minutes, seconds);
			}
			else EndOfTimer();
		}
		if (minutes < 10)
		{
			minTens = 0;
			minUnits = minutes % 10;
			secTens = seconds / 10;
			secUnits = seconds % 10;
		}
		else if (minutes >= 10 && minutes < 60) {
			minTens = minutes / 10;
			minUnits = minutes % 10;
			secTens = seconds / 10;
			secUnits = seconds % 10;
		}
		if (hours < 10)
		{
			hourTens = 0;
			hourUnits = hours % 10;
			minTens = minutes / 10;
			minUnits = minutes % 10;
			secTens = seconds / 10;
			secUnits = seconds % 10;
		}
		else if (hours >= 10)
		{
			hourTens = hours / 10;
			hourUnits = hours % 10;
			minTens = minutes / 10;
			minUnits = minutes % 10;
			secTens = seconds / 10;
			secUnits = seconds % 10;
		}
		for (int i = 0; i < ROWS; i++)
		{
			cout << string(30, ' ');
			if (hours > 0)
			{
				cout << digits[hourTens][i];
				cout << " ";
				cout << digits[hourUnits][i];
				cout << " ";
				if (i == 4 || i == 7) cout << char(178);
				else cout << " ";
				cout << " ";
			}
			if (hours == 0 && minutes < 15 && minutes>0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			if (hours > 0 || minutes > 0)
			{
				cout << digits[minTens][i];
				cout << " ";
				cout << digits[minUnits][i];
				cout << " ";
				if (i == 4 || i == 7) cout << char(178);
				else cout << " ";
				cout << " ";
			}
			if (hours == 0 && minutes == 0 && seconds > 9)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}

			cout << digits[secTens][i];
			cout << " ";
			cout << digits[secUnits][i];
			cout << " ";
			cout << endl;
		}
		if (seconds < 10)
		{
		}
		randomColour = 1 + (rand() % (15 - 1 + 1));
		SetConsoleTextAttribute(h, randomColour | FOREGROUND_INTENSITY);
		seconds--;
		Sleep(1000);
		system("cls");
		StartOfTimer();
	}

};
