#include <iostream>
using namespace std;

const int COLS = 10;
const int ROWS = 11;

const int numOfNums = 10;
const int numOfLines = 11;

const char* const codes[numOfNums][numOfLines] =
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

int main()
{
   
}