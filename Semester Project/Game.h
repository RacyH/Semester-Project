/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Windows.h>
#include <time.h> 

#include "Player.h"
#include "Save.h"
#include "Map.h"
#include "Enemies.h"
#include "NPCs.h"

class Game
{
public:

/*
*Preconditions -
*Postconditions -
*/
	Game();
	//Game(const string& filename); //this is if I have time later. easier than hardcoding the map

/*
*Preconditions -
*Postconditions -
*/
	void run();

/*
*Preconditions -
*Postconditions -
*/
	void handleinput(char input);

/*
*Preconditions -
*Postconditions -
*/
	void openmap();

/*
*Preconditions -
*Postconditions -
*/
	void setdefmap();

/*
*Preconditions -
*Postconditions -
*/
	void evalpos(int& something);

/*
*Preconditions -
*Postconditions -
*/
	void evalmove();

/*
*Preconditions -
*Postconditions -
*/
	void HUD();

/*
*Preconditions -
*Postconditions -
*/
	void menu();

/*
*Preconditions -
*Postconditions -
*/
	void openinv();

/*
*Preconditions -
*Postconditions -
*/
	void craftmenu();

/*
*Preconditions -
*Postconditions -
*/
	void move(char input);

/*
*Preconditions -
*Postconditions -
*/
	void savegame();

/*
*Preconditions -
*Postconditions -
*/
	void loadgame();

/*
*Preconditions -
*Postconditions -
*/
	void tutorial();

/*
*Preconditions -
*Postconditions -
*/
	void startmenu();

/*
*Preconditions -
*Postconditions -
*/
	void vinteract();

/*
*Preconditions -
*Postconditions -
*/
	void craft();

/*
*Preconditions -
*Postconditions -
*/
	void craftvillage();

/*
*Preconditions -
*Postconditions -
*/
	int EnemySpawn();

/*
*Preconditions -
*Postconditions -
*/
	void combat(int i);

private:

	bool running, incombat, invillage, inwater, inrocks, bossdefeated;//, inbosscastle;//may implement mining and fishing if I have time
	int lmx, lmy;//big map = these are for current location
	int smx, smy;//little map

	char largemap[7][7], smallmap[6][6];

	Player Player1;
	Save newsave;
	Map playmap;
	NPCs villager1;
	NPCs villager2, villager3, villager4, villager5, villager6;
};

#endif //GAME_H
