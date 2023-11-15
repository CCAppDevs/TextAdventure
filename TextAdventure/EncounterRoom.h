#pragma once
#include "AbstractRoom.h"
#include <iostream>

class EncounterRoom :
    public AbstractRoom
{
private:
    std::string MonsterType;

public:
    EncounterRoom(std::string desc, std::string monsterType);

    std::string Execute() override;

    // Inherited via AbstractRoom
    short ToShort() override;
    COLOUR GetColour() override;
};

