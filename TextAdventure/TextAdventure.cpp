#include <iostream>
#include "Map.h"
#include "Game.h"

int main()
{
	Game myGame;

	myGame.ConstructConsole(80, 60, 8, 8);

	myGame.Start();
}
