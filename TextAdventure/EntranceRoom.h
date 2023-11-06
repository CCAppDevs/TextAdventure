#pragma once
#include "AbstractRoom.h"
class EntranceRoom :
    public AbstractRoom
{
public:
    EntranceRoom(std::string desc);

    std::string ToString();
};

