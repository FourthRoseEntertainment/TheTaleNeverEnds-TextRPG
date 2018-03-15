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
}

void Mplayer::PopulateBackground()
{
	bgTypes.push_back("Adventurer");
}
void Mplayer::PopulateRole()
{
	rTypes.push_back("Amateur");
}
void Mplayer::PopulateClass()
{
	cTypes.push_back("Fighter");
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