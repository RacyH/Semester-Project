/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef MAP_H
#define MAP_H


class Map
{
public:

	/*
*Preconditions -
*Postconditions -
*/
	Map();

	/*
*Preconditions -
*Postconditions -
*/
	~Map();

/*
*Preconditions -
*Postconditions -
*/
	void SetLocationType();

/*
*Preconditions -
*Postconditions -
*/
	int GetPlayLocation(int& x, int& y);

/*
*Preconditions -
*Postconditions -
*/
	char GetLocType(int x, int y);

/*
*Preconditions -
*Postconditions -
*/
	void CreateMapLarge();

/*
*Preconditions -
*Postconditions -
*/
	void printmap(int& loc);

/*
*Preconditions -
*Postconditions -
*/
	void CreateMapSmall();

/*
*Preconditions - Is not used in current version. Saved for update.
*Postconditions -
*/
	//void loadmap(char largechar[][7], char msmall[6][6]);

/*
*Preconditions - Is not used in current version. Saved for update.
*Postconditions -
*/
	//void savemap(char largechar[][7], char msmall[6][6]);

/*
*Preconditions -
*Postconditions -
*/
	void CreateVillageItem(int& st, int& wo, int& met);

/*
*Preconditions - Not used in current version. Saved for updates.
*Postconditions -
*/
	//void SearchForHouse(int& x, int& y);

private:

	int maplarge[7][7];//indicates the block that you are in
	char large[7][7];
	//I think that the player will start at 0, and if they go into the outer ends of the map, so the x and y axis of 7, they will have to face much larger opponents
	char mapsmall[6][6]; //indicates which of the maplarge blocks you are in y-axis of each individual mapsmall x-axis of the mapsmall
	//is a character so that the program knows what sort of things are happening there.
	//int chest[19];//You may only have one chest in the game
	bool haswell, hashouse, haschest;
};

#endif //MAP_H