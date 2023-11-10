#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Map.h"
#include "Console.h"

// interface
// map or game board
// characters and enemies
// randomness

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define CLEAR 99
#define ATTACK 97
#define RUN 114

int main()
{
	Map* myMap = new Map(20, 20);
	Console console = Console(*myMap, 5);

	bool isPlaying = true;
	int c = 0;

	while (isPlaying) {
		// run a frame of the game
		c = 0;

		// draw statement
		console.Draw();

		switch ((c = _getch())) {
		case KEY_UP:
			myMap->MoveY(-1);
			break;
		case KEY_DOWN:
			myMap->MoveY(1);
			break;
		case KEY_LEFT:
			myMap->MoveX(-1);
			break;
		case KEY_RIGHT:
			myMap->MoveX(1);
			break;
		case CLEAR:
			console.Drain();
			break;
		default:
			// not arrow
			break;
		}
	}

	
}
