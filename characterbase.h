#pragma once
#include <iostream>
#include <string>
using namespace std;
class CharacterBase
{
private:
	string symbol;
	int moveset;
	int attackset;
	int attackrange;
	int moverange;
	int health;
	bool status;
	int reqPoints;
public:
	CharacterBase::CharacterBase()
	{
		//basic pawn unit
		symbol = "S";
		moveset = 0;
		moverange = 1;
		health = 100;
		status = true;
		reqPoints = 10;
	}
	//getters
	string getSymbol()
	{
		return symbol;
	}
	int getMoveset()
	{
		return moveset;
	}
	int getMoverange()
	{
		return moverange;
	}
	int getHealth()
	{
		return health;
	}
	bool getStatus()
	{
		return status;
	}
	int getReqpoints()
	{
		return reqPoints;
	}
	//setters
	void setSymbol(string i)
	{
		symbol = i;
	}
	void setMoveset(int i)
	{
		moveset = i;
	}
	void setMoverange(int i)
	{
		moverange = i;
	}
	void setHealth(int i)
	{
		health = i;
	}
	void setStatus(bool i)
	{
		status = i;
	}
	void setReqPoints(int i)
	{
		reqPoints = i;
	}
};