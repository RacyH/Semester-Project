/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef ENEMIES_H
#define ENEMIES_H

#include <iostream>
#include <time.h>

using namespace std;

class Enemies
{
public:

	/*
*Preconditions -
*Postconditions -
*/
	Enemies(int no, int plev);

	/*
*Preconditions -
*Postconditions -
*/
	~Enemies();

/*
*Preconditions - 
*Postconditions - 
*/
	void SetEnemy(int enu) { ecurrent = EnemyName[enu]; enumber = enu; };

/*
*Preconditions -
*Postconditions -
*/
	string GetEnemy() { return ecurrent; };

	/*
*Preconditions -
*Postconditions -
*/
	int GetENumber() { return enumber; };

/*
*Preconditions -
*Postconditions -
*/
	void SetEHealth();

/*
*Preconditions -
*Postconditions -
*/
	int GetEHealth() { return ehealth; };

/*
*Preconditions -
*Postconditions -
*/
	void SetESpeed();

/*
*Preconditions -
*Postconditions -
*/
	int GetESpeed() { return espeed; };

/*
*Preconditions -
*Postconditions -
*/
	void SetEStamina();

/*
*Preconditions -
*Postconditions -
*/
	int GetEStamina() { return estamina; };

/*
*Preconditions -
*Postconditions -
*/
	void SetEStr();

/*
*Preconditions -
*Postconditions -
*/
	int GetEStr() { return estrength; };

/*
*Preconditions -
*Postconditions -
*/
	void SetEMaxLevel();

/*
*Preconditions -
*Postconditions -
*/
	int GetEMaxLevel() { return emax_level; };

/*
*Preconditions -
*Postconditions -
*/
	void SetELevel(int plvl); //What if I have the max level as an input from the enemy list?

/*
*Preconditions -
*Postconditions -
*/
	int GetELevel() { return elevel; };

/*
*Preconditions -
*Postconditions -
*/
	void SetExp();

/*
*Preconditions -
*Postconditions -
*/
	int GetExp() { return eexpgiven; };

/*
*Preconditions -
*Postconditions -
*/
	int EnemyAttack();

/*
*Preconditions -
*Postconditions -
*/
	void SetArmorRating();

/*
*Preconditions -
*Postconditions -
*/
	int GetArmorRating() { return earmor; };

/*
*Preconditions -
*Postconditions -
*/
	void SetLoot();

/*
*Preconditions -
*Postconditions -
*/
	void PlayerGetLoot(int& ino, int& amt, int& g);

/*
*Preconditions -
*Postconditions -
*/
	void GetAttacked(int att);

	/*
*Preconditions -
*Postconditions -
*/
	void DeathByFlee();

	/*
*Preconditions -
*Postconditions -
*/
	void EHUD();

private:

	string EnemyName[13] = { "Chicken", "Rat", "Hedgehog", "Wolf", "Deer", "Bear", "Goblin", "Orc", "Dwarf", "Lion", "Witch", "Demon", "Dragon" };
	string ecurrent;
	int earmor, ehealth, estamina, espeed, estrength, eattack, elevel, eexpgiven, emax_level;
	int itemno, amount, gold; //This, with the eexpgiven above determine the loot the player gets when an enemy is killed.
	//string loot[5];
	//Max number of loot items dropped is going to be 5. I think zero will be money, 1 through 4 items

	int enumber; //this is a way to better categorize enemies. The lower the number, the lower the max level, the lower the level when encountered, loot, etc.
	//The different kinds of creatures are listed above.
};

#endif //ENEMIES_H