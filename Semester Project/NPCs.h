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
*Preconditions - Requires iostream and time.h. Requires Nnumber. Requires SetNPCname(), SetNPCmoney(), and SetInv() functions.
*Postconditions - Sets a randomly generated Nnumber. Runs the functions.
* NOTE*** There is an issue where the villagers are all the same. Will fix in later versions.
*/
	NPCs();


/*
*Preconditions - Requires iostream. Requires Ncurrent, NPCname[], and Nnumber.
*Postconditions - Sets the value of Ncurrent based on the string value inside of NPCname[] based on the integer
* that has been assigned to Nnumber.
*/
	void SetNPCname() { Ncurrent = NPCname[Nnumber]; };

/*
*Preconditions - Requires iostream. Requires Ncurrent.
*Postconditions - Returns the string value of Ncurrent.
*/
	string GetNPCname() { return Ncurrent; };

/*
* The following several things do not need to be included. They are here for viewing purposes, but they serve no functional purpose,
* so they have been commented out.
* 
*Preconditions - Reqiuires iostream. Requires Nnumber and NPClevel.
*Postconditions - Sets NPClevel based on the Nnumber.

	void SetNPClevel(); //to be clear, in this early game dev, the villagers do not need any sort of stat, just gold.
	//However. I would love to make it so that they can accompany you in your adventures as I work on this code.
	
/*
*Preconditions - 
*Postconditions - 

	int GetNPClevel() { return NPClevel; };

/*
*Preconditions - The following several functions were not needed for this early version.
*Postconditions -

	void SetNPCstrength();

/*
*Preconditions -
*Postconditions -

	int GetNPCstrength() { return NPCstrength; };

/*
*Preconditions -
*Postconditions -

	void SetNPCstamina();

/*
*Preconditions -
*Postconditions -

	int GetNPCstamina() { return NPCstamina; };

/*
*Preconditions -
*Postconditions -

	void SetNPCspeed();

/*
*Preconditions -
*Postconditions -

	int GetNPCspeed() { return NPCspeed; };

/*
*Preconditions -
*Postconditions -

	void SetNPChealth();

/*
*Preconditions -
*Postconditions -

	int GetNPChealth() { return NPChealth; };

/*
*Preconditions - Requires iostream. Requires Nnumber and NPCmoney.
*Postconditions - Sets NPCmoney based on Nnumber.
*/
	void SetNPCmoney();

/*
*Preconditions - Requires iostream. Requiers NPCmoney.
*Postconditions - Returns the int value of NPCmoney.
*/
	int GetNPCmoney() { return NPCmoney; };

/*
*Preconditions - Requires iostream and std library. Requires input. Requires NPCinv[], NPCmoney.
*Postconditions - Changes the input from function. Prompts user for input based on things it has outputted to the screen.
* Returns a value for use in taking things out of the inventory of the Player1 object (in Game class).
*/
	int trade(int& ams, int& am);

/*
*Preconditions - Requires iostream and time.h. Requires NPCinv[].
*Postconditions - Sets the values to all of the array items in NPCinv[].
* NOTE*** Currently, it sets all of the values of all of the items to the same thing.
*/
	void SetInv();

/*
*Preconditions - Requires iostream and std library. Requires NPCinv[].
*Postconditions - Outputs a number, the items in NPCinv[], and their value, that are above 0.
*/
	void showitems();

/*
*Preconditions - Requires iostream. Requires input. Requires NPCmoney.
*Postconditions - Adds the inputted amount to NPCmoney.
*/
	void addremovegold(int g);

private:

	string NPCname[5] = {"Farmer", "Trader", "Healer", "Warrior", "Scholar"};
	string Ncurrent;
	/*int NPClevel;//Default 10 for everyone but warrior
	int NPCstrength;
	int NPCstamina;//These will be default 5 for everyone but the warrior.
	int NPCspeed;
	int NPChealth;//Default 120 for everyone but warrior.*/
	int NPCmoney;//Default 100 for everyone but Trader
	int Nnumber; // 0:Farmer, 1:Trader, 2:Healer, 3:Warrior, 4:Scholar
	int NPCinv[22];
	string items[22] = {/*0*/"Wood", /*1*/"Stone", /*2*/"Metal", /*3*/"Sword", /*4*/"Battleaxe", /*5*/"Warhammer", /*6*/"Hammer",
		/*7*/"Axe", /*8*/"Pickaxe", /*9*/"Shield", /*10*/"Knife", /*11*/"Food", /*12*/"Health Potion", /*13*/"Stat Boost Potion",
		/*14*/"Health Boost Potion", /*15*/"Cloth", /*16*/"Uncooked Food", /*17*/"Herbs", /*18*/"Helmet", /*19*/"Chest Plate",
		/*20*/"Leg Plating", /*21*/"Armored Boots" }; //Same as yours.
};

#endif //NPCS_H
