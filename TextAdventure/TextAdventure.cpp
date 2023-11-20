#include <iostream>
#include "Map.h"
#include "Game.h"

int main()
{
	Game myGame;

	myGame.ConstructConsole(80, 60, 12, 16);

	myGame.Start();
}
