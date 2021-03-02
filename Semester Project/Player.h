#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
class Player
{
public:

	Player();
	~Player();
	void CharacterSetUp();
	void SetName(string Name1) { Name = Name1; };
	string GetName() { return Name; };
	//void SetLevel() { level = GetLevel(); };
	int GetLevel() {return level;};
	int GetHealth() { return health; };
	int GetStamina() { return stamina; };
	int GetSpeed() { return speed; };
	int GetStrength() { return strength; };
	int GetMoney() { return money; };
	char playermove(char move);
	void characterlocation();
	void craft(int& cr);
	void interact(int& x);
	void LevelUp();
	void GainExperience();
	void PerkChart();
	void useitem();

private:

	string Name;
	int health;
	int stamina;
	int speed;
	int strength;
	int attack;
	int currentexperience;
	int experienceneeded;
	int level;
	int money;
	int inventory[19][1];

	int perks[3][12];
};

#endif //PLAYER_H
