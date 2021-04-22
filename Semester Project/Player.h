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
*Preconditions - Requires iostream. Requires SetBeginningInv(). Requires Name, health, maxHealth, stamina,
* strength, speed, level, currentexperience, experienceneeded.
*Postconditions - Sets the above to their default default. Runs SetBeginningInv().
*/
	Player();

/*
*Preconditions - Requires iostream. Requires Name, health, maxHealth, stamina,
* strength, speed, level, currentexperience, experienceneeded.
*Postconditions - Resets the above to their default.
*/
	~Player();

/*
*Preconditions - Requires iostream and std library. Requires strength, stamina, speed, health, maxHealth,
* experienceneeded, level.
*Postconditions - Adds 1 to each of strength, stamina, speed. Sets health to 100, experienceneeded to 50. Sets maxHealth to health.
* Then it prompts the user to choose which of strength, stamina, speed they would like to add 1 point to, five times.
*/
	void CharacterSetUp();

	/*
*Preconditions - Requires iostream. Requires inventory[], equipment[].
*Postconditions - Sets the values of all items in both arrays to 0.
*/
	void SetBeginningInv();

/*
*Preconditions - Requires iostream. Requires Name. Requires input.
*Postconditions - Sets Name to the input.
*/
	void SetName(string Name1) { Name = Name1; };

/*
*Preconditions - Requires iostream. Requires Name.
*Postconditions - Returns the string value of Name.
*/
	string GetName() { return Name; };

/*
*Preconditions - Requires iostream. Requires currentexperience. Requires input.
*Postconditions - Sets currentexperience to input.
*/
	void SetExperience(int exp) { currentexperience = exp; };

/*
*Preconditions - Requires iostream. Requires currentexperience.
*Postconditions - Returns the int value of currentexperience.
*/
	int GetExperience() { return currentexperience; };

/*
*Preconditions - Requires iostream. Requires experienceneeded. Requires input.
*Postconditions - Sets experienceneeded to input.
*/
	void SetExperienceNeeded(int exp) { experienceneeded = exp; };

/*
*Preconditions - Requires iostream. Requires experienceneeded.
*Postconditions - Returns the int value of experienceneeded.
*/
	int ExperienceToNext() { return experienceneeded; };

/*
*Preconditions - Requires iostream. Requires level. Requires input.
*Postconditions - Sets level to input.
*/
	void SetLevel(int lvl) { level = lvl; };

/*
*Preconditions - Requires iostream. Requires level.
*Postconditions - Returns the int value of level.
*/
	int GetLevel() {return level;};

/*
*Preconditions - Requires iostream. Requires health. Requires input.
*Postconditions - Sets health as input.
*/
	void SetHealth(int hlt) { health = hlt; };

/*
*Preconditions - Requires iostream. Requires health.
*Postconditions - Returns int value of health.
*/
	int GetHealth() { return health; };

/*
*Preconditions - Requires iostream. Requires maxHealth. Requires input.
*Postconditions - Sets maxHealth to input.
*/
	void SetMaxH(int mxhlt) { maxHealth = mxhlt; };

/*
*Preconditions - Requires iostream. Requires maxHealth.
*Postconditions - Returns int value of maxHealth.
*/
	int GetMaxH() { return maxHealth; };

/*
*Preconditions - Requires iostream. Requires stamina. Requires input.
*Postconditions - Sets stamina to input.
*/
	void SetStamina(int sta) { stamina = sta; };

/*
*Preconditions - Requires iostream. Requires stamina.
*Postconditions - Returns int value of stamina.
*/
	int GetStamina() { return stamina; };

/*
*Preconditions - Requires iostream. Requires speed. Requires input.
*Postconditions - Sets speed to input.
*/
	void SetSpeed(int spd) { speed = spd; };

/*
*Preconditions - Requires iostream. Requires speed.
*Postconditions - Returns int value of speed.
*/
	int GetSpeed() { return speed; };

/*
*Preconditions - Requires iostream. Requires strength. Requires input.
*Postconditions - Sets strength to input.
*/
	void SetStrength(int str) { strength = str; };

/*
*Preconditions - Requires iostream. Requires strength.
*Postconditions - Returns int value of strength.
*/
	int GetStrength() { return strength; };

/*
*Preconditions - Requires iostream. Requires armor. Requires equipment[].
*Postconditions - Sets armor to an int value based on the values inside of the different parts of equipment[].
*/
	void SetArmor();

/*
*Preconditions - Requires iostream. Requires armor.
*Postconditions - Returns int value of armor.
*/
	int GetArmor() { return armor; };

/*
*Preconditions - Requires iostream. Requires money. Requires input.
*Postconditions - Sets money to input.
*/
	void SetMoney(int& mon) { money = mon; };

/*
*Preconditions - Requires iostream. Requirs money.
*Postconditions - Returns input value of money.
*/
	int GetMoney() { return money; };

	/*
*Preconditions - Requires iostream. Requires currentexperience, experienceneeded, level.
*Postconditions - Sets currentexperience and experienceneeded based on value of level.
* NOTE*** This is not needed for this right now. I was thinking of implementing something, but won't go into details.
*/
	void SetExperience() {
		currentexperience = level * 50;
		experienceneeded = 50 + (level * 50); }

