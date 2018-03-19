#pragma once
#include <vector>
#include <time.h>
#include <stdlib.h>

class Mdiceroll
{
public:
	Mdiceroll();
	~Mdiceroll();

	void Startup();
	std::vector<int> DiceRoller(int dType, int dQty);
	int Roll(int dType);

private:
	std::vector<int> dice;
	int value;
	int lastValue;
	int offset;
};

