#pragma once
#include "olcConsoleGameEngineOOP.h"

class Game : public olcConsoleGameEngineOOP
{
public:
	Game();

protected:

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapesedTime) override;

private:

};

