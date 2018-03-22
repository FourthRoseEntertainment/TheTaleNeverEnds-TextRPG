#include "storyhandler.h"

Mstoryhandler::Mstoryhandler()
{
	Startup();
}

Mstoryhandler::~Mstoryhandler()
{
}

void Mstoryhandler::Startup()
{
}

std::vector<std::string> Mstoryhandler::LoadOptions(std::string selection)
{
	std::ifstream optionLdr("optionLdr.json");
	json js = json::parse(optionLdr);
	std::vector<std::string> option;
	json data = js[selection]["List"];
	for (int i = 0; i != data.size(); i++)
	{
		option.push_back(data[i]);
	}
	return option;
}

std::vector<int> Mstoryhandler::LoadClass(std::string cType)
{
	std::ifstream classLdr("classLdr.json");
	json js = json::parse(classLdr);
	std::vector<int> option;
	json data = js[cType]["stat"];
	for (int i = 0; i != data.size(); i++)
	{
		option.push_back(data[i]);
	}
	return option;
}

std::vector < std::string > Mstoryhandler::LoadClassEquips(std::string cType, std::string type)
{
	std::ifstream classLdr("classLdr.json");
	json js = json::parse(classLdr);
	std::vector<std::string> option;
	json data = js[cType][type];
	for (int i = 0; i != data.size(); i++)
	{
		option.push_back(data[i]);
	}
	return option;
}

void Mstoryhandler::storyDisplay(std::string fType, std::string tag) 
{
	std::ifstream textFile;
	std::string line;
	std::string previousLine;

	textFile.open(fType+".txt");
	if (!textFile.is_open()) { std::cout << "OPEN FAILED!"; }
	while (getline(textFile, line))
	{
		if (previousLine == tag)
		{
			std::cout << "\t" << line << std::endl;
			break;
		}
		previousLine = line;
	}
	textFile.close();
	
}