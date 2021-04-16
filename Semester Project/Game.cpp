/*Racy Halterman
* Data Structures Spring 2021
* Semester Project
* Writing a script game program.
*/
#include "Game.h"
using std::cout;

Game::Game()//may need two constructors. one for a load, one for a new game
{
    setdefmap(); //this needs moved.
    lmx = 0;
    lmy = 0;
	smx = 0;
	smy = 0;
    running = true;
	inwater = inrocks = invillage = incombat = bossdefeated = false;
}

void Game::run()
{
    while (running) 
	{
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
	case 'e':
		craftmenu();
		break;
	case 'E':
		craftmenu();
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
	playmap.printmap(loc);
}

void Game::setdefmap()
{
	playmap.SetLocationType();
	playmap.CreateMapLarge();
	playmap.CreateMapSmall();
}

void Game::evalpos(int& something)
{
	int loc = playmap.GetPlayLocation(lmx, lmy);// ene = -1;
	char type = playmap.GetLocType(lmx, lmy);
	something = EnemySpawn();
	if (something != -1)
	{
		incombat = true;
	}
	else
	{
		incombat = false;
	}
	//may implement mining and fishing later. maybe.
	switch (type)
	{
	case 'V': invillage = true; inrocks = inwater = false;
		break;
	case '~': inwater = true; inrocks = invillage = false;
		break;
	case '*': inwater = inrocks = false;
		break;
	case 'g': inwater = inrocks = invillage = false;
		break;
	case '^': inrocks = true; inwater = invillage = false;
		break;
	case '#': inwater = inrocks = invillage = false;
		break;
	default:break;
	}
}

void Game::evalmove()
{
	int something;
	char choice;
	evalpos(something);
	HUD();
	if (invillage == true)
	{
		cout << "You are in the local village. Try out the shops, build a home, dig a well, or go out and adventure.\n";
		cout << "Press E to craft or to interact with villagers.\n";
		cin.get(choice);
		handleinput(choice);
	}
	if (incombat == true)
	{
		cout << "Something is stirring near you. Will you fight, or flee?\n";
		cout << "Press A to fight, or D to flee.\n";
		cout << "If you flee, you will be spawned back in the village and lose half of the health you have left.\n";
		cin >> choice;
		while (choice != 'a' && choice != 'A' && choice != 'd' && choice != 'D')
		{
			cout << "Incorrect input. Please try again.\n";
			cin >> choice;
		}
		if (choice == 'A' || choice == 'a')
		{
			combat(something);
		}
		if (choice == 'D' || choice == 'd')
		{
			cout << "You have been spawned back at the village. Your health has been cut in half.\n";
			lmx = lmy = smx = smy = 0;
			incombat = false;
			int hlt = Player1.GetHealth();
			hlt = hlt / 2;
			Player1.SetHealth(hlt);
		}
	}
	else
	{
		cin>>choice;
		handleinput(choice);
	}
}

void Game::HUD()
{
    Sleep(400);
    system("cls");

    cout << "Name: " << Player1.GetName() << "  Lvl: " << Player1.GetLevel() << "  Exp/To Next Level: ";
    cout << Player1.GetExperience() << '/' << Player1.ExperienceToNext() << endl << endl;
	cout << "Health/Max Health: " << Player1.GetHealth() << '/' << Player1.GetMaxH() << endl;
	//cout << "Current Position:" << smy << smx << endl << endl;//not sure if I want to include current position yet
	cout << playmap.GetPlayLocation(lmx, lmy) << endl; //this is just for error handling.
}

void Game::menu()
{
	system("cls");
	int menuchoice = 0;
	cout << "Menu:\n";
	cout << "1. Open Map\n";//printmap function is not currently working properly
	cout << "2. Tutorial\n";
	cout << "3. Save and Exit\n";
	cout << "0. Exit Menu\n";
	cin >> menuchoice;
	while (!(cin >> menuchoice))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a number. Try again.\n";
		cin >> menuchoice;
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
	case 0: break;
	default: break;
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
		while (!(cin >> item))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cin >> item;
		}
		item--;
		Player1.useitem(item);
	}
	else if (use == 'Q' || use == 'q')
	{
		cin >> item;
		while (!(cin >> item))
		{
			cin.clear();
			cin.ignore(123, '\n');
			cin >> item;
		}
		item--;
		Player1.EquipItem(item);
	}
}

