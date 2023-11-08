#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Map.h"

// interface
// map or game board
// characters and enemies
// randomness

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	bool isPlaying = true;
	Map myMap = Map(25, 25);
	int c;

	ShowConsoleCursor(false);

	while (isPlaying) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		cout << myMap.ToString();

		c = 0;

		switch ((c = _getch())) {
		case KEY_UP:
			myMap.MoveY(-1);
			break;
		case KEY_DOWN:
			myMap.MoveY(1);
			break;
		case KEY_LEFT:
			myMap.MoveX(-1);
			break;
		case KEY_RIGHT:
			myMap.MoveX(1);
			break;
		default:
			// not arrow
			break;
		}
	}
	
}
