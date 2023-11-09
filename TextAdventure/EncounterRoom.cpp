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

std::string EncounterRoom::ToString()
{
    return "[M]";
}
