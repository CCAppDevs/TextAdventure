#include "EncounterRoom.h"
#include "Game.h"

EncounterRoom::EncounterRoom(std::string desc, std::string name, float health, float minDamage, float maxDamage)
    : AbstractRoom(desc)
{
    theEnemy = new Enemy(name, health, minDamage, maxDamage);
    Marker = L'M';
    RoomColour = FG_RED;
}

bool EncounterRoom::Execute(Game& myGame)
{
    if (!hasBeenVisited) {
        myGame.StartCombat(*theEnemy);
        SetHasBeenVisited(true);
    }
    
    return hasBeenVisited;
}

Enemy* EncounterRoom::GetEnemy()
{
    return theEnemy;
}


short EncounterRoom::ToShort()
{
    return Marker;
}

COLOUR EncounterRoom::GetColour()
{
    return RoomColour;
}

void EncounterRoom::SetComplete()
{
    Marker = L'X';
    RoomColour = FG_GREEN;
}
