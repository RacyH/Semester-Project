/*Racy Halterman
* 
*/

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "Game.h"


void mainmenu();

Game game;

int main()
{
	mainmenu();
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