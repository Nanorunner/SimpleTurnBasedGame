#pragma once
#include "characterbase.h"
#include "weapon.h"
#include "armor.h"

class Tank
{
private:
	CharacterBase base;
	Weapon greatsword;
	Armor heavySteel;
	int currentHealth;
public:
	Tank::Tank()
	{
		base.setSymbol("H");
		base.setMoveset(1);
		base.setHealth(500);
		currentHealth = base.getHealth();
		base.setStatus(true);
		base.setReqPoints(30);
		greatsword.setName("Greatsword");
		greatsword.setDamage(150);
		heavySteel.setName("Steel Plate");
		heavySteel.setPhysicalResistance(.40);
		heavySteel.setRangedResistance(.30);
	}
	bool onAttack(int dmgvals[])
	{
		currentHealth = currentHealth - int(double(dmgvals[0]) * heavySteel.getPhysicalResistance()
			+ double(dmgvals[1]) * heavySteel.getRangedResistance()
			+ double(dmgvals[2]) * heavySteel.getMagicResistance());
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
		return heavySteel;
	}
	Weapon getWeaponProperties()
	{
		return greatsword;
	}
};