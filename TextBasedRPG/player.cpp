#include "player.h"

Mplayer::Mplayer()
{
	Startup();
}


Mplayer::~Mplayer()
{

}

void Mplayer::Startup()
{
	strStat = 0;
	dexStat = 0;
	conStat = 0;
	chaStat = 0;
	intStat = 0;
	wisStat = 0;
	bgTypes = story.LoadOptions("background");
	rTypes = story.LoadOptions("role");
	cTypes = story.LoadOptions("class");
}

void Mplayer::SetPlayerName(std::string passed_name)
{
	playerName = passed_name;
}

void Mplayer::SetBackground(std::string passed_bg)
{
	bgType = passed_bg;
}

void Mplayer::SetRole(std::string passed_r)
{
	rType = passed_r;
}

void Mplayer::SetClass(std::string passed_c)
{
	cType = passed_c;
	statAllocation = story.LoadClass(cType);
	Allocate(statAllocation);
	armorTypes = story.LoadClassEquips(cType,"armor");
	weaponTypes = story.LoadClassEquips(cType, "weapon");
}

void Mplayer::SetAllocation(std::string passed_a)
{
	if (passed_a == "Roll")
	{
		aType = "Roll";
		for (std::vector<int>::iterator it = statAllocation.begin(); it < statAllocation.end(); it++)
		{
			int total = 0;
			int lowest = 7;
			std::vector<int> temp = dice.DiceRoller(6, 4);
			for (std::vector<int>::iterator itr = temp.begin(); itr < temp.end(); itr++)
			{
				if (*itr < lowest) {lowest = *itr; }
				total = total + *itr;
			}
			*it = total - lowest;
		}
	}
	else
	{
		aType = "Preset";
		statAllocation = { 8, 10, 12, 13, 14, 15 };
	}
	SortAllocation(statAllocation);
	Allocate(statAllocation);
}

void Mplayer::Allocate(std::vector<int> passed_statAllocation)
{
	strStat = strStat + passed_statAllocation[0];
	dexStat = dexStat + passed_statAllocation[1];
	conStat = conStat + passed_statAllocation[2];
	chaStat = chaStat + passed_statAllocation[3];
	intStat = intStat + passed_statAllocation[4];
	wisStat = wisStat + passed_statAllocation[5];
	std::cout << "Strength:\t" << strStat << std::endl;
	std::cout << "Dexterity:\t" << dexStat << std::endl;
	std::cout << "Constitution:\t" << conStat << std::endl;
	std::cout << "Charisma:\t" << chaStat << std::endl;
	std::cout << "Intellect:\t" << intStat << std::endl;
	std::cout << "Wisdom:\t\t" << wisStat << std::endl;
}


void Mplayer::Harm(int negHP)
{

}
void Mplayer::Heal(int posHP)
{

}
void Mplayer::LevelUp()
{

}
void Mplayer::SetStatus(int statType, int statPotency)
{

}

std::vector<int> Mplayer::SortAllocation(std::vector<int> passed_statAllocation)
{
	int strV = 0;
	int dexV = 0;
	int conV = 0;
	int chaV = 0;
	int intV = 0;
	int wisV = 0;
	bool confirmed = false;
	std::vector<int> temp_statAllocation;
	std::vector<string> statistics = { "Strength", "Dexterity", "Constitution", "Charisma", "Intellect", "Wisdom" };
	do
	{
		temp_statAllocation = passed_statAllocation;
		for (std::vector<int>::iterator it = temp_statAllocation.begin(); it != temp_statAllocation.end(); it++)
		{
			bool valid;
			do
			{
				valid = true;
				std::cout << "What would you like to assign the score " << *it << " towards?" << std::endl;
				std::string temp = PlayerChoiceHandler::getPlayerChoice(statistics);
				if (temp == "Strength")
				{
					if (strV > 0) { std::cout << "Strength has already been selected." << std::endl; valid = false; }
					else
					{
						temp_statAllocation[0] = *it;
						strV++;
					}
				}
				if (temp == "Dexterity")
				{
					if (dexV > 0) { std::cout << "Dexterity has already been selected." << std::endl; valid = false;}
					else
					{
						temp_statAllocation[1] = *it;
						dexV++;
					}
				}
				if (temp == "Constitution")
				{
					if (conV > 0) { std::cout << "Constitution has already been selected." << std::endl; valid = false;}
					else
					{
						temp_statAllocation[2] = *it;
						conV++;
					}
				}
				if (temp == "Charisma")
				{
					if (chaV > 0) { std::cout << "Charisma has already been selected." << std::endl;  valid = false; }
					else
					{
						temp_statAllocation[3] = *it;
						chaV++;
					}
				}
				if (temp == "Intellect")
				{
					if (intV > 0) { std::cout << "Intellect has already been selected." << std::endl;  valid = false; }
					else
					{
						temp_statAllocation[4] = *it;
						intV++;
					}
				}
				if (temp == "Wisdom")
				{
					if (wisV > 0) { std::cout << "Wisdom has already been selected." << std::endl; valid = false; }
					else
					{
						temp_statAllocation[5] = *it;
						wisV++;
					}
				}
			}while (!valid);
		}
		std::vector<string> confirm = { "Yes", "No" };
		std::string isconfirmed = PlayerChoiceHandler::getPlayerChoice(confirm);
		if (isconfirmed == "Yes") { confirmed = true; }
	} while (!confirmed);
	return temp_statAllocation;
}