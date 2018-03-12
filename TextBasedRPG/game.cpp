#include "game.h"
#include "Loop.h"
int main()
{
	Mloop loop;
	loop.Startup();
	loop.GameLoop();
	return 0;
}