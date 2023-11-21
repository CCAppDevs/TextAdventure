#include "Player.h"

Player::Player(std::string name, float maxHealth, float minDamage, float maxDamage)
	: AbstractCharacter(name, maxHealth, minDamage, maxDamage)
{
}

void Player::TakeDamage(float amount)
{
	// clamp our value
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
