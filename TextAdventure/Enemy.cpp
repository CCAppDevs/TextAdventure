#include "Enemy.h"

Enemy::Enemy(std::string name, float maxHealth, float minDamage, float maxDamage)
	: AbstractCharacter(name, maxHealth, minDamage, maxDamage)
{
}

void Enemy::TakeDamage(float amount)
{
	if (Health + amount < 0) {
		Health = 0;
		return;
	}
	else if (Health + amount > MaxHealth) {
		Health = MaxHealth;
		return;
	}
	else {
		Health += amount;
		return;
	}
}
