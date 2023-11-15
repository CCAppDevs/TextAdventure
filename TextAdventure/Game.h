#pragma once
#include "olcConsoleGameEngineOOP.h"
#include "Map.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();

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
};

