#include "EncounterRoom.h"

EncounterRoom::EncounterRoom(std::string desc, std::string monsterType) : AbstractRoom(desc)
{
    MonsterType = monsterType;
}

void EncounterRoom::Execute()
{
    std::cout << "You have triggered an encounter\n";
}

std::string EncounterRoom::ToString()
{
    return "[M]";
}
