#pragma once
#include "json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Mstoryhandler
{
public:
	Mstoryhandler();
	~Mstoryhandler();
	void Startup();
	std::vector<std::string> LoadOptions(std::string selection);
	std::vector<int> LoadClass(std::string cType);
	std::vector<std::string> LoadClassEquips(std::string cType, std::string type);
	void storyDisplay(std::string cType/*<cType/CLASS><rType/ROLE><bgType/Background>*/, std::string tag/*<"STORY_BEGIN"><"ROLE_ONE"><"BG_TWO">*/);

private:
	std::ifstream classLdr;
	std::ifstream equipLdr;
	std::ifstream saveLdr;
	using json = nlohmann::json;

	json js;
};

