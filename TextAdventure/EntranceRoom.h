#pragma once
#include "AbstractRoom.h"
class EntranceRoom :
    public AbstractRoom
{
public:
    EntranceRoom(std::string desc);

    // Inherited via AbstractRoom
    short ToShort() override;
    COLOUR GetColour() override;
};

