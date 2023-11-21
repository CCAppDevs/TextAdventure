#pragma once
#include "AbstractCharacter.h"
class Player :
    public AbstractCharacter
{
public:
    Player(std::string name, float maxHealth, float minDamage, float maxDamage);
    // Inherited via AbstractCharacter
    void TakeDamage(float amount) override;
};

