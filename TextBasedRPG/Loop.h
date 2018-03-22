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
	bool loopExit;
	Mplayer player;
	Minput input;
};
