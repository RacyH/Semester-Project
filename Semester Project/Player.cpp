#include "Player.h"
//#include "Save.h"
#include "Map.h"
#include "Enemies.h"
#include "NPCs.h"

Map current;

Player::Player()
{
	Name = "";
	health = 0;
	stamina = 0;
	strength = 0;
	speed = 0;
	level = 0;
}

Player::~Player()
{
	//save player, reset inventory, perks, location
}

void Player::CharacterSetUp()
{
	strength = 1;
	stamina = 1;
	speed = 1;
	strength = 1;
	level = 0;

	int points = 0;
	char selection;
	bool laser = false;
	cout << "First, name your character. Characters may only have one name.\n";
	cin >> Name;
	cout << "You will be given one free point in each of your Speed, Strength, and your Stamina.\n";
	cout << "You will be given 5 extra points wherever you want to put them.\n";
	cout << "For your first point, press W for speed, A for Strength, and S for stamina.\n";
	while (laser == false)
	{
		cin >> selection;
		if (selection == 'W' || selection == 'w')
		{
			cout << "Stamina determines how often you get a critical hit. It also determines your health regen.\n";
			laser = true;
			stamina++;
		}
		else if (selection == 'A' || selection == 'a')
		{
			cout << "Strength determines how hard you hit. It is a determinant factor in your health regen.\n";
			laser = true;
			strength++;
		}
		else if (selection == 'S' || selection == 's')
		{
			cout << "Speed determines how fast you hit. This will effect you in battle, as whoever is faster hits first.\n";
			laser = true;
			speed++;
		}
		else
		{
			cout << "That was an invalid selection. Please choose either Speed, Strength, or Stamina.\n";
			laser = true;
		}
	}
	for (points; points < 4; points++)
	{
		system("cls");
		cout << "What would you like to add to your character stats now.\n";
		cin >> selection;
		switch (selection)
		{
		case 'A': strength++;
			break;
		case 'W': stamina++;
			break;
		case 'S': speed++;
			break;
		case 'a': strength++;
			break;
		case 'w': stamina++;
			break;
		case 's': speed++;
			break;
		default: cout << "That was an incorrect selection. Please try again.\n";
			cout << "Remember, W is for stamina, A is for strength, and S is for speed.\n";
			points--;
			break;
		}
	}
}

char Player::playermove(char move)
{
	switch (move)
	{
	case 'w':
		break;//Forward
	case 'W':
		break;
	case 'a':
		break;//Left
	case 'A':
		break;
	case 's':
		break;//Down/Backward
	case 'S':
		break;
	case 'd':
		break;//Right
	case 'D':
		break;
	default:
		break;
	}
}

void Player::characterlocation()
{
	
}

void Player::craft(int& cr)
{
	switch (cr)
	{
	case 0:
		break;//world
	case 1:
		break;//item
	default: cout << "You cannot do that here.\n";
		break;
	}
}

void Player::interact(int& x)
{
	switch (x)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default: cout << "You cannot do that here.\n";
		break;
	}
}

void Player::LevelUp()
{
	char stat;
	bool haschosen = false;

	level = level + 1;
	strength = strength + 1;
	speed = speed + 1;
	stamina = stamina + 1;
	health = health + 10;

	system("cls");

	cout << "Congratulations, you have leveled up.\nYou are now level " << level << ".\n";
	cout << "All of your stats have increased by 1, and your health has increased by 10.\n";
	cout << "You may choose to gain an extra point in Speed, Strength, or Stamina, or you may gain 10 extra health.\n";
	cout << "Press W for speed, A for strength, S for stamina, or D for health.\n";
	while (haschosen == false)
	{
		cin >> stat;
		if (stat == 'W' || stat == 'w')
		{
			speed = speed + 1;
			haschosen = true;
		}
		else if (stat == 'A' || stat == 'a')
		{
			strength = strength + 1;
			haschosen = true;
		}
		else if (stat == 'S' || stat == 's')
		{
			stamina = stamina + 1;
			haschosen = true;
		}
		else if (stat == 'D' || stat == 'd')
		{
			health = health + 10;
			haschosen = true;
		}
		else
		{
			cout << "That was not a valid selection. Try again.\n";
		}
	}
}

void Player::GainExperience()
{

	if (currentexperience >= experienceneeded)
	{LevelUp();}
}

void Player::PerkChart()
{

}

void Player::useitem()
{

}