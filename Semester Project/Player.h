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


	void SetExperience(int& exp) { currentexperience = exp; };


	int GetExperience() { return currentexperience; };


	int ExperienceToNext() { return experienceneeded; };


	void SetLevel(int& lvl) { level = lvl; };


	int GetLevel() {return level;};


	void SetHealth(int& hlt) { health = hlt; };


	int GetHealth() { return health; };


	void SetMaxH(int mxhlt) { maxHealth = mxhlt; };


	int GetMaxH() { return maxHealth; };


	void SetStamina(int& sta) { stamina = sta; };


	int GetStamina() { return stamina; };


	void SetSpeed(int& spd) { speed = spd; };


	int GetSpeed() { return speed; };


	void SetStrength(int& str) { strength = str; };


	int GetStrength() { return strength; };


	void SetMoney(int& mon) { money = mon; };


	int GetMoney() { return money; };


	void showcraft();


	void craft(int& item);


	void interact(int& x);


	void LevelUp();


	void GainExperience();


	void PerkChart();


	void useitem(int& use);


	void AddItem(int& add, int num);


	void ShowInv();


	void EquipItem(int& eq);

private:

	string Name;
	int health, maxHealth;
	int stamina, speed, strength, attack;
	int currentexperience, experienceneeded, level;
	int money, inventory[22], equipment[6][1];//there are 19 items in total that you can have. there are 6 equipment slots
	//5 armor and one weapon. 1 helmet, 1 chest piece, 1 leg plating, 1 boots, 1 shield, and you can choose between sword, axe, hammer, etc.
	//another note. in equipment, the second number determines which kind of weapon is equipped
	string items[22] = {/*0*/"Wood", /*1*/"Stone", /*2*/"Metal", /*3*/"Sword", /*4*/"Battleaxe", /*5*/"Warhammer", /*6*/"Hammer",
		/*7*/"Axe", /*8*/"Pickaxe", /*9*/"Shield", /*10*/"Knife", /*11*/"Food", /*12*/"Health Potion", /*13*/"Stat Boost Potion", 
		/*14*/"Health Boost Potion", /*15*/"Cloth", /*16*/"Uncooked Food", /*17*/"Herbs", /*18*/"Helmet", /*19*/"Chest Piece",
		/*20*/"Leg Plating", /*21*/"Armored Boots"}; //Simple list for displaying what is in your inventory

	int x;//big map
	int y;
	int x1;//little map
	int y1;

	int perks[3][6];
	string perkchart[3][6]; //strength, speed, stamina. strength will have 6 perks you can unlock. must have them be at 3+ to get the first perk.
	//still working on perk chart, but I think that the first perk will be to add +15 to that stat, the second will be to have stronger attack
	//again, still working on this.
};

#endif //PLAYER_H
