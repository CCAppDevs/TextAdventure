#pragma once
#include "olcConsoleGameEngineOOP.h"
#include "Map.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	bool StartEncounter(std::string encounterText);

protected:

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapesedTime) override;

private:
	// player
	int playerX;
	int playerY;

	void moveX(int amount);
	void moveY(int amount);

	std::string text;

	// map
	int mapX;
	int mapY;
	Map* myMap;


	// Room Tools
	// start combat
	// end combat
	// deal damage to the player
	// display a puzzle
	// check for solution to puzzle
	// output text to the buffer
};

