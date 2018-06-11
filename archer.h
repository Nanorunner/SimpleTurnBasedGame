#pragma once
#include "characterbase.h"
#include "weapon.h"
#include "armor.h"

class Tank
{
private:
	CharacterBase base;
	Weapon bowandarrow;
	Armor leathers;
	int currentHealth;
public:
	Tank::Tank()
	{
		base.setSymbol("A");
		currentHealth = base.getHealth();
		base.setStatus(true);
		base.setReqPoints(30);
		bowandarrow.setName("Bow and Arrow");
		bowandarrow.setDamage(350);
		bowandarrow.setDmgrange(3);
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
		currentHealth = base.getHealth() / 5;
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
		return bowandarrow;
	}
};