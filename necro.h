#pragma once
#include "characterbase.h"
#include "weapon.h"
#include "armor.h"
#include <vector>

class Support
{
private:
	CharacterBase base;
	vector <Weapon> items;
	Armor mageRobes;
	int currentHealth;
	bool vecFlag;
	int cooldown;
	bool offcooldown;
public:
	Support::Support()
	{
		//damage
		Weapon claws;
		claws.setName("Claws of Death");
		claws.setDamage(200);
		claws.setMagicdamage(100);
		claws.setDmgrange(1);
		//support
		Weapon resurrect;
		resurrect.setName("Raise Dead");
		resurrect.setDamage(0);
		resurrect.setDmgrange(0);

		base.setSymbol("M");
		currentHealth = base.getHealth();
		base.setStatus(true);
		base.setReqPoints(	70);
		base.setHealth(200);
		items.push_back(claws);
		items.push_back(resurrect);
		mageRobes.setPhysicalResistance(.20);
		mageRobes.setRangedResistance(.20);
		mageRobes.setMagicResistance(.50);
		vecFlag = true;
	}
	bool onAttack(int dmgvals[])
	{
		currentHealth = currentHealth - int(double(dmgvals[0]) * mageRobes.getPhysicalResistance()
			+ double(dmgvals[1]) * mageRobes.getRangedResistance()
			+ double(dmgvals[2]) * mageRobes.getMagicResistance());
		if (currentHealth <= 0)
		{
			base.setStatus(false);
		}
		return base.getStatus();
	}
	bool getOnCooldown()
	{
		return offcooldown;
	}
	void incrementCooldown()
	{
		cooldown--;
		if (cooldown <= 0)
		{
			offcooldown = true;
		}
	}
	bool resetCooldown()
	{
		if ((offcooldown == false) || (cooldown != 0))
		{
			return false;
		}
		else
		{
			cooldown = 10;
			offcooldown = false;
		}
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
		return mageRobes;
	}
	vector <Weapon> getWeaponProperties()
	{
		return items;
	}
	bool getvecFlag()
	{
		return vecFlag;
	}
};
