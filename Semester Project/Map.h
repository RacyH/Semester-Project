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
*Preconditions - Requires iostream. Requires hashouse, haschest, haswell.
*Postconditions - Sets the variables to false.
*/
	Map();

/*
*Preconditions - Requires iostream. Requires hashouse, haschest, haswell.
*Postconditions - Sets the variables to false.
*/
	~Map();

/*
*Preconditions - Requires iostream and std library. Requires large[] array.
*Postconditions - Runs a loop, creating the default map.
* NOTE*** There is a different way I would like to have implemented this. Find it commented out
* in the cpp file.
*/
	void SetLocationType();

/*
*Preconditions - Requires iostream. Requires maplarge[][]. Requires input.
*Postconditions - Returns the value of the maplarge[][] array based on input.
*/
	int GetPlayLocation(int& x, int& y);

/*
*Preconditions - Requires iostream. Requires large[][]. Requires input.
*Postconditions - Returns the character that is set to large[][] based on input.
*/
	char GetLocType(int x, int y);

/*
*Preconditions - Requires iostream. Requires maplarge[][].
*Postconditions - Sets values 0 - 48 in the array maplarge[][].
*/
	void CreateMapLarge();

/*
*Preconditions - Requires iostream and std libarary. Requires large[][] and maplarge[][].
*Postconditions - Outputs the values of both large[][] and maplarge[][].
* NOTE*** I did not spend much time on this, and it needs work. It is backwards for both.
*/
	void printmap(int& loc);

//May end up scrapping. Is not used for anything.
	//void CreateMapSmall();

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
*Preconditions - Requires iostream and std library. Requires input. Requires haschest, hashouse, haswell.
*Postconditions - Upon input, determines what to display. After displaying those messages, the user inputs from the keyboard.
* Upon input, it determines what to subtract from the input of the function and which output to display.
* NOTE*** In this early version, building these things does nothing, and does not save after exiting the game.
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