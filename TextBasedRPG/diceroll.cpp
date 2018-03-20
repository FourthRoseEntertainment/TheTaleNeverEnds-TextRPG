#include "diceroll.h"
#include <iostream>



Mdiceroll::Mdiceroll()
{
	Startup();
}


Mdiceroll::~Mdiceroll()
{
}

void Mdiceroll::Startup()
{
	srand((int)time(0));
}
std::vector<int> Mdiceroll::DiceRoller(int dType, int dQty)
{
	dice.clear();
	for (int i = 0; i < dQty; i++)
	{
		dice.push_back(Roll(dType));
	}
	return dice;
}

int Mdiceroll::Roll(int dType)
{
	value = (rand() % dType) + 1;
	return value;
}


