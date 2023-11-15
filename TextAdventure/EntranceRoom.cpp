#include "EntranceRoom.h"

EntranceRoom::EntranceRoom(std::string desc) : AbstractRoom(desc)
{
}

short EntranceRoom::ToShort()
{
    return L'S';
}

COLOUR EntranceRoom::GetColour()
{
    return FG_YELLOW;
}
