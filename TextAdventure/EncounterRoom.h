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

    void Execute();

    // Inherited via AbstractRoom
    std::string ToString() override;
};

