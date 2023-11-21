#include "AbstractCharacter.h"

AbstractCharacter::AbstractCharacter(std::string name, float maxHealth, float minDamage, float maxDamage)
{
	Name = name;
	Health = maxHealth;
	MaxHealth = maxHealth;
	DamageMin = minDamage;
	DamageMax = maxDamage;
}

float AbstractCharacter::RollForDamage()
{
	// todo add random roll for damage
	return 0.0f;
}

float AbstractCharacter::GetHealth()
{
	return Health;
}

float AbstractCharacter::GetMaxHealth()
{
	return MaxHealth;
}

float AbstractCharacter::GetDamageMin()
{
	return DamageMin;
}

float AbstractCharacter::GetDamageMax()
{
	return DamageMax;
}

void AbstractCharacter::SetHealth(float amount)
{
	Health = amount;
}

void AbstractCharacter::SetMaxHealth(float amount)
{
	MaxHealth = amount;
}

void AbstractCharacter::SetDamageMin(float amount)
{
	DamageMin = amount;
}

void AbstractCharacter::SetDamageMax(float amount)
{
	DamageMax = amount;
}
