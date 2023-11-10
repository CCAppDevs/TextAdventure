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

    bool Execute() override;

    // Inherited via AbstractRoom
    std::string ToString() override;
};

