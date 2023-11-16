#pragma once
#include <string>
#include "EColour.h"
#include "Game.h"

class AbstractRoom
{

private:
	 
protected:
	std::string Description;

public:
	AbstractRoom(std::string desc);

	std::string GetDescription();
	void SetDescription(std::string desc);

	virtual bool Execute(Game& myGame);

	virtual short ToShort() = 0;
	virtual COLOUR GetColour();
};

