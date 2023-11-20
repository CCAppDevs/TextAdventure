#include "AbstractRoom.h"
#include "Game.h"

AbstractRoom::AbstractRoom(std::string desc)
{
    Description = desc;
}

std::string AbstractRoom::GetDescription()
{
    return Description;
}

void AbstractRoom::SetDescription(std::string desc)
{
    Description = desc;
}

bool AbstractRoom::Execute(Game& myGame)
{
    return true;
}

COLOUR AbstractRoom::GetColour()
{
    return FG_DARK_GREY;
}
