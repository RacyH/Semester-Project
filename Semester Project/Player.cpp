/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a video game program.
*/
#include "Player.h"


Player::Player()
{
	Name = "";
	health = 0;
	maxHealth = 0;
	stamina = 0;
	strength = 0;
	speed = 0;
	level = 0;
	currentexperience = 0;
	experienceneeded = 50 + (level * 50);
	SetBeginningInv();
}

Player::~Player()
{
	Name = "";
	health = 0;
	maxHealth = 0;
	stamina = 0;
	strength = 0;
	speed = 0;
	level = 0;
	currentexperience = 0;
	experienceneeded = 0;
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
		cin.get(selection);
		if (selection == 'W' || selection == 'w')
		{
			cout << "Stamina determines your health regen.\n";
			laser = true;
			stamina++;
		}
		else if (selection == 'A' || selection == 'a')
		{
			cout << "Strength determines how hard you hit.\n";
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
		}
	}
	for (points; points < 4; points++)
	{
		system("cls");
		cout << "What would you like to add to your character stats now?\n";
		cin.get(selection);
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

void Player::SetBeginningInv()
{
	for (int i = 0; i < 22; i++)
	{
		inventory[i] = 0;
	}
	for (int j = 0; j < 6; j++)
	{
		equipment[j] = 0;
	}
}

void Player::SetArmor()
{
	if (equipment[0] == 1)
	{
		//helmet
		armor = 5;
	}
	if (equipment[1] == 1)
	{
		//chest
		armor = armor + 5;
	}
	if (equipment[2] == 1)
	{
		//legs
		armor = armor + 5;
	}
	if (equipment[3] == 1)
	{
		//boots
		armor = armor + 5;
	}
	if (equipment[4] == 1)
	{
		//shield
		armor = armor + 5;
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
	cout << "0. Exit\n";
	cout << "Put in the number next to the item you would like to craft.\n";//need an exit code
	cin >> crch;
	while (!(cin >> crch))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> crch;
	}
	if (crch != 17)
	{
		craft(crch);
	}
}

void Player::craft(int& item)
{
	switch (item)//need error handling for if the menu does not have the item with it. a simple if statement for each of them
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

void Player::GainExperience(int exp)
{
	currentexperience = currentexperience + exp;
	while (currentexperience >= experienceneeded)
	{
		if (currentexperience >= experienceneeded)
		{
			LevelUp();
		}
	}
}

void Player::useitem(int use) //need to add in the uses of the items
{
	if (use == 11 || use == 12 || use == 13 || use == 14 || use == 16 || use == 17)//still need these items to do something
	{
		if (inventory[use] > 0)
		{
			inventory[use] = inventory[use] - 1;
			effect(use);
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

void Player::effect(int use)
{
	switch (use)
	{
	case 11: 
	if (health < maxHealth)
	{
		if (health <= maxHealth - 25)
		{
			health += 25;
		}
		else
		{
			health = maxHealth;
		}
	}
		break;
	case 12:
		if (health < maxHealth)
		{
			if (health <= maxHealth - 100)
			{
				health += 100;
			}
			else
			{
				health = maxHealth;
			}
		}
		break;
	case 13:
		break;
	case 14:
		break;
	case 16:
		if (health < maxHealth)
		{
			if (health <= maxHealth - 5)
			{
				health += 5;
			}
			else
			{
				health = maxHealth;
			}
		}
		break;
	case 17:
		break;
	default: break;
	}
}

void Player::AddItem(int& add, int num)
{
	inventory[add] += num;
}

void Player::ShowInv()
{
	for (int i = 0; i < 22; i++)
	{
		if (inventory[i] > 0)
		{
			cout << i + 1 << '\t' << items[i] << '\t' << inventory[i] << endl;
		}
	}
}

void Player::EquipItem(int& eq)
{
	if (eq == 3 || eq == 4 || eq == 5 || eq == 6 || eq == 7 || eq == 8 || eq == 10)//weaponry
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[5] = eq;
		}
	}
	else if (eq == 18 && equipment[0] == 0)//helmet
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[0] = eq;
		}
	}
	else if (eq == 19 && equipment[1] == 0) //chest plate
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[1] = 1;
		}
	}
	else if (eq == 20 && equipment[2] == 0) //leg plating
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[2] = 1;
		}
	}
	else if (eq == 21 && equipment[3] == 0) //armored boots
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[3] = 1;
		}
	}
	else if (eq == 9 && equipment[4] == 0) //shield
	{
		if (inventory[eq] > 0)
		{
			inventory[eq] = inventory[eq] - 1;
			equipment[4] = 1;
		}
	}
	else
	{
		cout << "You may not equip that item.\n";
	}
}

