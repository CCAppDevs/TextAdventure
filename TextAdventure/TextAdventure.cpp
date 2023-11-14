#include <iostream>
#include "Map.h"
#include "Game.h"

int main()
{
	Game myGame;

	myGame.ConstructConsole(80, 60, 1, 1);

	myGame.Start();
}
