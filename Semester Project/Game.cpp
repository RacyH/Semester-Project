#include "Game.h"

Game::Game()
{
    setdefmap();
    lmx = 0;
    lmy = 0;
	smx = 0;
	smy = 0;
    running = true;
}

void Game::run()
{
    while (running) {
        evalmove();
    }
}

void Game::handleinput(char input)
{
    //open menu, move, interact
	switch (input)
	{
	case 'w': move('w');
		break;
	case 'W': move('w');
		break;
	case 'a': move('a');
		break;
	case 'A': move('a');
		break;
	case 's': move('s');
		break;
	case 'S': move('s');
		break;
	case 'd': move('d');
		break;
	case 'D': move('d');
		break;
	case 'e': if (incombat != true)
	{
		craft();
	}
		break;
	case 'E': if (incombat != true)
	{
		craft();
	}
		break;
	case 'I': openinv();
		break;
	case 'i': openinv();
		break;
	case 'z': menu();
		break;
	case 'Z':menu();
		break;
	default:
		break;
	}
}

void Game::openmap()
{
	int loc = playmap.GetPlayLocation(lmx, lmy);
	char ex;
	playmap.printmap(loc);
	cout << "\nPress any letter followed by enter to exit the Map.\n";
	cin >> ex;
}

void Game::setdefmap()
{
	playmap.SetLocationType();
	playmap.CreateMapLarge();
	playmap.CreateMapSmall();
}

void Game::evalpos(string& something)
{
	int loc = playmap.GetPlayLocation(lmx, lmy), ene = EnemySpawn();
	char type;
	if (loc == 1)
	{
		invillage = true;
	}
	else
	{
		invillage = false;
	}
	if (ene > -1)
	{
		incombat = true;
		enemy.SetEnemy(ene);
		something = enemy.GetEnemy();
	}
	else
	{
		incombat = false;
	}
}

void Game::evalmove()
{
	string something;
	evalpos(something);
	HUD();
	if (invillage)
	{
		cout << "You are in the local village. Try out the shops, build a home, dig a well, or go out and adventure.\n\n";
	}
	if (incombat)
	{
		cout << "You are approached by a wild " << something << ". What are you going to do?\n";
	}
	char choice;
	cin >> choice;
    handleinput(choice);
	/*if (running)//because the option to quit is handled within handleinput function, this will kick the player from the game, without evalpos()
	{
		evalpos(something);
	}*/
}

void Game::HUD()
{
    Sleep(400);
    system("cls");

    cout << "Name: " << Player1.GetName() << "  Lvl: " << Player1.GetLevel() << "  Exp/To Next Level: ";
    cout << Player1.GetExperience() << '/' << Player1.ExperienceToNext() << endl << endl;
	cout << "Health/Max Health: " << Player1.GetHealth() << '/' << Player1.GetMaxH() << endl;
	cout << "Current Position:" << smy << smx << endl << endl;//not sure if I want to include current position yet
}

void Game::menu()
{
	system("cls");
	int menuchoice = 0;
	cout << "Menu:\n";
	cout << "1. Open Map\n";
	cout << "2. Tutorial\n";
	cout << "3. Save and Exit\n";
	while (menuchoice < 1 || menuchoice > 3)
	{
		cin >> menuchoice;
		if (menuchoice < 1 || menuchoice > 3)
		{
			cout << "Incorrect input. Please try again.\n";
		}
	}
	switch (menuchoice)
	{
	case 1: openmap();
		menu();
		break;
	case 2: tutorial();
		menu();
		break;
	case 3: savegame();
		break;
	}
}

void Game::openinv()
{
	char use;
	int item;
	system("cls");
	Player1.ShowInv();
	cout << "Press U to Use an item.\n";
	cout << "Usable items are potions, the food, and the herbs.\n";
	cout << "Press Q to Equip an item.\n";
	cout << "If you choose to use or equip an item, key in the items number to equip.\n";
	cout << "Press E to exit Inventory.\n";
	cin >> use;
	if (use == 'U' || use == 'u')
	{
		cin >> item;
		item--;
		Player1.useitem(item);
	}
	else if (use == 'Q' || use == 'q')
	{
		cin >> item;
		item--;
		Player1.EquipItem(item);
	}
}

void Game::craftmenu()
{
	int chc;
	bool valid;
	system("cls");
	if (invillage)
	{
		cout << "In this menu, you may interact with nearby villagers, craft items necessary for survival, and craft village items.\n";
		cout << "Village items include a well, a chest, and a home.\nYou may only craft one of each of these items.\n";
		cout << "Press the corresponding number next to the option you would like to choose.\n";
		cout << "1. Interact with Villagers\n2. Craft Item\n3. Craft Village Item\n4. Exit\n\n";
		cin >> chc;
		switch(chc)
		{
		case 1: vinteract();
			break;
		case 2: craft();
			break;
		case 3: craftvillage();
			break;
		case 4: break;
		default: craftmenu();
			break;
		}
	}
	else if (!invillage)
	{
		cout << "In this menu, you may craft items necessary for survival.\n";
		cout << "Press the corresponding number next to the option you would like to choose.\n";
		cout << "1. Craft Item\n2. Exit\n\n";
		cin >> chc;
		switch (chc)
		{
		case 1: craft();
			break;
		case 2:
			break;
		default: craftmenu();
			break;
		}
	}
}

