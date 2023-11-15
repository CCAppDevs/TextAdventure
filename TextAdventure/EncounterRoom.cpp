#include "EncounterRoom.h"

EncounterRoom::EncounterRoom(std::string desc, std::string monsterType) : AbstractRoom(desc)
{
    MonsterType = monsterType;
    Description += MonsterType;
}

std::string EncounterRoom::Execute()
{
    return "You have triggered an encounter";
}

short EncounterRoom::ToShort()
{
    return L'M';
}

COLOUR EncounterRoom::GetColour()
{
    return FG_RED;
}
