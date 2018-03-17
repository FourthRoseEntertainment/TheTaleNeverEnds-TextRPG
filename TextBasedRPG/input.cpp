#include "input.h"

Minput::Minput()
{
}

Minput::~Minput()
{
}

bool Minput::Confirmation()
{
	std::vector<std::string> yesno = { "Yes", "No" };
	OutputChoice(" - Is this correct?", NULL);
	string choice = PlayerChoiceHandler::getPlayerChoice(yesno);
	if (choice == "Yes") return true;
	if (choice == "No") return false;
}

std::string Minput::UserInput(std::string passed_output)
{
	std::string tempString;
	do
	{
		OutputChoice(passed_output, NULL);
		tempString = "";
		std::getline(std::cin, tempString);
		std::cout << std::endl << tempString;

	} while (!Confirmation());

	return tempString;
}

char Minput::InputChoice(std::vector<char> input)
{
	bool restart = true;
	while (restart)
	{
		char tempInput = NULL;
		tempInput = _getch();
		for (unsigned int i = 0; i < input.size(); i++)
		{
			if (input[i] == toupper(tempInput)) { return toupper(tempInput); }
		}
		std::cout << "Your entry (" << tempInput << ") does not match the options, please try again!" << std::endl;
	}
	return NULL;
}

void Minput::OutputChoice(std::string output, char input)
{
	if (input == NULL)
	{
		std::cout << output << std::endl;
	}
	else
	{
		std::cout << output << " : " << input << std::endl;
	}
}

void Minput::OutputChoice(std::vector<std::string> output, std::vector<char> input)
{
	for (unsigned int i = 0; i < output.size(); i++)
	{
		std::cout << "Please input (" << input[i] << ") for " << output[i] << std::endl;
	}
}

/*char Minput::ChoiceHandler(std::vector<std::string> output, std::vector<char> input)
{
	OutputChoice(output, input);
	return InputChoice(input);
}


char Minput::ChoiceHandler(std::string output, char input)
{
	OutputChoice(output, input);
	return InputChoice(input);
}

char Minput::InputChoice(char input)
{
	std::cout << "Just one option?" << std::endl;
	bool restart = true;
	while (restart)
	{
		char tempInput = _getch();
		if (tempInput == input) { return tempInput; }
		else
		{
			tempInput = NULL;
			std::cout << "Your entry does not match the options, please try again!" << std::endl;
			break;
		}
	}
	return NULL;
}*/