#include "EncounterRoom.h"
#include "Game.h"

EncounterRoom::EncounterRoom(std::string desc, std::string monsterType) : AbstractRoom(desc)
{
    MonsterType = monsterType;
    Description += MonsterType;
}

bool EncounterRoom::Execute(Game& myGame)
{
    myGame.StartEncounter("Fighting a goblin.");
    return false;
}


short EncounterRoom::ToShort()
{
    return L'M';
}

COLOUR EncounterRoom::GetColour()
{
    return FG_RED;
}
