#pragma once
#include "AbstractRoom.h"
class EmptyRoom :
    public AbstractRoom
{
public:
    EmptyRoom(std::string desc);
    // Inherited via AbstractRoom
    virtual std::string ToString() override;
};

