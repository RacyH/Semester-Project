#ifndef MAP_H
#define MAP_H


class Map
{
public:

	void SetLocationType();
	void GetPlayLocation();
	void EnemySpawn();
	void CreateMapLarge();

private:

	int maplarge[7][7];//indicates the block that you are in
	//I think that the player will start at 0, and if they go into the outer ends of the map, so the x and y axis of 7, they will have to face much larger opponents
	char mapsmall[49][12][12]; //[indicates which of the maplarge blocks you are in][y-axis of each individual mapsmall][x-axis of the mapsmall]
	//is a character so that the program knows what sort of things are happening there.
	int chest[19][1];//You may only have one chest in the game. 19, 2.
};

#endif //MAP_H
