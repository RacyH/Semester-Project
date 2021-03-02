#include "Map.h"


void Map::SetLocationType()
{

}

void Map::GetPlayLocation()
{

}

void Map::EnemySpawn()
{

}

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