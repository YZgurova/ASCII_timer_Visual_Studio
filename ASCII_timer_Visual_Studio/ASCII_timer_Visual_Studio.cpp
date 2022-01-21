#include "Timer.h"

int main()
{
	Timer timer;
	cin >> timer.seconds;;
	system("cls");

	SetWindowPos(handleWindow, 0, 0, 0, 800, 15 * 25, SWP_SHOWWINDOW | SWP_NOMOVE);
	timer.ConvertSeconds();
	timer.StartOfTimer();
	timer.EndOfTimer();
}