void Player::CombatItem()
{
	//11,12,13,14,16,17
	int choice;
	cout << "Press the corresponding number next to the item you would like to use.\n";
	if (inventory[11] > 0)
	{
		cout << "1. Food\n";
	}
	if (inventory[16] > 0)
	{
		cout << "2. Uncooked Food\n";
	}
	if (inventory[12] > 0)
	{
		cout << "3. Health Potion\n";
	}
	if (inventory[14] > 0)
	{
		cout << "4. Health Boost Potion\n";
	}
	if (inventory[13] > 0)
	{
		cout << "5. Stat Boost Potion\n";
	}
	if (inventory[17] > 0)
	{
		cout << "6. Herbs\n";
	}
	cin >> choice;
	while (!(cin >> choice))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> choice;
	}
	if (choice < 1 || choice > 6)
	{
		switch (choice)
		{
		case 1: useitem(11);
			break;
		case 2: useitem(16);
			break;
		case 3: useitem(12);
			break;
		case 4: useitem(14);
			break;
		case 5: useitem(13);
			break;
		case 6: useitem(17);
			break;
		}
	}
}

void Player::GetAttacked(int atk)
{
	//int damage = health - atk;
	health -= atk;
}

void Player::VillageItem(int& st, int& wo, int& met)
{
	wo = inventory[0];
	st = inventory[1];
	met = inventory[2];
}

void Player::CreatedItem(int& st, int& wo, int& met)
{
	inventory[0] = wo;
	inventory[1] = st;
	inventory[2] = met;
}

void Player::GetInv(int inv[])//these next four are to help saving and loading
{
	for (int i = 0; i < 22; i++)
	{
		inv[i] = inventory[i];
	}
}

void Player::GetEqp(int eqp[])
{
	for (int i = 0; i < 6; i++)
	{
		eqp[i] = equipment[i];
	}
}

void Player::SetInv(int inv[])
{
	for (int i = 0; i < 22; i++)
	{
		inventory[i] = inv[i];
	}
}

void Player::SetEqp(int eqp[])
{
	for (int i = 0; i < 6; i++)
	{
		equipment[i] = eqp[i];
	}
}

int Player::trade()
{
	int t, am, ams = 0;
	cout << "Press the number next to the item you would like to sell.\n";
	cin >> t;
	while (!(cin >> t))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> t;
	}
	cout << "You currently have " << inventory[t - 1] << " of that item right now.\n";
	cout << "How much would you like to sell?\n";
	cin >> am;
	while (!(cin >> am))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> am;
	}
	while (am > inventory[t - 1])
	{
		cout << "You do not have enough of that item.\nInput the amount you would like to sell again.\n";
		cin >> am;
		while (!(cin >> am))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cout << "Not a number. Try again.\n";
			cin >> am;
		}
	}
	switch (t)
	{
	case 0: break;
	case 1:	inventory[t - 1] = inventory[t - 1] - am;
		ams = (1 * am);
		money = (money - ams);
		break;
	case 2: inventory[t - 1] = inventory[t - 1] - am;
		ams = (2 * am);
		money = (money - ams);
		break;
	case 3:inventory[t - 1] = inventory[t - 1] - am;
		ams = (3 * am);
		money = (money - ams);
		break;
	case 4:inventory[t - 1] = inventory[t - 1] - am;
		ams = (15 * am);
		money = (money - ams);
		break;
	case 5:inventory[t - 1] = inventory[t - 1] - am;
		ams = (15 * am);
		money = (money - ams);
		break;
	case 6:inventory[t - 1] = inventory[t - 1] - am;
		ams = (15 * am);
		money = (money - ams);
		break;
	case 7:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 8:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 9:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 10:inventory[t - 1] = inventory[t - 1] - am;
		ams = (20 * am);
		money = (money - ams);
		break;
	case 11:inventory[t - 1] = inventory[t - 1] - am;
		ams = (15 * am);
		money = (money - ams);
		break;
	case 12:inventory[t - 1] = inventory[t - 1] - am;
		ams = (5 * am);
		money = (money - ams);
		break;
	case 13:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 14:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 15:inventory[t - 1] = inventory[t - 1] - am;
		ams = (10 * am);
		money = (money - ams);
		break;
	case 16:inventory[t - 1] = inventory[t - 1] - am;
		ams = (1 * am);
		money = (money - ams);
		break;
	case 17:inventory[t - 1] = inventory[t - 1] - am;
		ams = (3 * am);
		money = (money - ams);
		break;
	case 18:inventory[t - 1] = inventory[t - 1] - am;
		ams = (3 * am);
		money = (money - ams);
		break;
	case 19:inventory[t - 1] = inventory[t - 1] - am;
		ams = (25 * am);
		money = (money - ams);
		break;
	case 20:inventory[t - 1] = inventory[t - 1] - am;
		ams = (50 * am);
		money = (money - ams);
		break;
	case 21:inventory[t - 1] = inventory[t - 1] - am;
		ams = (30 * am);
		money = (money - ams);
		break;
	case 22:inventory[t - 1] = inventory[t - 1] - am;
		ams = (25 * am);
		money = (money - ams);
		break;
	default: break;
	}
	return (-1 * ams);
}

void Player::addremovegold(int g)
{
	money = money + g;
}