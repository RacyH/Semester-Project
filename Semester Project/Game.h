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
*Preconditions - Requires iostream. Requires setdefmap() to work. Requires the following variable to be loaded:
* lmx, lmy, smx, smy, running, inwater, inrocks, invillage, incombat, bossdefeated.
*Postconditions - Sets the above variables to their default. Runs setdefmap().
*/
	Game();
	//Game(const string& filename); //this is if I have time later. easier than hardcoding the map

/*
*Preconditions - Requires iostream. Requires evalmove() function to work. Requires running to be set.
*Postconditions - While running is equal to true, runs evalmove() repeatedly.
*/
	void run();

/*
*Preconditions - Requires iostream. Requires input. Requires move(), craftmenu(), openinv(), and menu() functions to work.
*Postconditions - Selects which function to perform based on input. If input is invalid, does nothing.
*/
	void handleinput(char input);

/*
*Preconditions - Requires iostream. Requires Map.h is included. Requires lmx and lmy to have values set to them.
* Requires playmap object has been created.
*Postconditions - Runs GetPlayLocation() and printmap() functions from Map class.
* NOTE*** This function does not work properly. Would like to improve on it later.
*/
	void openmap();

/*
*Preconditions - Requires iostream. Requires Map.h is included. Requires playmap object has been created.
*Postconditions - Runs SetLocationType(), CreateMapLarge() functions from Map class.
* NOTE*** CreateMapSmall() is not necessarily a requirement to play this game. Will use in later versions of the game.
*/
	void setdefmap();

/*
*Preconditions - Requires iostream. Requires input. Requires Map.h is loaded. Requires playmap object has been created.
* Requires the following variables: invillage, inrocks, inwater, incombat, lmx, lmy.
* Requires EnemySpawn() function works properly.
*Postconditions - Runs GetLocType(), sets input equal to the result of running EnemySpawn()
* Will also set the different boolean drivers to true or false based on outcomes.
* NOTE*** A lot of this function is left for future versions.
*/
	void evalpos(int& something);

/*
*Preconditions - Requires iostream. Requires evalpos(), HUD(), combat(), handleinput() functions.
* Requires Player.h included. Requires Player1 object has been created. Requires std library.
* Requiers incombat and invillage variables have values.
*Postconditions - Runs evalpos(), runs HUD(), handles bool values to determine which other functions and outputs to perform.
*/
	void evalmove();

/*
*Preconditions - Requires iostream. Requires Windows.h. Requires std library. Requires Player.h. Requires Player1 object has been created.
*Postconditions - Runs Sleep(), clears the screen, outputs a basic HUD for the player.
*/
	void HUD();

/*
*Preconditions - Requires iostream. Requires std library. Requires openmap(), menu(), tutorial(), savegame() functions.
*Postconditions - Clears the screen then outputs a basic menu. Upon input from the user, it performs functions.
* NOTE*** It generally asks for more than one input.
*/
	void menu();

/*
*Preconditions - Requires iostream. Requires std library. Requires Player.h is included. Requires Player1 object has been created.
*Postconditions - Clears the screen then outputs the Player1 inventory[]. Outputs options for the user. Prompts input.
* Upon input, performs whichever function the user prompted.
*/
	void openinv();

/*
*Preconditions - Requires iostream. Requires std libary. Requires vinteract(), craft(), craftvillage(), craftmenu() functions.
* Requires invillage to have a value.
*Postconditions - Depending on value of invillage, outputs a menu, prompts for an input, and based on the input
* performs the function prompted by the user.
*/
	void craftmenu();

/*
*Preconditions - Requires iostream and std library. Requires input. Requires lmx, lmy, smx, and smy.
*Postconditions - Based on input changes the values of the variables.
* If the user tries to move without the bounds of the map, it couts to the screen an error message.
* NOTE*** Sometimes the game pushed you faster when you press S. I have noted this in the INTRO() function.
*/
	void move(char input);

/*
*Preconditions - Requires iostream. Requires running. Requires Player.h, Save.h be included.
* Requires smx, smy, lmx, lmy. Requiers std library. Requires Player1 and newsave objects have been created.
*Postconditions - Runs the save functions from Save.h based on variables set by Get functions from Player1 object.
* Sets running to false.
*/
	void savegame();

/*
*Preconditions - Requries iostream. Requires std library. Requires Player.h and Save.h included.
* REquiers smx, smy, lmx, and lmy. Requires Player1 and newsave objects created.
*Postconditions - Loads in variables from newsave object, and sets them to Player1 object.
*/
	void loadgame();

/*
*Preconditions - Requires iostream and std libary.
*Postconditions - Outputs a tutorial to the screen, and prompts the user for input to close the tutorial.
*/
	void tutorial();

/*
*Preconditions - Requires iostream. Requires std library. Requires Windows.h. Requires Player.h. Requires Player1 object has been created.
* Requires INTRO(), run(), loadgame() functions to work.
*Postconditions - Takes input from the user, and then determines which function, or an error
* message to run or display.
*/
	void startmenu();

/*
*Preconditions - Requires iostream. Requires std library. Requires Villager.h and Player.h to be loaded.
*Requires Player1, villager1, villager2, villager3, villager4, villager5, villager6 objects to be created.
* Requires craftmenu() function to work.
*Postconditions - Clears the screen. Displays the available villagers names. Prompts for input. Upon input, allows the user to choose to
*buy or sell from that particular villager.
* NOTE*** It will only work if the user inputs twice for every prompt.
*/
	void vinteract();

/*
*Preconditions - Requires iostream and std library. Requires Player.h. Requires Player1 object is created.
* Requires craftmenu() works.
*Postconditions - Clears the screen. Then Player1.showcraft() runs. Then runs craftmenu().
*/
	void craft();

/*
*Preconditions - Requires iostream and std library. Requires Player.h and Map.h. Requires Player1 and playmap objects have been created.
* Requires vinteract(), craft(), craftmenu() functions to work.
*Postconditions - Prompts the user to select input. Upon input, determines which function to run.
*/
	void craftvillage();

/*
*Preconditions - Requires iostream, std library, and time.h. Requires Map.h. Requires playmap object has been created.
* Requires lmx and lmy.
*Postconditions - Determines player location, then returns a random number based on location.
*/
	int EnemySpawn();

/*
*Preconditions - Requires Enemy.h. Requires Windows.h. Requires iostream and std library. Requires Player.h. Requires Player1 object has been created.
* Requires HUD(). Requirs lmx, lmy, smx, smy.
*Postconditions - Displays HUD(), then creates enemy object of class type Enemy, then prompts for input. Upon input, determines which functions
* from which class to perform. Upon completion, may update lmx, lmy, smx, and smy to zero if certain conditions are met.
*/
	void combat(int i);

	/*
*Preconditions - Requires iostream, std library, and Windows.h.
*Postconditions - Clears the screen, outputs an introduction to the game. Then Sleep() runs for one second.
*/
	void INTRO();

private:

	bool running, incombat, invillage, inwater, inrocks, bossdefeated;//, inbosscastle;//may implement mining and fishing if I have time
	int lmx, lmy;//big map = these are for current location
	int smx, smy;//little map

	char largemap[7][7], smallmap[6][6];

	Player Player1;
	Save newsave;
	Map playmap;
//	NPCs villager1(1);
//	NPCs villager2(2), villager3(3), villager4(0), villager5(1), villager6(4);
	NPCs villager1;
	NPCs villager2;
	NPCs villager3;
	NPCs villager4;
	NPCs villager5;
	NPCs villager6;
};

#endif //GAME_H
