#include "NPCs.h"

void NPCs::SetNPClevel()
{
	switch (Nnumber)
	{
	case 3: NPClevel = 25;//Gonna have to figure this out in a bit.
		break;
	default: NPClevel = 10;
		break;
	}
}

void NPCs::SetNPCstrength()
{
	switch (Nnumber)
	{
	case 3: NPCstrength = 10;//Gonna have to figure this out in a bit.
		break;
	default: NPCstrength = 5;
		break;
	}
}

void NPCs::SetNPCstamina()
{
	switch (Nnumber)
	{
	case 3: NPCstamina = 10;//Gonna have to figure this out in a bit.
		break;
	default: NPCstamina = 5;
		break;
	}
}

void NPCs::SetNPCspeed()
{
	switch (Nnumber)
	{
	case 3: NPCspeed = 10;//Gonna have to figure this out in a bit.
		break;
	default: NPCspeed = 5;
		break;
	}
}

void NPCs::SetNPChealth()
{
	switch (Nnumber)
	{
	case 3: NPChealth = 150;//Gonna have to figure this out in a bit.
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

void NPCs::interact(int input)
{
	switch (input)
	{
	case 0: trade();//trade
		break;
	case 1: //leave interaction
		break;
	default: break;
	}
}

void NPCs::trade()
{

}