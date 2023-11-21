#pragma once
#include "olcConsoleGameEngineOOP.h"
#include "Map.h"
#include <queue>
#include "Player.h"
#include "Enemy.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();
	bool StartEncounter(std::string encounterText);
	void StartCombat(Enemy& theEnemy);

protected:

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapesedTime) override;

private:
	// player
	int playerX;
	int playerY;

	Player myPlayer;

	void moveX(int amount);
	void moveY(int amount);

	// output variables
	std::string text;

	float OutputTimeThreshold;
	float OutputTimeElapsed;
	std::queue<std::string> Output;

	// map
	int mapX;
	int mapY;
	Map* myMap;


	// Room Tools
	AbstractRoom& GetCurrentRoom();

	// start combat
	// end combat
	// deal damage to the player
	// display a puzzle
	// check for solution to puzzle
	
	// output text to the buffer
	void QueueOutputText(std::string message);
	void DrawTextOutput(float fElapsedTime);
};

