#pragma once
#include <string>
class AbstractCharacter
{
private:

protected:
	std::string Name;
	float Health;
	float MaxHealth;
	float DamageMin;
	float DamageMax;

public:
	AbstractCharacter();
	AbstractCharacter(std::string name, float maxHealth, float minDamage, float maxDamage);

	float RollForDamage();
	virtual void TakeDamage(float amount) = 0;

	std::string GetName();

	float GetHealth();
	float GetMaxHealth();
	float GetDamageMin();
	float GetDamageMax();

	void SetHealth(float amount);
	void SetMaxHealth(float amount);
	void SetDamageMin(float amount);
	void SetDamageMax(float amount);
};

