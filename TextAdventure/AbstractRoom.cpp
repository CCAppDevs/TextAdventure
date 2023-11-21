#include "AbstractRoom.h"
#include "Game.h"

AbstractRoom::AbstractRoom(std::string desc)
{
    Description = desc;
    hasBeenVisited = false;
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

bool AbstractRoom::GetHasBeenVisited()
{
    return hasBeenVisited;
}

void AbstractRoom::SetHasBeenVisited(bool newState)
{
    hasBeenVisited = newState;
}
