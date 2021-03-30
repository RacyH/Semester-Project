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

	void SaveFile(string name, int health, int maxh, int stamina, int speed, int strength, int level, int money);


	void LoadFile();


	string GetName() { return nme; };


	int GetHlt() { return hlt; };


	int GetMaxHlt() { return maxhlt; };


	int GetStam() { return sta; };


	int GetSpd() { return spd; };


	int GetStr() { return str; };


	int GetLvl() { return lvl; };


	int GetMon() { return mon; };


	void SaveMap(char largechar[][7], char msmall[49][6][6]);


	void LoadMap(char largechar[][7], char msmall[49][6][6]);


	void SaveInv(int inv[]);


	void LoadInv(int inv[]);

private:

	string save1 = "save1.txt";
	string map1 = "map1.txt";
	string inv1 = "inv1.txt";
	string nme;
	int hlt, maxhlt, sta, spd, str, lvl, mon;

};

#endif //SAVE_H