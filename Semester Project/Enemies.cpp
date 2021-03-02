#include "Enemies.h"
#include "Player.h"

void Enemies::SetEnemy()
{
	//there will only be 12 enemey types. i may move this to the map.h, or the player.h as I develop more of the game. May include a boss later
}

void Enemies::SetEHealth()
{
	ehealth = 100 + (elevel * 10);
}

void Enemies::SetESpeed()
{
	espeed = elevel * 1.5;
}

void Enemies::SetEStamina()
{
	estamina = elevel * 1.5;
}

void Enemies::SetEStr()
{
	estrength = elevel * (estamina / 3);
}

void Enemies::SetEMaxLevel()
{

}

void Enemies::SetELevel()
{
	//elevel = come back to this
}

void Enemies::SetExp()
{
	eexpgiven = elevel * 25;
}

void Enemies::EnemyAttack()
{
	eattack = estrength;
}

void Enemies::SetArmorRating()
{
	earmor = elevel * .8;
}

void Enemies::SetLoot()
{
	switch (enumber)
	{
	case 0:
		break;
	case 1:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	}
}

void Enemies::PlayerGetLoot()
{

}