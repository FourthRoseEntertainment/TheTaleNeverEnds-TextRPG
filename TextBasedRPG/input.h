#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include "PlayerChoiceHandler.h"

class Minput
{
public:
	Minput();
	~Minput();

	//User Entry return
	bool Confirmation();
	std::string UserInput(std::string passed_output);
	void OutputChoice(std::string output, char input);
	void OutputChoice(std::vector<std::string> output, std::vector<char> input);
	char InputChoice(std::vector<char> input);
	/*
	//Multiple options
	char ChoiceHandler(std::vector<std::string> output, std::vector<char> input);

	//Single options
	char ChoiceHandler(std::string output, char input);
	char InputChoice(char input);
	*/

private:

};

