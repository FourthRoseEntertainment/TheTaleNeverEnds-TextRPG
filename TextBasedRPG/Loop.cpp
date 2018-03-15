#include "Loop.h"
#include <string>

Mloop::Mloop()
{
}


Mloop::~Mloop()
{
}

void Mloop::Startup()
{
	player.Startup();
	player.SetPlayerName(input.UserInput("Please enter your character's name :"));
	player.SetBackground(pch.getPlayerChoice(player.bgTypes)); //Only one currently.
	player.SetRole(pch.getPlayerChoice(player.rTypes)); //Only one currently.
	player.SetClass(pch.getPlayerChoice(player.cTypes));
	input.OutputChoice("Congratulations, you've finished your character!", NULL);
	input.OutputChoice("The bare bones anyway...  Tragically, this is as far as I've gotten.", NULL);
	input.OutputChoice("Until we meet again!", NULL);
}
void Mloop::GameLoop()
{
	while (loopExit == 0)
	{

	}
}