#pragma once
#include "AbstractRoom.h"
#include <iostream>
#include "Enemy.h"

class Game;

class EncounterRoom :
    public AbstractRoom
{
private:
    Enemy* theEnemy;

public:
    EncounterRoom(std::string desc, std::string name, float health, float minDamage, float maxDamage);

    bool Execute(Game& myGame) override;

    // TODO: get enemy function so that we can manipulate the enemy during combat

    // Inherited via AbstractRoom
    short ToShort() override;
    COLOUR GetColour() override;
};

