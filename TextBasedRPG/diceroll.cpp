#include "diceroll.h"



Mdiceroll::Mdiceroll()
{
}


Mdiceroll::~Mdiceroll()
{
}

void Mdiceroll::Startup()
{
	value = 0;
	lastValue = value;
	offset = 7;
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
	do {
		
		value = rand();
		value = value / offset;
	} while (value == lastValue);
	lastValue = value;
	value = value % dType + 1;

	return value;
}


