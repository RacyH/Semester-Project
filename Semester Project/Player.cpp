#include "Player.h"
//#include "Map.h"
//#include "Enemies.h"
//#include "NPCs.h"

//Map current;

Player::Player()
{
	Name = "";
	health = 0;
	maxHealth = 0;
	stamina = 0;
	strength = 0;
	speed = 0;
	level = 0;
}

Player::~Player()
{

	//reset/destroy
}

void Player::CharacterSetUp()
{
	strength = 1;
	stamina = 1;
	speed = 1;
	strength = 1;
	health = 100;
	maxHealth = health;
	experienceneeded = 50;
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
		cout << "What would you like to add to your character stats now?\n";
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

void Player::showcraft()
{
	int crch;
	if (inventory[2] >= 2 && inventory[1] >= 1 && inventory[15] >= 1)//sword
	{
		cout << "1. Sword\n";
	}
	if (inventory[2] >= 1 && inventory[1] >= 2 && inventory[15] >= 1)
	{
		cout << "2. Battleaxe\n";
	}
	if (inventory[2] >= 1 && inventory[1] >= 2 && inventory[15] >= 1)
	{
		cout << "3. Warhammer\n";
	}
	if (inventory[2] >= 1 && inventory[1] >= 1)
	{
		cout << "4. Hammer\n";
	}
	if (inventory[2] >= 1 && inventory[1] >= 2)
	{
		cout << "5. Axe\n";
	}
	if (inventory[2] >= 2 && inventory[1] >= 2)
	{
		cout << "6. Pickaxe\n";
	}
	if (inventory[2] >= 1 && inventory[1] >= 3 && inventory[15] >= 1)
	{
		cout << "7. Shield\n";
	}
	if (inventory[2] >= 1 && inventory[15] >= 1)
	{
		cout << "8. Knife\n";
	}
	if (inventory[16] >= 1 && inventory[1] >= 1)
	{
		cout << "9. Food\n";
	}
	if (inventory[11] >= 1 && inventory[17] >= 1)
	{
		cout << "10. Health Potion\n";
	}
	if (inventory[17] >= 2 && inventory[1] >= 1)
	{
		cout << "11. Stat Boost Potion\n";
	}
	if (inventory[16] >= 1 && inventory[1] >= 1 && inventory[17] >= 1)
	{
		cout << "12. Health Boost Potion\n";
	}
	if (inventory[2] >= 2)
	{
		cout << "13. Helmet\n";
	}
	if (inventory[5] >= 2)
	{
		cout << "14. Chest Piece\n";
	}
	if (inventory[4] >= 2)
	{
		cout << "15. Leg Plating\n";
	}
	if (inventory[3] >= 2)
	{
		cout << "16. Armored Boots\n";
	}
	cout << "Put in the number next to the item you would like to craft.\n";//need an exit code
	cin >> crch;
	craft(crch);
}

void Player::craft(int& item)
{
	switch (item)
	{
	case 1:	inventory[2] = inventory[2] - 2;
		inventory[1] = inventory[1] - 1;
		inventory[15] = inventory[15] - 1;
		inventory[3]++;
		break;
	case 2:	inventory[2] = inventory[2] - 1;
		inventory[1] = inventory[1] - 2;
		inventory[15] = inventory[15] - 1;
		inventory[4]++;
		break;
	case 3:	inventory[2] = inventory[2] - 1;
		inventory[1] = inventory[1] - 2;
		inventory[15] = inventory[15] - 1;
		inventory[5]++;
		break;
	case 4:	inventory[2] = inventory[2] - 1;
		inventory[1] = inventory[1] - 1;
		inventory[6]++;
		break;
	case 5:	inventory[2] = inventory[2] - 1;
		inventory[1] = inventory[1] - 2;
		inventory[7]++;
		break;
	case 6:	inventory[2] = inventory[2] - 2;
		inventory[1] = inventory[1] - 2;
		inventory[8]++;
		break;
	case 7:	inventory[2] = inventory[2] - 1;
		inventory[1] = inventory[1] - 3;
		inventory[15] = inventory[15] - 1;
		inventory[9]++;
		break;
	case 8:	inventory[2] = inventory[2] - 1;
		inventory[15] = inventory[15] - 1;
		inventory[10]++;
		break;
	case 9:	inventory[16] = inventory[16] - 1;
		inventory[1] = inventory[1] - 1;
		inventory[11]++;
		break;
	case 10: inventory[17] = inventory[17] - 1;
		inventory[11] = inventory[11] - 1;
		inventory[12]++;
		break;
	case 11: inventory[17] = inventory[17] - 1;
		inventory[1] = inventory[1] - 1;
		inventory[13]++;
		break;
	case 12: inventory[16] = inventory[16] - 1;
		inventory[1] = inventory[1] - 1;
		inventory[17] = inventory[17] - 1;
		inventory[14]++;
		break;
	case 13: inventory[2] = inventory[2] - 2;
		inventory[18]++;
		break;
	case 14: inventory[2] = inventory[2] - 5;
		inventory[19]++;
		break;
	case 15: inventory[2] = inventory[2] - 4;
		inventory[20]++;
		break;
	case 16: inventory[2] = inventory[2] - 3;
		inventory[21]++;
		break;
	default: cout << "Invalid Option.\n";
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

	level++, strength++, speed++, stamina++;
	maxHealth = maxHealth + 10;
	health = maxHealth;
	experienceneeded = (level * 50) + 50;

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
			speed++;
			haschosen = true;
		}
		else if (stat == 'A' || stat == 'a')
		{
			strength++;
			haschosen = true;
		}
		else if (stat == 'S' || stat == 's')
		{
			stamina++;
			haschosen = true;
		}
		else if (stat == 'D' || stat == 'd')
		{
			maxHealth = maxHealth + 10;
			health = maxHealth;
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

void Player::useitem(int& use)
{
	if (use == 11 || use == 12 || use == 13 || use == 14 || use == 18)
	{
		if (inventory[use] > 0)
		{
			inventory[use] = inventory[use] - 1;
		}
		else
		{
			cout << "There is not enough of that item to use.\n";
		}
	}
	else
	{
		cout << "You may not use that item. Try equipping it instead.\n";
	}
}

void Player::AddItem(int& add, int num)
{
	inventory[add] = inventory[add] + num;
}

void Player::ShowInv()
{
	for (int i = 0; i < 22; i++)
	{
		if (inventory[i] > 0)
		{
			cout << i + 1 << '\t' << items[i] << '\t' << inventory[i];
		}
	}
}

void Player::EquipItem(int& eq)
{
	if (eq == 3 || eq == 4 || eq == 5 || eq == 6 || eq == 7 || eq == 8 || eq == 10)//weaponry
	{
		if (inventory[eq] > 0 && equipment[5][0] == 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[5][0] = eq;
		}
	}
	else if (eq == 18 && equipment[0][0] == 0)
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[0][0] = eq;
		}
	}
	else if (eq == 19 && equipment[1][0] == 0) //helmet
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[1][0] = 1;
		}
	}
	else if (eq == 20 && equipment[2][0] == 0) //chest plate
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[2][0] = 1;
		}
	}
	else if (eq == 21 && equipment[3][0] == 0) //leg plating
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[3][0] = 1;
		}
	}
	else if (eq == 9 && equipment[4][0] == 0) //shield
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[4][0] = 1;
		}
	}
	else
	{
		cout << "You may not equip that item.\n";
	}
}