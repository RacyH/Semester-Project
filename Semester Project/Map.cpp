#include "Map.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void Map::SetLocationType()//randomly generates a world. There is a 60% chance of the area being a grassland, 20% chance of the area being a mountain, and 20% it's a body of water
{
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			char chance;
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
			large[y][x] = chance;
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
	maplarge[0][0] = 'V';
}

void Map::CreateMapSmall()//gotta work on this.
{
	for (int L = 1; L < 49; L++)
	{
		for (int x = 0; x < 6; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				
			}
		}
	}
}

int Map::GetPlayLocation(int& x, int& y)
{
	return maplarge[y][x];
}

//gonna move this to Game.cpp

void Map::CreateMapLarge()
{
	int x = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			maplarge[i][j] = x;
			x++;
		}
	}
}

void Map::printmap(int& loc)
{
	system("cls");
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
		{
			cout << mapsmall[loc][y][x] << ' ';
		}
		cout << endl;
	}
}

void Map::loadmap(char largechar[][7], char msmall[49][6][6])
{

	//need input from file.
	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			large[yL][xL] = largechar[yL][xL];
		}
	}
	for (int z = 0; z < 49; z++)//[z][y][x]
	{
		for (int xS = 0; xS < 12; xS++)
		{
			for (int yS = 0; yS < 12; yS++)
			{
				mapsmall[z][yS][xS] = msmall[z][yS][xS];
			}
		}
	}
}

void Map::savemap(char largechar[][7], char msmall[49][6][6])
{

	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			largechar[yL][xL] = large[yL][xL];
		}
	}
	for (int z = 0; z < 49; z++)//[z][y][x]
	{
		for (int xS = 0; xS < 12; xS++)
		{
			for (int yS = 0; yS < 12; yS++)
			{
				msmall[z][xS][xS] = mapsmall[z][yS][xS];
			}
		}
	}
}