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
	std::ifstream optionLdr;
	optionLdr.open("optionLdr.JSON");
	if (!optionLdr.is_open()) { std::cout << "Options Failed to Load!" << std::endl; }
	optionLdr >> js;
	optionLdr.close();
}

std::vector<std::string> Mstoryhandler::LoadOptions(std::vector<std::string> option, bool bg, bool r , bool c)
{
	if (bg)
	{
		//option = js.get < std::string "Background"::std::string "List";
	}
	else
	{if(r){
		//option = js.get < std::string "Background"::std::string "List";
	}
	else {
		if (c) {
			//option = js.get < std::string "Background"::std::string "List";
		}
		else
		{
			return option;
		}
	} }
}