#include "EncounterRoom.h"
#include "Game.h"

EncounterRoom::EncounterRoom(std::string desc, std::string monsterType) : AbstractRoom(desc)
{
    MonsterType = monsterType;
    Description += MonsterType;
}

bool EncounterRoom::Execute(Game& myGame)
{
    if (!hasBeenVisited) {
        myGame.StartEncounter("Fighting a goblin.");
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
