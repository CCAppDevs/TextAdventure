#include "AbstractCharacter.h"

float AbstractCharacter::GetRandomNumber(float min, float max)
{
	using namespace std;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distr(min, max);
	return distr(gen);
}

AbstractCharacter::AbstractCharacter()
{
	Name = "";
	Health = 100.f;
	MaxHealth = 100.f;
	DamageMin = 1.f;
	DamageMax = 10.f;
}

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
	return GetRandomNumber(DamageMin, DamageMax);
}

std::string AbstractCharacter::GetName()
{
	return Name;
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
