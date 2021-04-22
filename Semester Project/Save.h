/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <string>
#include <fstream>
//#include <iomanip>
using namespace std;

class Save
{
public:
/*
*Preconditions - Requires iostream, std library, fstream. Requires input. Requires save1.
*Postconditions - Outputs the input to the save1 file.
*/
	void SaveFile(string name, int health, int maxh, int stamina, int speed, int strength, int level, int money, int curexp, int neexp);

/*
*Preconditions - Requires iostream, std library, fstream. Requires save1, nme, hlt, maxhlt, sta, spd, str, lvl, mon, cexp, nexp.
*Postconditions - Loads and sets the different variable from the file.
*/
	void LoadFile();

/*
*Preconditions - Requires iostream. Requires nme.
*Postconditions - Returns string saved in nme.
*/
	string GetName() { return nme; };

/*
*Preconditions - Requires iostream. Requires hlt.
*Postconditions - Returns int value saved in hlt.
*/
	int GetHlt() { return hlt; };

/*
*Preconditions - Requires iostream. Requires maxhlt.
*Postconditions - Returns int value saved in maxhlt.
*/
	int GetMaxHlt() { return maxhlt; };

/*
*Preconditions - Requires iostream. Requires sta.
*Postconditions - Returns int value saved in sta.
*/
	int GetStam() { return sta; };

/*
*Preconditions - Requires iostream. Requires spd.
*Postconditions - Returns int value saved in spd.
*/
	int GetSpd() { return spd; };

/*
*Preconditions - Requires iostream. Requires str.
*Postconditions - Returns int value saved in str.
*/
	int GetStr() { return str; };

/*
*Preconditions - Requires iostream. Requires lvl.
*Postconditions - Returns int value saved in lvl.
*/
	int GetLvl() { return lvl; };

/*
*Preconditions - Requires iostream. Requires mon.
*Postconditions - Returns int value saved in mon.
*/
	int GetMon() { return mon; };

/*
*Preconditions - Requires iostream. Requires cexp.
*Postconditions - Returns int value saved in cexp.
*/
	int GetCexp() { return cexp; };

/*
*Preconditions - Requires iostream. Requires nexp.
*Postconditions - Returns int value saved in nexp.
*/
	int GetNexp() { return nexp; };

/*
*Preconditions - Requires iostream, std library, fstream. Requires input. Requires map1.
*Postconditions - Saves the input to the map1 file.
* NOTE*** There is no need to save anything from the map except the current position. So, that is all that is saved.
*/
	void SaveMap(/*char largechar[][7], char msmall[][6], */int& curx, int& cury, int& curlx, int& curly);

/*
*Preconditions - Requires iostream, std library, fstream. Requires input. Requires map1.
*Postconditions - Changes the value of the function inputs to inputs from the file
*/
	void LoadMap(/*char largechar[][7], char msmall[][6], */int& curx, int& cury, int& curlx, int& curly);

/*
*Preconditions - Requires iostream, std library, fstream. Requires input. Requires inv1.
*Postconditions - Saves the inputs to the file.
*/
	void SaveInv(int inv[], int eqp[]);

/*
*Preconditions - Requires iostream, std library, fstream. Requires input. Requires inv1.
*Postconditions - Loads the inputs from the file.
*/
	void LoadInv(int inv[], int eqp[]);

private:

	string save1 = "save1.txt";
	string map1 = "map1.txt";
	string inv1 = "inv1.txt";
	string nme;
	int hlt, maxhlt, sta, spd, str, lvl, mon, cexp, nexp;

};

#endif //SAVE_H