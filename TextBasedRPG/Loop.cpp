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
	player.SetBackground(input.ChoiceHandler(player.bgTypes, player.bgOptions)); //Only one currently.
	player.SetRole(input.ChoiceHandler(player.rTypes, player.rOptions)); //Only one currently.
	player.SetClass(input.ChoiceHandler(player.cTypes, player.cOptions));
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