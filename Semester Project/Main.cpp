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
*Preconditions - Requires iostream and std library.
*Postconditions - Outputs the main menu to the screen.
*/
void mainmenu();

/*
There are quite a few bugs in this code. However, it runs, works, and is quite fun. 10/10 would definitely recommend.
Also, You may find that there are a few classes that do not have deconstructors. I found out that because I used arrays,
it deletes all of it's variables automatically without a deconstructor. Enjoy this game.
*/
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
