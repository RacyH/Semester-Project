/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a script game program.
*/
#include "Enemies.h"

Enemies::Enemies(int no, int plev)
{
	SetEnemy(no);
	SetEHealth();
	SetESpeed();
	SetEStamina();
	SetEStr();
	EnemyAttack();
	SetExp();
	SetEMaxLevel();
	SetLoot();
	SetArmorRating();
	SetELevel(plev);
}

Enemies::~Enemies()
{
	earmor = ehealth = estamina = espeed = estrength = eattack = elevel = eexpgiven = emax_level = enumber = 0;
}

void Enemies::SetEHealth()
{
	if (elevel == 0)
	{
		ehealth = 10;
	}
	if (enumber < 10 && elevel != 0)
	{
		ehealth = 100;
	}
	else if(enumber == 12)
	{
		ehealth = 1500;
	}
	else
	{
		ehealth = 250;
	}
}

void Enemies::SetESpeed()
{
	if (enumber != 12)
	{
		if (elevel > 0)
			espeed = elevel;
		else
			espeed = 1;
	}
	else //The dragon will pretty much always be faster than you.
	{
		espeed = 150 + elevel;
	}
}

void Enemies::SetEStamina()
{
	if (enumber != 12)
	{
		if (elevel > 0)
			estamina = elevel;
		else
			estamina = 1;
	}
	else
	{
		estamina = elevel + 10;
	}
}

void Enemies::SetEStr() //The dragon doesn't hit that much harder than the other guys, but he can take a beating.
{
	if (elevel != 0)
		estrength = elevel;
	else if(elevel == 0)
		estrength = 1;
}

void Enemies::SetEMaxLevel()
{
	if (enumber < 10)
	{
		emax_level = enumber + 10;
	}
	else //prepare to get roughed up by some witches, demons, and a dragon.
	{
		emax_level = 100;
	}
}

void Enemies::SetELevel(int plvl)
{
	if (plvl <= emax_level)
	{
		elevel = plvl;
	}
	else
	{
		elevel = emax_level;
	}
}

void Enemies::SetExp()
{
	int exp;
	if (enumber != 12)
	{
		exp = enumber + 25;
		eexpgiven = exp;
	}
	else
	{
		exp = 1000 + (enumber * 25);
		eexpgiven = exp; //lots of experience for the dragon
	}
}

int Enemies::EnemyAttack()
{
	eattack = estrength;
	return eattack;
}

void Enemies::SetArmorRating()
{
	if (enumber != 12)
	{
		earmor = elevel;
	}
	else
	{
		earmor = elevel + 25;
	}
}

void Enemies::SetLoot()
{
	srand(time(NULL));
	itemno = rand() % 3; //Enemies only drop wood, stone, or metal. all other items must be crafted or bought
	//int itemno, amount, gold, exp;
	amount = rand() % 10;
	switch (enumber)
	{
	case 0:
		gold = 2;
		break;
	case 1:
		gold = 5;
		break;
	case 2:
		gold = 10;
		break;
	case 3:
		gold = 15;
		break;
	case 4:
		gold = 20;
		break;
	case 5:
		gold = 25;
		break;
	case 6:
		gold = 50;
		break;
	case 7:
		gold = 55;
		break;
	case 8:
		gold = 75;
		break;
	case 9:
		gold = 90;
		break;
	case 10:
		gold = 100;
		break;
	case 11:
		gold = 150;
		break;
	case 12:
		gold = 1000;
		break;
	}
}

void Enemies::PlayerGetLoot(int& ino, int& amt, int& g)
{
	ino = itemno;
	amt = amount;
	g = gold;
}

void Enemies::GetAttacked(int att)
{
	int damage = ehealth - att;
	ehealth = damage;
	if (ehealth < 0)
	{
		SetLoot();
	}
}

void Enemies::DeathByFlee()
{
	ehealth = 0;
}

void Enemies::EHUD()
{
	cout << ecurrent << "\tLevel: " << elevel << "\tHealth: " << ehealth << endl;
	//cout << eexpgiven << endl;//used for debugging purposes
}