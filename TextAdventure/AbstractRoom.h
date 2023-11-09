#pragma once
#include <string>

/*

[0][0][0][0][0]
[0][1][2][2][0]
[0][2][3][2][0]
[0][4][2][9][0]
[0][0][0][0][0]

*/

class AbstractRoom
{

private:
	 
protected:
	std::string Description;

public:
	AbstractRoom(std::string desc);

	std::string GetDescription();
	void SetDescription(std::string desc);

	virtual std::string ToString() = 0; // draw the cell of the room
	virtual std::string Execute();
};

