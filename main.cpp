#include "archer.h"
#include "necro.h"
#include "soldier.h"
#include "tank.h"
#include "support.h"
#include "functions.h"
#include <iostream>
#include <string>
using namespace std;
#define GAMEDIMENSIONS 25
int main()
{
	srand(time(NULL));
	bool flag = false;
	int reqPoints = 0;
	int difficultyLevel = 0;
	double enemyHealthScale = 1, enemyAttackScale = 1;
	vector <Archer> playerArchers;
	vector <Archer> enemyArchers;
	vector <Tank> playerTanks;
	vector <Tank> enemyTanks;
	vector <Soldier> playerSoldiers;
	vector <Soldier> enemySoldiers;
	vector <Support> playerSupports;
	vector <Support> enemySupports;
	vector <Necro> playerNecros;
	vector <Necro> enemyNecros;
	string obstacleFlag = "";
	int obstacleLevel = 0;
	cout << "Welcome to the game!" << endl;
	system("pause");
	cout << "Select your difficulty:" << endl << "\t1.) Easy" << endl << "\t2.) Normal" << endl << "\t3.) Hard" 
		<< endl << "\t4.) Very Hard" << endl;
	cin >> difficultyLevel;
	switch (difficultyLevel)
	{
	case 1:
		enemyHealthScale = .5;
		enemyAttackScale = .5;
		break;
	case 2:
		break;
	case 3:
		enemyHealthScale = 1.5;
		enemyAttackScale = 1.5;
		break;
	case 4:
		enemyHealthScale = 2;
		enemyAttackScale = 2;
		break;
	}
	system("cls");
	cout << "How many requisition points do you want to use?" << endl;
	cin >> reqPoints;
	system("cls");
	while (flag == false)
	{
		Archer tempArcher;
		Soldier tempSoldier;
		Tank tempTank;
		Support tempSupport;
		Necro tempNecro;
		int numSoldiers = 0, numArchers = 0, numTanks = 0, numSupports = 0, numNecros = 0, total = 0;
		reqPointMessage(reqPoints);
		cout << "How many soldiers do you want? Each costs 10 points." << endl;
		cin >> numSoldiers;
		for (int i = 0; i < numSoldiers; i++)
		{
			playerSoldiers.push_back(tempSoldier);
			enemySoldiers.push_back(tempSoldier);
		}
		system("cls");
		reqPointMessage(reqPoints);
		cout << "How many archers do you want? Each costs 30 points." << endl;
		cin >> numArchers;
		for (int i = 0; i < numArchers; i++)
		{
			playerArchers.push_back(tempArcher);
			enemyArchers.push_back(tempArcher);
		}
		system("cls");
		reqPointMessage(reqPoints);
		cout << "How much heavy armor do you want? Each costs 30 points." << endl;
		cin >> numTanks;
		for (int i = 0; i < numTanks; i++)
		{
			playerTanks.push_back(tempTank);
			enemyTanks.push_back(tempTank);
		}
		system("cls");
		reqPointMessage(reqPoints);
		cout << "How many mages do you want? Each costs 50 points." << endl;
		cin >> numSupports;
		for (int i = 0; i < numSupports; i++)
		{
			playerSupports.push_back(tempSupport);
			enemySupports.push_back(tempSupport);
		}
		system("cls");
		reqPointMessage(reqPoints);
		cout << "How many necromancers do you want? Each costs 70 points." << endl;
		cin >> numNecros;
		for (int i = 0; i < numNecros; i++)
		{
			playerNecros.push_back(tempNecro);
		}
		system("cls");
		total = numSoldiers * 10 + numArchers * 30 + numTanks * 30 + numSupports * 50 + numNecros * 70;
		if (total <= reqPoints)
		{
			flag = true;
		}
		else
		{
			playerTanks.clear();
			playerSoldiers.clear();
			playerArchers.clear();
			playerNecros.clear();
			playerSupports.clear();
			enemyTanks.clear();
			enemySoldiers.clear();
			enemyArchers.clear();
			enemyNecros.clear();
			enemySupports.clear();
			cout << "Too many units, try again." << endl;
			system("pause");
			system("cls");
		}
	}
	vector <vector <string>> gameGrid;
	vector <string> gridTopRow;
	gridTopRow.push_back("");
	for (int i = 1; i < GAMEDIMENSIONS; i++)
	{
		gridTopRow.push_back(to_string(i));
	}
	gameGrid.push_back(gridTopRow);
	for (int i = 1; i < GAMEDIMENSIONS + 1; i++)
	{
		vector <string> gameGridRow;
		gameGridRow.push_back(to_string(i));
		for (int x = 0; x < GAMEDIMENSIONS; x++)
		{
			gameGridRow.push_back(string() + char(250));
		}
		gameGrid.push_back(gameGridRow);
	}
	//!!!!!!remember game grid starts at (1,1)!!!!!!
	cout << "Randomized obstacles? (y/n)" << endl;
	cin >> obstacleFlag;
	if (obstacleFlag == "y")
	{

	}

}