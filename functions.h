#pragma once
#include "archer.h"
#include "necro.h"
#include "soldier.h"
#include "tank.h"
#include "support.h"
#include <ctime>

vector <int> archerAttack(Archer a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties.getDamage());
	foo.push_back(a.getWeaponProperties.getRangedamage());
	foo.push_back(a.getWeaponProperties.getMagicdamage());
	return foo;
}
vector <int> necroAttack(Necro a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties[0].getDamage());
	foo.push_back(a.getWeaponProperties[0].getRangedamage());
	foo.push_back(a.getWeaponProperties[0].getMagicdamage());
	return foo;
}
vector <int> supportAttack(Support a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties[0].getDamage());
	foo.push_back(a.getWeaponProperties[0].getRangedamage());
	foo.push_back(a.getWeaponProperties[0].getMagicdamage());
	return foo;
}
vector <int> tankAttack(Tank a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties.getDamage());
	foo.push_back(a.getWeaponProperties.getRangedamage());
	foo.push_back(a.getWeaponProperties.getMagicdamage());
	return foo;
}
vector <int> archerAttack(Archer a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties.getDamage());
	foo.push_back(a.getWeaponProperties.getRangedamage());
	foo.push_back(a.getWeaponProperties.getMagicdamage());
	return foo;
}
void reqPointMessage(int points)
{
	cout << "You currently have " << points << " requisition points." << endl << "Soldiers require 10 points."
		<< endl << "Hevy armor and archers require 30 points." << endl << "Mages require 50 points." << endl <<
		"Necromancers require 70 points." << endl;
}
int randNum(int min, int max)
{
	int x = rand() % min + max;
	return x;
}
int randBin()
{
	return (rand() % 2) - 1;
}