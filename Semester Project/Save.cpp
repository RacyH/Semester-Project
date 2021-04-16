/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#include "Save.h"

void Save::SaveFile(string name, int health, int maxh, int stamina, int speed, int strength, int level, int money, int curexp, int neexp)
{
	fstream outFile; //need input and output for experience.

	outFile.open(save1);
	outFile << name << ' ' << health << ' ' << maxh << ' ' << stamina << ' ' << speed << ' ' << strength << ' ' << level << ' ' << money << 
		' ' << curexp << ' ' << neexp << endl;
	outFile.close();
}

void Save::LoadFile()
{
	fstream inFile;

	inFile.open(save1);
	inFile >> nme >> hlt >> maxhlt >> sta>> spd >> str >> lvl >> mon >> cexp >> nexp;
	inFile.close();
}

void Save::SaveMap(/*char largechar[][7], char msmall[][6],*/int& curx, int& cury, int& curlx, int& curly)
{//the current version does not need to save the map.
	fstream inFile;

	inFile.open(map1);

	/*for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			inFile << largechar[yL][xL] << ' ';
		}
		inFile << endl;
	}

	for (int xS = 0; xS < 6; xS++)
	{
		for (int yS = 0; yS < 6; yS++)
		{
			inFile << msmall[yS][xS] << ' ';
		}
		inFile << endl;
	}*/

	inFile << curx << ' ' << cury << ' ' << curlx << ' ' << curly << endl;
	inFile.close();
}

void Save::LoadMap(/*char largechar[][7], char msmall[][6], */int& curx, int& cury, int& curlx, int& curly)
{
	fstream outFile;
	outFile.open(map1);

	/*for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			outFile >> largechar[yL][xL];
		}
	}

	for (int xS = 0; xS < 6; xS++)
	{
		for (int yS = 0; yS < 6; yS++)
		{
			outFile >> msmall[yS][xS];
		}
	}*/

	outFile >> curx >> cury >> curlx >> curly;

	outFile.close();
}

void Save::SaveInv(int inv[], int eqp[])
{
	fstream inFile;

	inFile.open(inv1);
	for (int i = 0; i < 22; i++)
	{
		inFile << inv[i] << ' ';
	}

	cout << endl;

	for (int j = 0; j < 6; j++)
	{
		inFile << eqp[j] << ' ';
	}

	inFile.close();
}

void Save::LoadInv(int inv[], int eqp[])
{
	fstream outFile;

	outFile.open(inv1);
	for (int i = 0; i < 22; i++)
	{
		outFile >> inv[i];
	}
	for (int j = 0; j < 6; j++)
	{
		outFile >> eqp[j];
	}
	outFile.close();
}