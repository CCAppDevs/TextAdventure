#pragma once
#include <string>
#include "EColour.h"

class Game;

class AbstractRoom
{

private:
	 
protected:
	std::string Description;
	bool hasBeenVisited;

public:
	AbstractRoom(std::string desc);

	std::string GetDescription();
	void SetDescription(std::string desc);

	virtual bool Execute(Game& myGame);

	virtual short ToShort() = 0;
	virtual COLOUR GetColour();

	virtual bool GetHasBeenVisited();
	virtual void SetHasBeenVisited(bool newState);
};