/*
*Preconditions - Requires iostream and std library. Requires inventory[]. Requires craft().
*Postconditions - Outputs items that are craftable by the user given the number of items in their inventory. Then based on an input,
* runs craft(), based on their input.
*/
	void showcraft();

/*
*Preconditions - Requiers iostream and std library. Requires inventory[]. Requirs input.
*Postconditions - Based on input, subtracts the necessary items from the inventory[] and adds the correct items to inventory[].
* Alternatively, if they have chosen an input that does not work, it will display an error message.
*/
	void craft(int& item);

/*
*Preconditions - Requires iostream and std library. Requires level, strength, speed, stamina, maxHealth, health, experienceneeded.
*Postconditions - Adds 1 to level, strength, speed, stamina. Adds 10 to maxHealth, and sets health to maxHealth. Increases experienceneeded by 50.
* Then allows the user to choose one of strength, speed, stamina, maxHealth, to add one to strength, speed, stamina, or 10 to maxHealth.
*/
	void LevelUp();

/*
*Preconditions - Requires iostream. Requires currentexperience, experienceneeded. Requires LevelUp(). Requires input.
*Postconditions - Adds input to currentexperience. If currentexperience >= experienceneeded, then runs LevelUp() on loop until
* that condition is no longer met.
* NOTE*** I have had a few run ins with the dragon, which shits out a lot of experience, enough to level up like, 10 times,
* and it only leveled me up once. So that is an issue.
*/
	void GainExperience(int exp);

/*
*Preconditions - Requires iostream and std library. Requires inventory[]. Requires effect(). Requires input.
*Postconditions - Based on input, determines if the item selected is usable, if it is, then it detracts one from
* inventory[], then runs effect() with the item number as its input.
* NOTE*** May need to subtract one from input. Have never used an item in the game.
*/
	void useitem(int use);

/*
*Preconditions - Requires iostream. Requires health, maxHealth. Requires input.
*Postconditions - Depending on input, and on current health compared to maxHealth, increases health, or does nothing.
* NOTE*** Some usable items do nothing. Time is of the essence.
*/
	void effect(int use);

/*
*Preconditions - Requires iostream. Requires inventory[]. Requires 2 inputs.
*Postconditions - Adds the number of items(second input) to inventory[first input].
*/
	void AddItem(int& add, int num);

/*
*Preconditions - Requires iostream and std library.
*Postconditions - Outputs all items in the inventory, if there is more than 0 of that item.
*/
	void ShowInv();

/*
*Preconditions - Requires iostream and std library. Requires inventory[], equipment[]. Requires input.
*Postconditions - Determines which item is trying to be equipped based on input. Then removes it from the inventory[]
* and adds it to equipment[]. Or outputs an error message.
*/
	void EquipItem(int& eq);

/*
*Preconditions - Requires iostream and std library. Requires inventory[]. Requires useitem().
*Postconditions - Shows usable items in the users inventory next to a number. Prompts user for input based on what is in their inventory.
* Runs useitem() based on that input.
*/
	void CombatItem();

/*
*Preconditions - Requires iostream. Requires health. Requires input.
*Postconditions - Subtracts input from health.
*/
	void GetAttacked(int atk);

/*
*Preconditions - Requires iostream. Requires equipment[5].
*Postconditions - Returns whether or not there is an int greater than 0 in equipment[5].
*/

	bool HasWeapon() { return (equipment[5] > 0); };

/*
*Preconditions - Requires iostream. Requires inventory[]. Requires input.
*Postconditions - Changes the input to the number in the inventory[] to the specific place that that input is trying to obtain the number of.
*/
	void VillageItem(int& st, int& wo, int& met);

/*
*Preconditions - Requires iostream. Requires inventory[]. Requires 3 inputs.
*Postconditions - Sets the corresponding inventory[] slots to the inputs.
*/
	void CreatedItem(int& st, int& wo, int& met);

/*
*Preconditions - Requires iostream. Requires inventory[]. Requires input[].
*Postconditions - Sets the input[] to inventory[] slot by slot.
*/
	void GetInv(int inv[]);

/*
*Preconditions - Requires iostream. Requires equipment[]. Requires input[].
*Postconditions - Sets the input[] to equipment[] slot by slot.
*/
	void GetEqp(int eqp[]);

/*
*Preconditions - Requires iostream. Requires inventory[]. Requires input[].
*Postconditions - Sets the inventory[] to input[] slot by slot.
*/
	void SetInv(int inv[]);

/*
*Preconditions - Requires iostream. Requires equipment[]. Requires input[].
*Postconditions - Sets the equipment[] to input[] slot by slot.
*/
	void SetEqp(int eqp[]);

/*
*Preconditions - Requires iostream and std library. Requires inventory[], money.
*Postconditions - Prompts the user to sell an item. Upon input, it asks how many they would like to sell. It then subtracts
* that many of that item from it's corresponding inventory[] slot, and adds that particular items value to money.
* Returns the negative value of that item, so it can be deleted from the villagers gold.
*/
	int trade();

/*
*Preconditions - Requires iostream. Requires money. Requires input.
*Postconditions - Adds input to money.
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