void Game::craftmenu()
{
	int chc;
	bool valid;
	system("cls");
	if (invillage == true)
	{
		cout << "In this menu, you may interact with nearby villagers, craft items necessary for survival, and craft village items.\n";
		cout << "Village items include a well, a chest, and a home.\nYou may only craft one of each of these items.\n";
		cout << "Press the corresponding number next to the option you would like to choose.\n";
		cout << "1. Interact with Villagers\n2. Craft Item\n3. Craft Village Item\n0. Exit\n\n";
		cin >> chc;
		switch(chc)
		{
		case 1: vinteract();
			break;
		case 2: craft();
			break;
		case 3: craftvillage();
			break;
		case 0: break;
		default: craftmenu();
			break;
		}
	}
	else if (invillage != true)
	{
		cout << "In this menu, you may craft items necessary for survival.\n";
		cout << "Press the corresponding number next to the option you would like to choose.\n";
		cout << "1. Craft Item\n0. Exit\n\n";
		cin >> chc;
		switch (chc)
		{
		case 1: craft();
			break;
		case 0: //just breaks here, rather than returning to the craftmenu()
			break;
		default: craftmenu();
			break;
		}
	}
}

void Game::move(char input)
{
	switch (input)
	{
		case 'w': if (smy < 5) 
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
		case 'd':   if (smx < 5)
		{
			smx++;
		}
		else
		{
			if (lmx < 6)
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
		lvl = Player1.GetLevel() , mon = Player1.GetMoney(), inv[22], eqp[6], cexp = Player1.GetExperience(), nexp = Player1.ExperienceToNext();
	//playmap.savemap(largemap, smallmap);
	Player1.GetInv(inv);
	Player1.GetEqp(eqp);
	newsave.SaveFile(nm, hlt, maxhlt, sta, spd, str, lvl, mon, cexp, nexp);
	newsave.SaveMap(smx, smy, lmx, lmy);
	newsave.SaveInv(inv, eqp);
	running = false;//allows game to exit
}

void Game::loadgame()
{
	newsave.LoadFile();
	string name = newsave.GetName();
	int health = newsave.GetHlt(), stamina = newsave.GetStam(), speed = newsave.GetSpd(), strength = newsave.GetStr(),
		level = newsave.GetLvl(), money = newsave.GetMon(), maxhealth = newsave.GetMaxHlt(), inv[22], eqp[6], 
		exp = newsave.GetCexp(), nexp = newsave.GetNexp();

	Player1.SetName(name);
	Player1.SetHealth(health);
	Player1.SetSpeed(speed);//Need locations for x and y. also the house you've built, well, inventory, and chest.
	Player1.SetStamina(stamina);
	Player1.SetStrength(strength);
	Player1.SetLevel(level);
	Player1.SetMoney(money);
	Player1.SetMaxH(maxhealth);
	Player1.SetExperience(exp);
	Player1.SetExperienceNeeded(nexp);

	newsave.LoadMap(smx, smy, lmx, lmy);
	newsave.LoadInv(inv, eqp);
	Player1.SetInv(inv);
	Player1.SetEqp(eqp);
	//playmap.loadmap(largemap, smallmap);
}

void Game::startmenu()
{
	char selection, sel;
	bool choice = false;
	while (choice == false)
	{
		cin.get(selection);
		if (selection == 'N' || selection == 'n')
		{
			choice = true;
			Player1.CharacterSetUp();
			run();
		}
		else if (selection == 'L' || selection == 'l')
		{
			choice = true;
			loadgame();
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
	int t, bs, g = 0, am = 0;
	system("cls");
	cout << "There are 6 adult villagers. You may buy their wares, or sell your own.\n";
	cout << "Enter the number next to the villager that you would like to interact with.\n";
	cout << "1. " << villager1.GetNPCname() << endl;
	cout << "2. " << villager2.GetNPCname() << endl;
	cout << "3. " << villager3.GetNPCname() << endl;
	cout << "4. " << villager4.GetNPCname() << endl;
	cout << "5. " << villager5.GetNPCname() << endl;
	cout << "6. " << villager6.GetNPCname() << endl;
	cout << "0. Exit\n";
	cin >> t;
	while (!(cin >> t))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a correct input.\nTry again.\n";
		cin >> t;
	}
	cout << "Would you like to buy or sell items?\n";
	cout << "1 to buy, 2 to sell, 0 to exit.\n";
	while (!(cin >> bs))
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "Not a correct input.\nTry again.\n";
		cin >> bs;
	}
	switch (t)
	{
	case 0: break;
	case 1:
		if (bs == 1)
		{
			villager1.showitems();
			cout << "0. Exit\n";
			am = 0;
			int x = villager1.trade(g, am);
			am = 0;
			Player1.addremovegold(g);
			Player1.AddItem(x, am);
		}
		else if (bs == 2)
		{
			Player1.ShowInv();
			cout << "0. Exit\n";
			g = Player1.trade();
			villager1.addremovegold(g);
		}
		break;
	case 2:		if (bs == 1)
	{
		villager2.showitems();
		cout << "0. Exit\n";
		am = 0;
		int x = villager2.trade(g, am);
		Player1.addremovegold(g);
		Player1.AddItem(x, am);
	}
		  else if (bs == 2)
	{
		Player1.ShowInv();
		cout << "0. Exit\n";
		g = Player1.trade();
		villager2.addremovegold(g);
	}
		  break;
	case 3: 		if (bs == 1)
	{
		villager3.showitems();
		cout << "0. Exit\n";
		am = 0;
		int x = villager3.trade(g, am);
		Player1.addremovegold(g);
		Player1.AddItem(x, am);
	}
		  else if (bs == 2)
	{
		Player1.ShowInv();
		cout << "0. Exit\n";
		g = Player1.trade();
		villager3.addremovegold(g);
	}
		  break;
	case 4: 		if (bs == 1)
	{
		villager4.showitems();
		cout << "0. Exit\n";
		am = 0;
		int x = villager4.trade(g, am);
		Player1.addremovegold(g);
		Player1.AddItem(x, am);
	}
		  else if (bs == 2)
	{
		Player1.ShowInv();
		cout << "0. Exit\n";
		g = Player1.trade();
		villager4.addremovegold(g);
	}
		  break;
	case 5: 		if (bs == 1)
	{
		villager5.showitems();
		cout << "0. Exit\n";
		am = 0;
		int x = villager5.trade(g, am);
		Player1.addremovegold(g);
		Player1.AddItem(x, am);
	}
		  else if (bs == 2)
	{
		Player1.ShowInv();
		cout << "0. Exit\n";
		g = Player1.trade();
		villager5.addremovegold(g);
	}
		  break;
	case 6: 		if (bs == 1)
	{
		villager6.showitems();
		cout << "0. Exit\n";
		am = 0;
		int x = villager6.trade(g, am);
		Player1.addremovegold(g);
		Player1.AddItem(x, am);
	}
		  else if (bs == 2)
	{
		Player1.ShowInv();
		cout << "0. Exit\n";
		g = Player1.trade();
		villager6.addremovegold(g);
	}
		  break;
	default: break;
	}
	craftmenu();
}

void Game::craft()
{
	system("cls");
	Player1.showcraft();
	craftmenu();
}

void Game::craftvillage() //needs to interact with player and map
{
	int input;
	system("cls");
	cout << "You can choose to 1. craft a menu item, 2. craft a village item, 3. to sell items to a villager.\n";
	cout << "0. Exit\n";
	cin >> input;
	switch (input)
	{
	case 1: craft();
		break;
	case 2: //This one will be rough, because I need to know which amounts the player has to craft the items.
		//so what I'm thinking is reach into the player class, see how much wood, stone, and metal are there.
		//pass that item into the wood, and pass it back into here, then update the players inventory
		int stone, metal, wood;
		Player1.VillageItem(stone, wood, metal);
		playmap.CreateVillageItem(stone, wood, metal);
		Player1.CreatedItem(stone, wood, metal);
		break;
	case 3: vinteract();
		break;
	case 0: break;
	default: craftmenu();
		break;
	}
}

int Game::EnemySpawn()
{
	//srand(time(NULL));

	int loc = playmap.GetPlayLocation(lmx, lmy);
	char type = playmap.GetLocType(lmx, lmy);
	int r = rand() % 5 + 1, en = -1;
	if (r > 3) //40% chance of spawning a creature
	{
		if (type == 'g') //in grassland
		{
			/*if (9 < Player1.GetLevel() < 20)
			{
				en = rand() % 4;
			}
			else if (19 < Player1.GetLevel() < 30)
			{
				en = rand() % 6;
			}
			else if (29 < Player1.GetLevel() < 40)
			{
				en = rand() % 8;
			}
			else if (39 < Player1.GetLevel() < 50)
			{
				en = rand() % 10;
			}
			else if (40 < Player1.GetLevel())
			{
				en = rand() % 12;
			}
			else //beginning, you only have to fight chickens and rats
			{*/
				en = rand() % 12;
			//}
		}
		if (type == '#')//no matter what, in the badlands, you can face anything from a chicken to a demon
		{
			en = rand() % 12;
		}
	}
	else if (type == '*' && bossdefeated == false)
	{
		en = 12;
	}
		//the below implementation is something that I would like to have used, but it had some errors.
	/*	else if (20 > loc >= 14)//the higher you get, the stronger the enemies become
		{
			en = rand() % 4;
		}
		else if (27 > loc >= 21)
		{
			en = rand() % 6;
		}
		else if (34 > loc >= 28)
		{
			en = rand() % 8;
		}
		else if (41 > loc >= 35)
		{
			en = rand() % 10;
		}
	}
	else if ((48 > loc >= 42) || loc == 13 || loc == 20 || loc == 27 || loc == 34 || loc == 41)
		//every spot in the outskirts of the map will give up a fight, except for the last, which I'm hoping to have a boss fight in.
	{
		en = rand() % 12;
	}
	else if (loc == 48 /*&& !(bossdefeated)) //bossdefeated I would like to set up so that the boss does not spawn in every block of the last area
	{
		en = 12;
	}*/

	return en; //if it does not end up returning a value above 0, it will return -1, which will tell the game that there is no beast
}

void Game::combat(int i)
{
	int plev = Player1.GetLevel();
	Enemies enemy(i, plev);
	int weap;
	if (Player1.HasWeapon() == true){
		weap = 10;
	}
	else{
		weap = 0;
	}

	char in;
	bool afirst = (Player1.GetSpeed() > enemy.GetESpeed());
	int attack = (Player1.GetStrength() + weap);
	int eatk = enemy.EnemyAttack();
	int n, a, g;//the 5 is just for the benefit of the beast
	int exp = enemy.GetExp();

	while (enemy.GetEHealth() > 0 && Player1.GetHealth() > 0)
	{
		HUD();
		enemy.EHUD();
		cout << endl << "Press I to use a combat item, or A to attack with your equipped weapon.\n";
		cout << "Press F to flee.\n";
		cin.get(in);
		if (in == 'a' || in == 'A')
		{
			if (afirst == true)
			{
				enemy.GetAttacked(attack);
				cout << "You attacked for " << attack << " damage.\n";
				if (enemy.GetEHealth() > 0)
				{
					Player1.GetAttacked(eatk);
					cout << enemy.GetEnemy() << " has attacked you for " << eatk << " damage.\n";
				}
				Sleep(1000);
			}
			else
			{
				Player1.GetAttacked(eatk);
				cout << enemy.GetEnemy() << " has attacked you for " << eatk << " damage.\n";
				if (Player1.GetHealth() > 0)
				{
					enemy.GetAttacked(attack);
					cout << "You attacked for " << attack << " damage.\n";
				}
				Sleep(1000);
			}
			if (!(enemy.GetEHealth() > 0))
			{
				enemy.PlayerGetLoot(n, a, g);
				Player1.AddItem(n, a);
				Player1.addremovegold(g);
				cout << "You have won this battle.\n";
				cout << "You got " << g << " gold.\n";
				cout << "You also got " << exp << " experience.\n";
				Sleep(1000);
				Player1.GainExperience(exp);
				if (enemy.GetENumber() == 12)
				{
					bossdefeated = true;
					cout << "You have defeated the evil dragon. Congratulations. This castle is now yours.\n";
					//maybe in an update, you get to keep the castle, and dink around in it.
				}
				Sleep(1000);
			}
			else if (!(Player1.GetHealth() > 0))
			{
				cout << "The " << enemy.GetEnemy() << " has defeated you.\n";
				Sleep(1000);
				cout << "You have been spawned back at the village.\n";
				lmx = lmy = smx = smy = 0;
				incombat = false;
				Player1.SetHealth(25);
				enemy.DeathByFlee();
				//kill off and delete the enemy here.
				//The enemy will actually just be destroyed at the end of this function
			}
		}
		else if (in == 'i' || in == 'I')
		{
			Player1.CombatItem();
			Player1.GetAttacked(eatk);
			if (!(Player1.GetHealth() > 0)) //if you die in combat, you are just respawned in the village
			{
				cout << "The " << enemy.GetEnemy() << "has defeated you.\n";
				cout << "You have been spawned back at the village.\n";
				lmx = lmy = smx = smy = 0;
				incombat = false;
				Player1.SetHealth(25);
				enemy.DeathByFlee();
			}
		}
		else if (in == 'f' || in == 'F')
		{
			cout << "You have been spawned back at the village. Your health has been cut in half.\n";
			lmx = lmy = smx = smy = 0;
			incombat = false;
			int hlt = Player1.GetHealth();
			hlt = hlt / 2;
			Player1.SetHealth(hlt);
			enemy.DeathByFlee();
			//kill off and delete the enemy here.
		}
		else
		{
			cout << "Incorrect input. Please try again.\n";
		}
	}

}