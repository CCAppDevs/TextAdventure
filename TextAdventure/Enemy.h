#pragma once
#include "AbstractCharacter.h"

class Enemy : public AbstractCharacter
{
public:
	Enemy(std::string name, float maxHealth, float minDamage, float maxDamage);
	void TakeDamage(float amount) override;
};

