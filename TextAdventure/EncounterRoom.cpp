#include "EncounterRoom.h"
#include "Game.h"

EncounterRoom::EncounterRoom(std::string desc, std::string name, float health, float minDamage, float maxDamage)
    : AbstractRoom(desc)
{
    theEnemy = new Enemy(name, health, minDamage, maxDamage);
}

bool EncounterRoom::Execute(Game& myGame)
{
    if (!hasBeenVisited) {
        myGame.StartCombat(*theEnemy);
        SetHasBeenVisited(true);
    }
    
    return hasBeenVisited;
}


short EncounterRoom::ToShort()
{
    return L'M';
}

COLOUR EncounterRoom::GetColour()
{
    return FG_RED;
}
