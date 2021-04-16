/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#include "NPCs.h"

NPCs::NPCs()//every time you play, there will be different villagers.
{
	srand(time(NULL));
	int npcn = rand() % 5 + 1;
	Nnumber = npcn;

	SetNPCname();
	SetNPCmoney();
	SetInv();
}

void NPCs::SetNPClevel()
{
	switch (Nnumber)
	{
	case 3: NPClevel = 25;
		break;
	default: NPClevel = 10;
		break;
	}
}

void NPCs::SetNPCstrength()
{
	switch (Nnumber)
	{
	case 3: NPCstrength = 10;
		break;
	default: NPCstrength = 5;
		break;
	}
}

void NPCs::SetNPCstamina()
{
	switch (Nnumber)
	{
	case 3: NPCstamina = 10;
		break;
	default: NPCstamina = 5;
		break;
	}
}

void NPCs::SetNPCspeed()
{
	switch (Nnumber)
	{
	case 3: NPCspeed = 10;
		break;
	default: NPCspeed = 5;
		break;
	}
}

void NPCs::SetNPChealth()
{
	switch (Nnumber)
	{
	case 3: NPChealth = 150;
		break;
	default: NPChealth = 120;
		break;
	}
}

void NPCs::SetNPCmoney()
{
	switch (Nnumber)
	{
	case 1: NPCmoney = 500;
		break;
	default: NPCmoney = 100;
		break;
	}
}

int NPCs::trade(int& ams, int& am)
{
	int t;
	cout << "Press the number that shows before the item you would like to purchase.\n";
	cin >> t;
	while (!(cin >> t))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> t;
	}
	cout << "They currently have " << NPCinv[t - 1] << " in stock of that item.\n";
	cout << "How much of that item would you like to purchase?\n";
	cin >> am;
	while (!(cin >> am))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> am;
	}
	while (am > NPCinv[t - 1])
	{
		cout << "There is not enough of that item.\nInput the amount you would like to buy again.\n";
		cin >> am;
		while (!(cin >> am))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Not a number. Try again.\n";
			cin >> am;
		}
	}
	switch (t)
	{
	case 0: break;
	case 1: 
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (1 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 2:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (2 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 3:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (3 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 4:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (15 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 5:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (15 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 6:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (15 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 7:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 8:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 9:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 10:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (20 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 11:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (15 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 12:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (5 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 13:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 14:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 15:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (10 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 16:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (1 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 17:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (3 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 18:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (3 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 19:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (25 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 20:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (50 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 21:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (30 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	case 22:
		NPCinv[t - 1] = NPCinv[t - 1] - am;
		ams = (25 * am);
		NPCmoney = (NPCmoney - ams);
		break;
	default: break;
	}
	ams *= -1;
	return t;
}

void NPCs::SetInv()
{
	for (int i = 0; i < 22; i++)
	{
		srand(time(NULL));
		int itno = rand() % 26;
		NPCinv[i] = itno;
	}
}

void NPCs::showitems()
{
	for (int i = 0; i < 22; i++)
	{
		if (NPCinv[i] > 0)
		{
			cout << i + 1 << '\t' << items[i] << '\t' << NPCinv[i] << endl;
		}
	}
}

void NPCs::addremovegold(int g)
{
	NPCmoney = NPCmoney + g;
}