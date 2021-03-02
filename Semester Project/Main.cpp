/*Racy Halterman
* 
*/

#include <iostream>
#include <iomanip>
#include "Crafting.h"
#include "Enemies.h"
#include "Map.h"
#include "Player.h"
#include "NPCs.h"
#include "Save.h"

void mainmenu();

Player Player1;

void main()
{
	mainmenu();
	char selection;
	bool choice = false;
	while (choice == false)
	{
		cin >> selection;
		if (selection == 'N' || selection == 'n')
		{
			Player1.CharacterSetUp();
		}
		else if (selection == 'L' || selection == 'l')
		{

		}
		else if (selection == 'E' || selection == 'e')
		{

		}
		else
		{
			cout << "Incorrect Input. Try again.\n";
		}
	}


}

void mainmenu()
{
	cout << "Welcome to this game.\n"; //Need a game title and location.
	cout << "You may choose one of the following by selecting the letter that is next to it.\n";
	cout << "New Game\tN\n";
	cout << "Load Game\tL\n";
	cout << "Exit Game\tE\n";
}
