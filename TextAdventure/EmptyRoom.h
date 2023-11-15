#pragma once
#include "AbstractRoom.h"
class EmptyRoom :
    public AbstractRoom
{
private:

protected:

public:
    EmptyRoom(std::string desc);
    
    short ToShort() override;

};

