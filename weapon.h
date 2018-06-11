#pragma once
#include <iostream>
#include <string>
using namespace std;
class Weapon
{
private:
	string name;
	int damage;
	int magicDamage;
	int heal;
	int dmgrange;
	int healrange;
	bool healflag;
public:
	Weapon::Weapon()
	{
		name = "Base Sword";
		damage = 50;
		magicDamage = 0;
		heal = 0;
		dmgrange = 1;
		healrange = 0;
		healflag = false;
	}
	//getters
	string getName()
	{
		return name;
	}
	int getDamage()
	{
		return damage;
	}
	int getMagicdamage()
	{
		return magicDamage;
	}
	int getHeal()
	{
		return heal;
	}
	int getDmgrange()
	{
		return dmgrange;
	}
	int getHealRange()
	{
		return healrange;
	}
	bool getHealflag()
	{
		return healflag;
	}
	//setters
	void setName(string i)
	{
		name = i;
	}
	void setDamage(int i)
	{
		damage = i;
	}
	void setMagicdamage(int i)
	{
		magicDamage = i;
	}
	void setHeal(int i)
	{
		heal = i;
	}
	void setDmgrange(int i)
	{
		dmgrange = i;
	}
	void setHealrange(int i)
	{
		healrange = i;
	}
	void setHealflag(bool i)
	{
		healflag = i;
	}
};