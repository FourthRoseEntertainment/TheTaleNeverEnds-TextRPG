#pragma once
#include "diceroll.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "PlayerChoiceHandler.h"
#include "storyhandler.h"

class Mplayer
{
public:
	Mplayer();
	~Mplayer();

	void Startup();

	void SetPlayerName(std::string passed_name);
	void SetBackground(std::string passed_bg);
	void SetRole(std::string passed_r);
	void SetClass(std::string passed_c);
	void SetAllocation(std::string passed_a);
	void Allocate(std::vector<int> passed_statAllocation);
	void RunStoryline();
	bool End();
	std::vector<int> SortAllocation(std::vector<int> passed_aTypes);

	void Harm(int negHP);
	void Heal(int posHP);
	void LevelUp();
	void SetStatus(int statType, int statPotency);
	//Option Values
	std::vector <std::string> bgTypes;
	std::vector <std::string> rTypes;
	std::vector <std::string> cTypes;
	std::vector <std::string> aTypes = { "Roll","Preset" };
	std::vector<int> statAllocation = { 0,0,0,0,0,0 };

private:
	Mdiceroll dice;
	Mstoryhandler story;

	//Plot Values
	std::string playerName;
	std::string bgType;
	std::string rType;
	std::string cType;
	std::string aType;
	std::vector<std::string> storyboard = { "STORY_BEGIN", "STORY_ONE", "STORY_TWO", "STORY_THREE" };
	int sbIt; //Holds iteration of storyboard to accept specific scenes in order.
	std::vector<std::string> roleboard = { "ROLE_BEGIN", "ROLE_ONE", "ROLE_TWO", "ROLE_THREE" };
	int rIt; //Holds iteration of storyboard to accept specific scenes in order.
	std::vector<std::string> bgboard = { "BG_BEGIN", "BG_ONE", "BG_TWO", "BG_THREE" };
	int bgIt; //Holds iteration of storyboard to accept specific scenes in order.

	//Longevity Values
	int healthPoints;
	int spellSlots;

	//Statistic Values
	int armorRating;
	int strStat;
	int dexStat;
	int conStat;
	int chaStat;
	int intStat;
	int wisStat;

	//equipment Values
	std::vector<std::string> armorTypes;
	std::vector<std::string> weaponTypes;
};

