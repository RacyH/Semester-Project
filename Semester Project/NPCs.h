#ifndef NPCS_H
#define NPCS_H

#include <iostream>
using namespace std;

class NPCs
{
public:


	void SetNPCname() { Ncurrent = NPCname[Nnumber]; };


	string GetNPCname() { return Ncurrent; };


	void SetNPClevel();


	int GetNPClevel() { return NPClevel; };


	void SetNPCstrength();


	int GetNPCstrength() { return NPCstrength; };


	void SetNPCstamina();


	int GetNPCstamina() { return NPCstamina; };


	void SetNPCspeed();


	int GetNPCspeed() { return NPCspeed; };


	void SetNPChealth();


	int GetNPChealth() { return NPChealth; };


	void SetNPCmoney();


	int GetNPCmoney() { return NPCmoney; };


	void interact(int input);


	void trade();


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
};

#endif //NPCS_H
