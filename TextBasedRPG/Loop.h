#pragma once
#include "player.h"
#include "input.h"
#include "PlayerChoiceHandler.h"

class Mloop
{
public:
	Mloop();
	~Mloop();
	void Startup();
	void GameLoop();

private:
	int loopExit = 0;
	Mplayer player;
	Minput input;
	PlayerChoiceHandler pch;
};