void Game::move(char input) //need error handling for water and mountains
{
	switch (input)
	{
		case 'w': if (smy < 6) 
		{
			smy++;
		}
		else
		{
			if (lmy < 6)
			{
				lmy++;
				smy = 0;
			}
			else
			{
				cout << "You cannot go this way.\n";
			}
		}
			break;
		case 'a':  if (smx > 0) 
		{
			smx--;
		}
		else
		{
			if (lmx > 0)
			{
				lmx--;
				smx = 0;
			}
			else
			{
				cout << "You cannot go this way.\n";
			}
		}
			break;
		case 'd':   if (smx < 6)
		{
			smx++;
		}
		else
		{
			if (lmx < 7)
			{
				lmx++;
				smx = 0;
			}
			else
			{
				cout << "You cannot go that way.\n";
			}
		}
			break;
		case 's': if (smy > 0)
		{
			smy--;
		}
		else
		{
			if (lmy > 0)
			{
				lmy--;
				smy = 0;
			}
			else
			{
				cout << "You cannot go this way.\n";
			}
		}
			break;
	}
}

void Game::tutorial()
{
	char ex;
	cout << "1. W, A, S, D are the buttons that you will use to move. W is forward, A is move to the right, S to the left, and D is backwards.\n";
	cout << "2. E will be the button to press to craft things while not in combat. While in the village, you can build things in the world,\n";
	cout << "otherwise, things you craft will be added to your inventory, which can be accessed by pressing I.\n";
	cout << "3. Pressing E in the village will also allow you to interact with the villagers around you.\n";
	cout << "4. To enter the menu, press Z.\n";
	cout << "5. This game is not for those who cannot handle defeat. You may die, and you may not like it. Do not punch your computer.\n";
	cout << "6. Enjoy the game.\n";
	cout << "Press any letter, followed by enter, to exit the tutorial.\n";
	cin >> ex;
}

void Game::savegame()
{
	string nm = Player1.GetName();
	int hlt = Player1.GetHealth(), maxhlt = Player1.GetMaxH(), sta = Player1.GetStamina() , spd = Player1.GetSpeed() , str = Player1.GetStrength() ,
		lvl = Player1.GetLevel() , mon = Player1.GetMoney();
	newsave.SaveFile(nm, hlt, maxhlt, sta, spd, str, lvl, mon);
	newsave.SaveMap(largemap, smallmap);
	running = false;//allows game to exit
}

void Game::loadgame(string name)
{
	newsave.LoadFile();
	int health = newsave.GetHlt(), stamina = newsave.GetStam(), speed = newsave.GetSpd(), strength = newsave.GetStr() ,
		level = newsave.GetLvl(), money = newsave.GetMon(), maxhealth = newsave.GetMaxHlt();

	Player1.SetName(name);
	Player1.SetHealth(health);
	Player1.SetSpeed(speed);//Need locations for x and y. also the house you've built, well, inventory, and chest.
	Player1.SetStamina(stamina);
	Player1.SetStrength(strength);
	Player1.SetLevel(level);
	Player1.SetMoney(money);
	Player1.SetMaxH(maxhealth);

	newsave.LoadMap(largemap, smallmap);
}

void Game::startmenu()
{
	char selection, sel;
	bool choice = false;
	while (choice == false)
	{
		cin >> selection;
		if (selection == 'N' || selection == 'n')
		{
			choice = true;
			Player1.CharacterSetUp();
			run();
		}
		else if (selection == 'L' || selection == 'l')
		{
			choice = true;
			string charname;
			cout << "What is the name on the file that you would like to open?\n";
			cout << "Remember that names are case sensitive and do not have spaces in them.\n";
			cin >> charname;
			loadgame(charname);
			run();
		}
		else if (selection == 'E' || selection == 'e')
		{
			choice = true;
		}
		else
		{
			cout << "Incorrect Input.\n";
		}
	}
}

void Game::vinteract()
{
	system("cls");

	craftmenu();
}

void Game::craft()
{
	system("cls");
	showcraftable();

	craftmenu();
}

void Game::craftvillage()
{
	system("cls");

	craftmenu();
}

int Game::EnemySpawn()
{
	srand(time(NULL));

	int loc = playmap.GetPlayLocation(lmx, lmy);

	if (14 > loc > 7)
	{
		int r = rand() % 2;
		if (r == 1)
		{
			int en = rand() % 2;
			return en;
		}
	}
	else if (21 > loc > 14)
	{
		int r = rand() % 2;
		if (r == 1)
		{
			int en = rand() % 4;
			return en;
		}
	}
	else if (28 > loc > 21)
	{
		int r = rand() % 2;
		if (r == 1)
		{
			int en = rand() % 6;
			return en;
		}
	}
	else if (35 > loc > 28)
	{
		int r = rand() % 2;
		if (r == 1)
		{
			int en = rand() % 8;
			return en;
		}
	}
	else if (42 > loc > 35)
	{
		int r = rand() % 2;
		if (r == 1)
		{
			int en = rand() % 10;
			return en;
		}
	}
	else if (49 > loc > 42)//every spot in the outskirts of the map will give up a fight, except for the last, which I'm hoping to have
		//a boss fight in.
	{
		int en = rand() % 12;
		return en;
	}
	return -1; //if it does not end up returning a value above 0, it will return -1, which will tell the game that there is no beast
}

void Game::showcraftable()//needs to be in player
{
  //this is for actual crafting of sword
}
/*
1. sword - need wood 2 metal cloth
2. battleaxe - need 2 wood metal cloth
3. warhammer - need 2 wood metal cloth
4. hammer - need wood metal
5. axe - need 2 wood metal
6. pickaxe - need 2 wood 2 metal
7. shield - need 3 wood metal cloth
8. knife - need metal cloth
9. food - need uncooked food wood
10. health potion - need food and herbs
11. stat boost - need wood 2 herbs
12. health boost - need wood, uncooked food, herbs
13. helmet - 2 metal
14. chest plate - 5 metal
15. leg plating - 4 metal
16. armored boots - 3 metal
*/