/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "Game.h"

/*
*Preconditions -
*Postconditions -
*/
void mainmenu();


int main()
{
	mainmenu();
	Game game;//i am going to need constructors and deconstructors for every single class.
	game.startmenu();
}

void mainmenu()
{
	cout << "Welcome to this game.\n"; //Need a game title and location.
	cout << "You may choose one of the following by selecting the letter that is next to it.\n";
	cout << "New Game\tN\n";
	cout << "Load Game\tL\n";
	cout << "Exit Game\tE\n";
}
