/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef NPCS_H
#define NPCS_H

#include <iostream>
using namespace std;

class NPCs
{
public:

	/*
*Preconditions -
*Postconditions -
*/
	NPCs();


/*
*Preconditions -
*Postconditions -
*/
	void SetNPCname() { Ncurrent = NPCname[Nnumber]; };

/*
*Preconditions -
*Postconditions -
*/
	string GetNPCname() { return Ncurrent; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPClevel(); //to be clear, in this early game dev, the villagers do not need any sort of stat, just gold.
	//However. I would love to make it so that they can accompany you in your adventures as I work on this code.

/*
*Preconditions -
*Postconditions -
*/
	int GetNPClevel() { return NPClevel; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPCstrength();

/*
*Preconditions -
*Postconditions -
*/
	int GetNPCstrength() { return NPCstrength; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPCstamina();

/*
*Preconditions -
*Postconditions -
*/
	int GetNPCstamina() { return NPCstamina; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPCspeed();

/*
*Preconditions -
*Postconditions -
*/
	int GetNPCspeed() { return NPCspeed; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPChealth();

/*
*Preconditions -
*Postconditions -
*/
	int GetNPChealth() { return NPChealth; };

/*
*Preconditions -
*Postconditions -
*/
	void SetNPCmoney();

/*
*Preconditions -
*Postconditions -
*/
	int GetNPCmoney() { return NPCmoney; };

/*
*Preconditions -
*Postconditions -
*/
	int trade(int& ams, int& am);

	/*
*Preconditions -
*Postconditions -
*/
	void SetInv();

	/*
*Preconditions -
*Postconditions -
*/
	void showitems();

	/*
*Preconditions -
*Postconditions -
*/
	void addremovegold(int g);

private:

	string NPCname[5] = {"Farmer", "Trader", "Healer", "Warrior", "Scholar"};
	string Ncurrent;
	int NPClevel;//Default 10 for everyone but warrior
	int NPCstrength;
	int NPCstamina;//These will be default 5 for everyone but the warrior.
	int NPCspeed;
	int NPCmoney;//Default 100 for everyone but Trader
	int NPChealth;//Default 120 for everyone but warrior.
	int Nnumber; // 0:Farmer, 1:Trader, 2:Healer, 3:Warrior, 4:Scholar
	int NPCinv[22];
	string items[22] = {/*0*/"Wood", /*1*/"Stone", /*2*/"Metal", /*3*/"Sword", /*4*/"Battleaxe", /*5*/"Warhammer", /*6*/"Hammer",
		/*7*/"Axe", /*8*/"Pickaxe", /*9*/"Shield", /*10*/"Knife", /*11*/"Food", /*12*/"Health Potion", /*13*/"Stat Boost Potion",
		/*14*/"Health Boost Potion", /*15*/"Cloth", /*16*/"Uncooked Food", /*17*/"Herbs", /*18*/"Helmet", /*19*/"Chest Plate",
		/*20*/"Leg Plating", /*21*/"Armored Boots" }; //Same as yours.
};

#endif //NPCS_H
