#pragma once
#include "archer.h"
#include "necro.h"
#include "soldier.h"
#include "tank.h"

vector <int> archerAttack(Archer a)
{
	vector <int> foo;
	foo.push_back(a.getWeaponProperties.getDamage());
	foo.push_back(a.getWeaponProperties.getRangedamage());
	foo.push_back(a.getWeaponProperties.getMagicdamage());
	return foo;
}