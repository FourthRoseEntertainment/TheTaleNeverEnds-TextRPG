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
	std::vector<std::string> LoadOptions(std::vector<std::string> option, bool bg, bool r, bool c);

private:
	std::ifstream classLdr;
	std::ifstream equipLdr;
	std::ifstream saveLdr;
	using json = nlohmann::json;

	json js;
};

