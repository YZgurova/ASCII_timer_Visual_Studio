#include "Timer.h"

int main()
{
	Timer timer;
	cin >> timer.seconds;
	system("cls");

	timer.ConvertSeconds(timer.seconds);
	timer.StartOfTimer();
	timer.EndOfTimer();
}