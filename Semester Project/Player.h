/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
class Player
{
public:

/*
*Preconditions -
*Postconditions -
*/
	Player();

/*
*Preconditions -
*Postconditions -
*/
	~Player();

/*
*Preconditions -
*Postconditions -
*/
	void CharacterSetUp();

	/*
*Preconditions -
*Postconditions -
*/
	void SetBeginningInv();

/*
*Preconditions -
*Postconditions -
*/
	void SetName(string Name1) { Name = Name1; };

/*
*Preconditions -
*Postconditions -
*/
	string GetName() { return Name; };

/*
*Preconditions -
*Postconditions -
*/
	void SetExperience(int exp) { currentexperience = exp; };

/*
*Preconditions -
*Postconditions -
*/
	int GetExperience() { return currentexperience; };

	/*
*Preconditions -
*Postconditions -
*/
	void SetExperienceNeeded(int exp) { experienceneeded = exp; };

/*
*Preconditions -
*Postconditions -
*/
	int ExperienceToNext() { return experienceneeded; };

/*
*Preconditions -
*Postconditions -
*/
	void SetLevel(int lvl) { level = lvl; };

/*
*Preconditions -
*Postconditions -
*/
	int GetLevel() {return level;};

/*
*Preconditions -
*Postconditions -
*/
	void SetHealth(int hlt) { health = hlt; };

/*
*Preconditions -
*Postconditions -
*/
	int GetHealth() { return health; };

/*
*Preconditions -
*Postconditions -
*/
	void SetMaxH(int mxhlt) { maxHealth = mxhlt; };

/*
*Preconditions -
*Postconditions -
*/
	int GetMaxH() { return maxHealth; };

/*
*Preconditions -
*Postconditions -
*/
	void SetStamina(int sta) { stamina = sta; };

/*
*Preconditions -
*Postconditions -
*/
	int GetStamina() { return stamina; };

/*
*Preconditions -
*Postconditions -
*/
	void SetSpeed(int spd) { speed = spd; };

/*
*Preconditions -
*Postconditions -
*/
	int GetSpeed() { return speed; };

/*
*Preconditions -
*Postconditions -
*/
	void SetStrength(int str) { strength = str; };

/*
*Preconditions -
*Postconditions -
*/
	int GetStrength() { return strength; };

/*
*Preconditions -
*Postconditions -
*/
	void SetArmor();

/*
*Preconditions -
*Postconditions -
*/
	int GetArmor() { return armor; };

/*
*Preconditions -
*Postconditions -
*/
	void SetMoney(int& mon) { money = mon; };

/*
*Preconditions -
*Postconditions -
*/
	int GetMoney() { return money; };

	/*
*Preconditions -
*Postconditions -
*/
	void SetExperience() {
		currentexperience = level * 50;
		experienceneeded = 50 + (level * 50); }

/*
*Preconditions -
*Postconditions -
*/
	void showcraft();

/*
*Preconditions -
*Postconditions -
*/
	void craft(int& item);

/*
*Preconditions -
*Postconditions -
*/
	void LevelUp();

/*
*Preconditions -
*Postconditions -
*/
	void GainExperience(int exp);

/*
*Preconditions -
*Postconditions -
*/
	void useitem(int use);

	/*
*Preconditions -
*Postconditions -
*/
	void effect(int use);

/*
*Preconditions -
*Postconditions -
*/
	void AddItem(int& add, int num);

/*
*Preconditions -
*Postconditions -
*/
	void ShowInv();

/*
*Preconditions -
*Postconditions -
*/
	void EquipItem(int& eq);

/*
*Preconditions -
*Postconditions -
*/
	void CombatItem();

/*
*Preconditions -
*Postconditions -
*/
	void GetAttacked(int atk);

/*
*Preconditions -
*Postconditions -
*/
	bool HasWeapon() { return (equipment[5] > 0); };

/*
*Preconditions -
*Postconditions -
*/
	void VillageItem(int& st, int& wo, int& met);

/*
*Preconditions -
*Postconditions -
*/
	void CreatedItem(int& st, int& wo, int& met);

/*
*Preconditions -
*Postconditions -
*/
	void GetInv(int inv[]);

/*
*Preconditions -
*Postconditions -
*/
	void GetEqp(int eqp[]);

/*
*Preconditions -
*Postconditions -
*/
	void SetInv(int inv[]);

/*
*Preconditions -
*Postconditions -
*/
	void SetEqp(int eqp[]);

/*
*Preconditions -
*Postconditions -
*/
	int trade();

/*
*Preconditions -
*Postconditions -
*/
	void addremovegold(int g);

private:

	string Name;
	int health, maxHealth;
	int stamina, speed, strength, armor;
	int currentexperience, experienceneeded, level;
	int money, inventory[22], equipment[6];//there are 22 items in total that you can have. there are 6 equipment slots
	//5 armor and one weapon. 1 helmet, 1 chest piece, 1 leg plating, 1 boots, 1 shield, and you can choose between sword, axe, hammer, etc.
	//another note. in equipment, the second number determines which kind of weapon is equipped
	string items[22] = {/*0*/"Wood", /*1*/"Stone", /*2*/"Metal", /*3*/"Sword", /*4*/"Battleaxe", /*5*/"Warhammer", /*6*/"Hammer",
		/*7*/"Axe", /*8*/"Pickaxe", /*9*/"Shield", /*10*/"Knife", /*11*/"Food", /*12*/"Health Potion", /*13*/"Stat Boost Potion", 
		/*14*/"Health Boost Potion", /*15*/"Cloth", /*16*/"Uncooked Food", /*17*/"Herbs", /*18*/"Helmet", /*19*/"Chest Plate",
		/*20*/"Leg Plating", /*21*/"Armored Boots"}; //Simple list for displaying what is in your inventory

	int x;//big map
	int y;
	int x1;//little map
	int y1;

	//int perks[3][6];
	//string perkchart[3][6]; //strength, speed, stamina. strength will have 6 perks you can unlock. must have them be at 3+ to get the first perk.
	//still working on perk chart, but I think that the first perk will be to add +15 to that stat, the second will be to have stronger attack
	//again, still working on this. May not have time to include anything with the perk chart
};

#endif //PLAYER_H

/* craftable items list
1. sword - need wood 2 metal cloth
2. battleaxe - need 2 wood metal cloth
3. warhammer - need 2 wood metal cloth
4. hammer - need wood metal
5. axe - need 2 wood metal
6. pickaxe - need 2 wood 2 metal
7. shield - need 3 wood metal cloth
8. knife - need metal cloth
9. food - need uncooked food wood
10. health potion - need food and herbs
11. stat boost - need wood 2 herbs
12. health boost - need wood, uncooked food, herbs
13. helmet - 2 metal
14. chest plate - 5 metal
15. leg plating - 4 metal
16. armored boots - 3 metal
*/