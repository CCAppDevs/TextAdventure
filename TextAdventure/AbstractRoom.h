#pragma once
#include <string>
#include "EColour.h"

class AbstractRoom
{

private:
	 
protected:
	std::string Description;

public:
	AbstractRoom(std::string desc);

	std::string GetDescription();
	void SetDescription(std::string desc);

	virtual std::string Execute();

	virtual short ToShort() = 0;
	virtual COLOUR GetColour();
};

