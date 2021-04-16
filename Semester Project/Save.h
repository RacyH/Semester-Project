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
#include <iomanip>
using namespace std;

class Save
{
public:
/*
*Preconditions -
*Postconditions -
*/
	void SaveFile(string name, int health, int maxh, int stamina, int speed, int strength, int level, int money, int curexp, int neexp);

/*
*Preconditions -
*Postconditions -
*/
	void LoadFile();

/*
*Preconditions -
*Postconditions -
*/
	string GetName() { return nme; };

/*
*Preconditions -
*Postconditions -
*/
	int GetHlt() { return hlt; };

/*
*Preconditions -
*Postconditions -
*/
	int GetMaxHlt() { return maxhlt; };

/*
*Preconditions -
*Postconditions -
*/
	int GetStam() { return sta; };

/*
*Preconditions -
*Postconditions -
*/
	int GetSpd() { return spd; };

/*
*Preconditions -
*Postconditions -
*/
	int GetStr() { return str; };

/*
*Preconditions -
*Postconditions -
*/
	int GetLvl() { return lvl; };

/*
*Preconditions -
*Postconditions -
*/
	int GetMon() { return mon; };

/*
*Preconditions -
*Postconditions -
*/
	int GetCexp() { return cexp; };

/*
*Preconditions -
*Postconditions -
*/
	int GetNexp() { return nexp; };

/*
*Preconditions -
*Postconditions -
*/
	void SaveMap(/*char largechar[][7], char msmall[][6], */int& curx, int& cury, int& curlx, int& curly);

/*
*Preconditions -
*Postconditions -
*/
	void LoadMap(/*char largechar[][7], char msmall[][6], */int& curx, int& cury, int& curlx, int& curly);

/*
*Preconditions -
*Postconditions -
*/
	void SaveInv(int inv[], int eqp[]);

/*
*Preconditions -
*Postconditions -
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