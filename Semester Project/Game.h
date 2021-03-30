#ifndef GAME_H
#define GAME_H

#include <iostream>
//#include <vector>
#include <Windows.h>
#include "Player.h"
#include "Save.h"
#include "Map.h"
#include "Enemies.h"
#include <time.h> 

//using std::vector;

class Game
{
public:


	Game();
	//Game(const string& filename); //this is if I have time later. easier than hardcoding the map


	void run();


	void handleinput(char input);


	void openmap();


	void setdefmap();


	void evalpos(string& something);


	void evalmove();


	void HUD();


	void menu();


	void openinv();


	void craftmenu();


	void move(char input);


	void savegame();


	void loadgame(string name);


	void tutorial();


	void startmenu();


	void vinteract();


	void craft();


	void craftvillage();


	int EnemySpawn();


	void showcraftable();

private:

	bool running, incombat, invillage;
	int lmx, lmy;//big map = these are for current location
	int smx, smy;//little map

	char largemap[7][7], smallmap[49][6][6];

	Player Player1;
	Save newsave;
	Map playmap;
	Enemies enemy;
};

#endif //GAME_H
