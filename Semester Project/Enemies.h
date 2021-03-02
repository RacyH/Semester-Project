#ifndef ENEMIES_H
#define ENEMIES_H

#include <iostream>

using namespace std;

class Enemies
{
public:

	void SetEnemy();
	string GetEnemy() { return EnemyName; };
	void SetEHealth();
	int GetEHealth() {
		return ehealth;
	};
	void SetESpeed();
	int GetESpeed() { return espeed; };
	void SetEStamina();
	int GetEStamina() { return estamina; };
	void SetEStr();
	int GetEStr() {
		return estrength;
	};
	void SetEMaxLevel();
	int GetEMaxLevel() { return emax_level; };
	void SetELevel(); //What if I have the max level as an input from the enemy list?
	int GetELevel() { return elevel; };
	void SetExp();
	int GetExp() { return eexpgiven; };
	void EnemyAttack();
	void SetArmorRating();
	int GetArmorRating() { return earmor; };
	void SetLoot();
	void PlayerGetLoot();

private:

	string EnemyName;
	int earmor;
	int ehealth;
	int estamina;
	int espeed;
	int estrength;
	int eattack;
	int elevel;
	int eexpgiven;
	int emax_level;
	string loot[5];
	//Max number of loot items dropped is going to be 5. I think zero will be money, 1 through 4 items

	int enumber; //this is a way to better categorize enemies. The lower the number, the lower the max level, the lower the level when encountered, loot, etc.

};

#endif //ENEMIES_H