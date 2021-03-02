#include "Save.h"
#include "Player.h"

void Save::SetFileName()
{
	IOFile = playersave.GetName() + ".dat";
}

void Save::SaveFile() //These don't work, but it's just sort of the idea I've had to save and load important information.
{
	inFile.open(IOFile);
	inFile << playersave.GetName() << ' ' << playersave.GetHealth() << ' ' << playersave.GetStamina() << ' ' << playersave.GetSpeed() << ' '
		<< playersave.GetStrength() << ' ' << playersave.GetLevel() << ' ' << playersave.GetMoney() << ' ';
		//<< playersave.inventory << ' ' << playersave.perks;Gotta figure this out.
}

void Save::LoadFile()
{
	inFile.open(IOFile);
	/*inFile >> playersave.SetName() >> playersave.health() >> playersave.stamina >> playersave.speed >> playersave.strength >> playersave.level
		>> playersave.level >> playersave.money >> playersave.inventory >> playersave.perks;*/
	//Gotta get this so that it reads in the strings and integers and sets them. Probably use a Set function for the attributes.
}