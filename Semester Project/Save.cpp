#include "Save.h"

void Save::SaveFile(string name, int health, int maxh, int stamina, int speed, int strength, int level, int money)
{
	fstream outFile;

	outFile.open(save1);
	outFile << name << ' ' << health << ' ' << maxh << ' ' << stamina << ' ' << speed << ' ' << strength << ' ' << level << ' ' << money << endl;
	outFile.close();
}

void Save::LoadFile()
{
	fstream inFile;

	inFile.open(save1);
	inFile >> nme >> hlt >> maxhlt >> sta>> spd >> str >> lvl >> mon;
	inFile.close();
}

void Save::SaveMap(char largechar[][7], char msmall[49][6][6])
{
	fstream inFile;

	inFile.open(map1);

	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			inFile << largechar[yL][xL] << ' ';
		}
		inFile << endl;
	}

	inFile << endl << endl;

	for (int z = 0; z < 49; z++)//[z][y][x]
	{
		for (int xS = 0; xS < 6; xS++)
		{
			for (int yS = 0; yS < 6; yS++)
			{
				inFile << msmall[z][yS][xS] << ' ';
			}
			inFile << endl;
		}
	}
	inFile.close();
}

void Save::LoadMap(char largechar[][7], char msmall[49][6][6])
{
	fstream outFile;
	outFile.open(map1);

	for (int xL = 0; xL < 7; xL++)
	{
		for (int yL = 0; yL < 7; yL++)
		{
			outFile >> largechar[yL][xL];
		}
	}

	for (int z = 0; z < 49; z++)//[z][y][x]
	{
		for (int xS = 0; xS < 6; xS++)
		{
			for (int yS = 0; yS < 6; yS++)
			{
				outFile >> msmall[z][yS][xS];
			}
		}
	}
	outFile.close();
}

void Save::SaveInv(int inv[])
{
	fstream inFile;

	inFile.open(inv1);
	for (int i = 0; i < 22; i++)
	{
		inFile << inv[i] << ' ';
	}
	inFile.close();
}

void Save::LoadInv(int inv[])
{
	fstream outFile;

	outFile.open(inv1);
	for (int i = 0; i < 22; i++)
	{
		outFile >> inv[i];
	}
	outFile.close();
}