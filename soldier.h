#pragma once
#include "characterbase.h"
#include "weapon.h"
#include "armor.h"

class Soldier
{
private:
	CharacterBase base;
	Weapon sword;
	Armor leathers;
	int currentHealth;
	bool vecFlag;
public:
	Soldier::Soldier()
	{
		currentHealth = base.getHealth();
		vecFlag = false;
	}
	bool onAttack(int dmgvals[])
	{
		currentHealth = currentHealth - int(double(dmgvals[0]) * leathers.getPhysicalResistance()
			+ double(dmgvals[1]) * leathers.getRangedResistance()
			+ double(dmgvals[2]) * leathers.getMagicResistance());
		if (currentHealth <= 0)
		{
			base.setStatus(false);
		}
		return base.getStatus();
	}
	int onHeal(int heal)
	{
		currentHealth += heal;
		if (currentHealth > base.getHealth())
		{
			currentHealth = base.getHealth();
		}
		return currentHealth;
	}
	int onRessurect()
	{
		base.setStatus(true);
		currentHealth = base.getHealth()/5;
	}
	int getCurrHealth()
	{
		return currentHealth;
	}
	CharacterBase getCharProperties()
	{
		return base;
	}
	Armor getArmorProperties()
	{
		return leathers;
	}
	Weapon getWeaponProperties()
	{
		return sword;
	}
	bool getvecFlag()
	{
		return vecFlag;
	}
};