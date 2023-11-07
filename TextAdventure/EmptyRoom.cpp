#include "EmptyRoom.h"

EmptyRoom::EmptyRoom(std::string desc) : AbstractRoom(desc)
{
}

std::string EmptyRoom::ToString()
{
    return "[.]";
}
