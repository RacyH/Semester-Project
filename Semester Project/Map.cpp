/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a script game program.
*/
#include "Map.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Map::Map()
{
	hashouse = haschest = haswell = false;
}

Map::~Map()
{
	hashouse = haschest = haswell = false;
}

void Map::SetLocationType()//randomly generates a world. There is a 60% chance of the area being a grassland, 20% chance of the area being a mountain, and 20% it's a body of water
{
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			/*char chance;
			int i = rand() % 5;
			switch (i)
			{
			case 0: chance = '^'; //Mountain//want to be able to mine//probably just call this rocky landscape
				break;
			case 1: chance = '~'; //Water//want to be able to fish
				break;
			case 2:chance = '"'; //Grassland
				break;
			case 3:chance = '"';
				break;
			case 4:chance = '"';
				break;
			default:chance = '"';
				break;
			}
			large[y][x] = chance;*/ //above is the implementation i would like to use in an updated version of the game. it is just randomly spawning terrain
			large[y][x] = 'g';
		}
	}
	for (int j = 0; j < 7; j++)
	{
		large[6][j] = '#';
		if (large[j][6] != '#')
		{
			large[j][6] = '#'; //This is just a harder grassland. More enemies. Borders the outside of the map.
		}
		else
		{
			large[j][6] = '*'; //This is where I will locate the boss if I have time.
		}
	}
	large[0][0] = 'V';
}

void Map::CreateMapSmall()//may disclude this entirely. if the terrain has been built in maplarge, then it doesn't need to take up any more space in the game itself.
{//this is now for the village map, so that house and well can be stored here.
	//may end up discluding anyway, and just making hashouse and haswell options. make the code smaller, more efficient
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			mapsmall[y][x] = 'x';
		}
	}
}

int Map::GetPlayLocation(int& x, int& y)
{
	return maplarge[y][x];
}

char Map::GetLocType(int x, int y)
{
	return large[y][x];
}

void Map::CreateMapLarge() //simple measuring device used for debugging purposes.
{
	int i = 0;
	for (int x = 0; x < 7; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			maplarge[y][x] = i;
			i++;
		}
	}
}

void Map::printmap(int& loc) //gotta figure this out. everything else works fine, thanks to implementation, but printing the map does not.
//may have to create another array, and have it be in that array backwards
{
	system("cls");
	int ex;
	for (int x = 6; x > -1; x--)
	{
		for (int y = 6; y > -1; y--)
		{
			cout << large[y][x] << ' ';
		}
		cout << endl;
	}
	for (int x = 6; x > -1; x--)
	{
		for (int y = 6; y > -1; y--)
		{
			cout << maplarge[y][x] << ' ';
		}
		cout << endl;
	}
	cout << "Press 1 to exit.\n";
	cin >> ex;
}

/*void Map::loadmap(char largechar[][7], char msmall[6][6])
{
	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			large[yL][xL] = largechar[yL][xL];
		}
	}
	for (int xS = 0; xS < 6; xS++)
	{
		for (int yS = 0; yS < 6; yS++)
		{
			mapsmall[yS][xS] = msmall[yS][xS]; //fix these
		}
	}
}

void Map::savemap(char largechar[][7], char msmall[6][6])
{

	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			largechar[yL][xL] = large[yL][xL];
		}
	}
	for (int xS = 0; xS < 6; xS++) //will only save the village map, so that your house and well are in the spot they need to be in
	{
		for (int yS = 0; yS < 6; yS++)
		{
			msmall[xS][xS] = mapsmall[yS][xS];
		}
	}
}*/

void Map::CreateVillageItem(int& st, int& wo, int& met)
{
	//say 40 stone to create well//200 wood to create house//15 wood and 1 metal to create chest
	int build, x, y;
	cout << "Press 0 to exit.\n";
	if (st >= 40)
	{
		cout << "Press 1 to add a well.\n";
	}
	if (wo >= 200)
	{
		cout << "Press 2 to add a house.\n";
	}
	if (wo >= 15 && met >= 1 && hashouse == true)
	{
		cout << "Press 3 to add a chest.\n";
	}
	cin >> build; //would like to put something in here to make it so that you cannot add things if you don't have enough resources.
	while (!(cin >> build))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> build;
	}
	if (4 > build > 0)
	{
		system("cls");
		//next bit used in updates.
		/*cout << "Where would you like to build? You cannot build where you have built before, and you may only build in the village.\n";
		cout << "Chests may only be built inside of a house that you have already built.\n";
		cout << "Input the x axis location first, then the y axis. The villagers will move their things for you.\n";
		cout << "The x axis runs horizontally, and has 6 spaces. The y axis runs vertically, and also has 6 spaces. Choose a number 1 - 6 for both.\n";
		cin >> x;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Not a number. Try again.\n";
			cin >> x;
		}
		cin >> y;
		while (!(cin >> y))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Not a number. Try again.\n";
			cin >> y;
		}
		if (mapsmall[y-1][x-1] == 'w' || mapsmall[y-1][x-1] == 'h' || mapsmall[y-1][x-1] == 'H')//capital H means there is a chest inside
		{
			cout << "You have already placed something here. Please try again.\n";
		}
		else if (x > 6 || x < 1 || y > 6 || y < 1)
		{
			cout << "You have chosen coordinates outside of the range of the village. Try again.\n";
		}*/
		if (build == 1)
		{
			//mapsmall[y-1][x-1] = 'w';
			st = st - 40;
			haswell = true;
		}
		else if (build == 2)
		{
			//mapsmall[y-1][x-1] = 'h';
			wo = wo - 200;
			hashouse = true;
		}
		else if (build == 3)
		{
			//SearchForHouse(x, y);
			//will need to create a function that searches for and returns the x and y coordinates of the house
			//mapsmall[y][x] = 'H';//this house now has a chest in it.
			wo = wo - 15;
			met = met - 1;
			haschest = true;
		}
	}
}

/*void Map::SearchForHouse(int& x, int& y) //may just stuff this above, as the user will only ever need to use this once in game
{//used in updates.
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (mapsmall[i][j] == 'h')
			{
				x = j;
				y = i;
			}
		}
	}
}*/