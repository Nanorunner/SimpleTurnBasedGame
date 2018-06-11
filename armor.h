#pragma once
#include <iostream>
#include <string>
using namespace std;
class Armor
{
private:
	string name;
	double physicalResistance;
	double rangedResistance;
	double magicResistance;
public:
	Armor::Armor()
	{
		name = "Basic Leathers";
		physicalResistance = .10;
		rangedResistance = .10;
		magicResistance = .10;
	}
	//getters
	string getName()
	{
		return name;
	}
	double getPhysicalResistance()
	{
		return physicalResistance;
	}
	double getRangedResistance()
	{
		return rangedResistance;
	}
	double getMagicResistance()
	{
		return magicResistance;
	}
	//setters
	void setName(string i)
	{
		name = i;
	}
	void setPhysicalResistance(double i)
	{
		physicalResistance = i;
	}
	void setRangedResistance(double i)
	{
		rangedResistance = i;
	}
	void setMagicResistance(double i)
	{
		magicResistance = i;
	}
};