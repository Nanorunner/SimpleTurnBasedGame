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
		//heals
		Weapon healItem;
		healItem.setDamage(0);
		healItem.setHeal(100);
		healItem.setName("Staff of Healing");
		healItem.setDmgrange(0);
		healItem.setHealflag(true);
		healItem.setHealrange(2);
		//damage
		Weapon staff;
		staff.setName("Staff of Damage");
		staff.setDamage(0);
		staff.setMagicdamage(150);
		staff.setDmgrange(3);
		//support
		Weapon bufftastic;
		bufftastic.setName("Inspire");
		bufftastic.setDamage(0);
		bufftastic.setDmgrange(0);
		
		base.setSymbol("M");
		currentHealth = base.getHealth();
		base.setStatus(true);
		base.setReqPoints(50);
		base.setHealth(200);
		items.push_back(staff);
		items.push_back(healItem);
		items.push_back(bufftastic);
		mageRobes.setPhysicalResistance(.20);
		mageRobes.setRangedResistance(.20);
		mageRobes.setMagicResistance(.50);
		vecFlag = true;
		cooldown = 0;
		offcooldown = true;
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
			cooldown = 5;
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
