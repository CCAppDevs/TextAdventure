#include "AbstractRoom.h"

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

bool AbstractRoom::Execute()
{
    return false;
}
