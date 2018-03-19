#pragma once
#include "diceroll.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "PlayerChoiceHandler.h"

class Mplayer
{
public:
	Mplayer();
	~Mplayer();

	void Startup();
	void PopulateBackground();
	void PopulateRole();
	void PopulateClass();

	void SetPlayerName(std::string passed_name);
	void SetBackground(std::string passed_bg);
	void SetRole(std::string passed_r);
	void SetClass(std::string passed_c);
	void SetAllocation(std::string passed_a);
	void Allocate(std::vector<int> passed_statAllocation);
	std::vector<int> SortAllocation(std::vector<int> passed_aTypes);

	void Harm(int negHP);
	void Heal(int posHP);
	void LevelUp();
	void SetStatus(int statType, int statPotency);

	//Option Values
	std::vector <std::string> bgTypes;
	std::vector <std::string> rTypes;
	std::vector <std::string> cTypes;
	std::vector <std::string> aTypes;
	std::vector<int> statAllocation = { 0,0,0,0,0,0 };

private:
	Mdiceroll dice;

	//Plot Values
	std::string playerName;
	std::string bgType;
	std::string rType;
	std::string cType;
	std::string aType;

	//Longevity Values
	int healthPoints;
	int spellSlots;

	//Statistic Values
	int strStat;
	int dexStat;
	int conStat;
	int chaStat;
	int intStat;
	int wisStat;
};

