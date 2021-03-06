#include "Loop.h"
#include <string>

Mloop::Mloop()
{
	Startup();
	GameLoop();
}


Mloop::~Mloop()
{
}

void Mloop::Startup()
{
	player.SetPlayerName(input.UserInput("Please enter your character's name :"));
	input.OutputChoice("What is your background?", NULL);
	player.SetBackground(PlayerChoiceHandler::getPlayerChoice(player.bgTypes)); //Only one currently.
	input.OutputChoice("What is your role?", NULL);
	player.SetRole(PlayerChoiceHandler::getPlayerChoice(player.rTypes)); //Only one currently.
	input.OutputChoice("What is your chosen class?", NULL);
	player.SetClass(PlayerChoiceHandler::getPlayerChoice(player.cTypes));
	input.OutputChoice("How would you like to determine your statistics?", NULL);
	player.SetAllocation(PlayerChoiceHandler::getPlayerChoice(player.aTypes));
	loopExit = false;
}
void Mloop::GameLoop()
{
	while (!loopExit)
	{
		player.RunStoryline();
		loopExit = player.End();
	}
}