#pragma once
#include <string>
#include <vector>

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
	void SetBackground(char passed_bg);
	void SetRole(char passed_r);
	void SetClass(char passed_c);

	void Harm(int negHP);
	void Heal(int posHP);
	void LevelUp();
	void SetStatus(int statType, int statPotency);

	//Option Values
	std::vector <std::string> bgTypes;
	std::vector <char> bgOptions;

	std::vector <std::string> rTypes;
	std::vector <char> rOptions;

	std::vector <std::string> cTypes;
	std::vector <char> cOptions;

private:
	//Plot Values
	std::string playerName;
	std::string bgType;
	std::string rType;
	std::string cType;

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

