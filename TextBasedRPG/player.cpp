#include "player.h"



Mplayer::Mplayer()
{
}


Mplayer::~Mplayer()
{
}

void Mplayer::Startup()
{
	PopulateBackground();
	PopulateRole();
	PopulateClass();
}

void Mplayer::SetPlayerName(std::string passed_name)
{
	playerName = passed_name;
}
void Mplayer::SetBackground(char passed_bg)
{
	for (unsigned int i = 0; i < bgOptions.size(); i++)
	{
		if (bgOptions[i] == passed_bg)
		{
			bgType = bgTypes[i];
		}
	}
}
void Mplayer::SetRole(char passed_r)
{
	for (unsigned int i = 0; i < rOptions.size(); i++)
	{
		if (rOptions[i] == passed_r)
		{
			rType = rTypes[i];
		}
	}
}
void Mplayer::SetClass(char passed_c)
{
	for (unsigned int i = 0; i < cOptions.size(); i++)
	{
		if (cOptions[i] == passed_c)
		{
			cType = cTypes[i];
		}
	}
}

void Mplayer::PopulateBackground()
{
	bgTypes.push_back("Adventurer");
	bgOptions.push_back('a');
}
void Mplayer::PopulateRole()
{
	rTypes.push_back("Amateur");
	rOptions.push_back('a');
}
void Mplayer::PopulateClass()
{
	cTypes.push_back("Fighter");
	cOptions.push_back('f');
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