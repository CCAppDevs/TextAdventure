#include <iostream>
#include <Windows.h>
#include <conio.h>
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
#define QUIT 113
#define ATTACK 97
#define RUN 114

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
	Map myMap = Map(25, 25);

	bool isPlaying = true;
	int c = 0;

	ShowConsoleCursor(false);

	while (isPlaying) {
		// run a frame of the game
		c = 0;

		// clear the console
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

		// draw statement
		cout << myMap.ToString();

		cout << "\nControls: Up, Down, Left, Right, (A)ttack, (R)un, (Q)uit\n";

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
		case QUIT:
			isPlaying = false;
			break;
		case ATTACK:
			break;
		case RUN:
			break;
		default:
			// not arrow
			break;
		}
	}

	
}
