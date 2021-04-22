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
*Preconditions - Requires Enemies.h and Enemies.cpp. Requires iostream Requires SetEnemy(), SetEMaxLevel(), SetELevel(), SetEHealth,
* SetESpeed(), SetEStamina(), SetEStr(), EnemyAttack(), SetExp(), SetLoot(), and SetArmorRating() are working properly.
* Requires an input.
*Postconditions - Creates the Enemy based on input.
*/
	Enemies(int no, int plev);

	/*
*Preconditions - Requires iostream is loaded.
*Postconditions - Resets the Enemy stats to 0.
*/
	~Enemies();

/*
*Preconditions - Requires an input. Requires iostream. Requires enumber and ecurrent are variables that can have values set to them.
*Postconditions - Sets the enemies enumber and their name.
*/
	void SetEnemy(int enu) { ecurrent = EnemyName[enu]; enumber = enu; };

/*
*Preconditions - Requires iostream. Requires ecurrent to have a string saved in it.
*Postconditions - Returns the string found in ecurrent.
*/
	string GetEnemy() { return ecurrent; };

/*
*Preconditions - Requires iostream. Requires enumber to have an int value stored in it.
*Postconditions - Returns the enumber.
*/
	int GetENumber() { return enumber; };

/*
*Preconditions - Requires iostream. Requires enumber and elevel have values. Requires ehealth to be able to have an integer set to it.
*Postconditions - Sets the Enemy's health based on level and enumber.
*/
	void SetEHealth();

/*
*Preconditions - Requires iostream. Requires ehealth has a value in it.
*Postconditions - Returns ehealth.
*/
	int GetEHealth() { return ehealth; };

/*
*Preconditions - Requires iostream. Requires enumber and elevel have values saved in them. Requires espeed to be a settable variable.
*Postconditions - Sets the espeed.
*/
	void SetESpeed();

/*
*Preconditions - Requires iostream. Requires espeed to have a saved int value.
*Postconditions - Returns espeed.
*/
	int GetESpeed() { return espeed; };

/*
*Preconditions - Requires iostream. Requires enumber and elevel have values saved in them. Requires estamina to be a settable variable.
*Postconditions - Sets estamina.
*/
	void SetEStamina();

/*
*Preconditions - Requires iostream. Requires estamina to have a saved int value.
*Postconditions - Returns estamina.
*/
	int GetEStamina() { return estamina; };

/*
*Preconditions - Requires iostream. Requires enumber and elevel have values saved in them. Requires estrength to be a settable variable.
*Postconditions - Sets estrength.
*/
	void SetEStr();

/*
*Preconditions - Requires iostream. Requires estrength to have a saved int value.
*Postconditions - Returns estrength.
*/
	int GetEStr() { return estrength; };

/*
*Preconditions - Requires iostream. Requires enumber has a value saved in it. Requires emax_level to be a settable variable.
*Postconditions - Sets emax_level
*/
	void SetEMaxLevel();

/*
*Preconditions - Requires iostream. Requires emax_level to have an int value saved.
*Postconditions - Returns emax_level.
*/
	int GetEMaxLevel() { return emax_level; };

/*
*Preconditions - Requires iosteam. Requires input. Requires emax_level be set. Requires elevel to be a settable variable.
*Postconditions - Sets elevel based on input.
*/
	void SetELevel(int plvl); //What if I have the max level as an input from the enemy list?

/*
*Preconditions - Requires iostream. Requires elevel has a saved int value.
*Postconditions - Returns elevel.
*/
	int GetELevel() { return elevel; };

/*
*Preconditions - Requires iostream. Requires enumber has a saved int value. Requires eexpgiven is a settable int variable.
*Postconditions - Sets eexpgiven.
*/
	void SetExp();

/*
*Preconditions - Requires iostream. Requires eexpgiven has a saved int value.
*Postconditions - Returns eexpgiven.
*/
	int GetExp() { return eexpgiven; };

/*
*Preconditions - Requires iostream. Requires estrength has a saved int value. Requires eattack is a settable int variable.
*Postconditions - Sets and returns eattack.
* NOTE*** This function could have been avoided, but I wanted to keep it so that
* I could use it in later versions of this game.
*/
	int EnemyAttack();

/*
*Preconditions - Requires iostream. Requires elevel has a int value stored to it. Requires earmor is a settable int variable.
*Postconditions - Sets earmor.
* NOTE*** Again, used in later versions of the game.
*/
	void SetArmorRating();

/*
*Preconditions - Requires iostream. Requires earmor has an int value.
*Postconditions - Returns earmor.
*/
	int GetArmorRating() { return earmor; };

/*
*Preconditions - Requires iostream. Requires time.h. Requires itemno, amount, and gold are settable
* int variables.
*Postconditions - Sets gold, itemno, and amount.
*/
	void SetLoot();

/*
*Preconditions - Requires iostream. Requires reference input. Requires itemno, amount, and gold have int values set to them.
*Postconditions - Alters the input to equal itemno, amount, and gold.
*/
	void PlayerGetLoot(int& ino, int& amt, int& g);

/*
*Preconditions - Requires iostream. Requires SetLoot() function works. Requires input. Requires ehealth has a saved int value.
*Postconditions - Subtracts input from ehealth. If ehealth reaches or falls below zero, calls SetLoot() function.
*/
	void GetAttacked(int att);

/*
*Preconditions - Requires iostream. Requires ehealth.
*Postconditions - Sets ehealth to 0.
*/
	void DeathByFlee();

/*
*Preconditions - Requires iostream. Requires std library be loaded. Requires ecurrent, elevel, and ehealth to have saved values.
*Postconditions - Outputs basic information about the enemy to the screen.
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