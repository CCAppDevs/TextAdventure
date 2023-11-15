#include "EmptyRoom.h"

EmptyRoom::EmptyRoom(std::string desc) : AbstractRoom(desc)
{
}

short EmptyRoom::ToShort()
{
    return L' ';
}