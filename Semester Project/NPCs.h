#ifndef NPCS_H
#define NPCS_H

#include <iostream>
using namespace std;

class NPCs
{
public:

	void SetNPCname();
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

	string GetNPCname() { return NPCname; };



private:

	string NPCname;
	int NPClevel;
	int NPCstrength;
	int NPCstamina;
	int NPCspeed;
	int NPCmoney;
	int NPChealth;
};

#endif //NPCS_H
