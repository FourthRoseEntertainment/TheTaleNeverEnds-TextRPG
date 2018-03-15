#include "PlayerChoiceHandler.h"

// Given a list of choices, get player to choose one via a keyboard mapping
string PlayerChoiceHandler::getPlayerChoice(vector<string> choiceList)
{
	if (choiceList.size() < 1) throw invalid_argument("Not enough choices");
	if (choiceList.size() > 26) throw invalid_argument("More choices than keyboard keys");
	// Decide character -> string mapping
	map<char, string> choiceMap;
	vector<string> remainder;
	// First pass: Go through the choices, and use their first letter if we can
	for (vector<string>::iterator it = choiceList.begin(); it != choiceList.end(); ++it) {
		// Try the first character
		char firstChar = (*it)[0];
		if (choiceMap.find(firstChar) == choiceMap.end()) {
			choiceMap[firstChar] = *it;
			continue;
		}
		else {
			remainder.push_back(*it);
		}
	}
	// Second pass: Go through the choices we failed to assign, and just pick the first available alphabet character
	int y = 0;
	for (vector<string>::iterator it = remainder.begin(); it != remainder.end(); ++it,y++) {
		string temp = *it;
		for (int i = 0; i < remainder[y].size(); i++)
		{
			char tempC = toupper(temp[i]);
			if (choiceMap.find(tempC) == choiceMap.end())
			{
				choiceMap[tempC] = *it;
				break;
			}
			if (i == (remainder[y].size() - 1))
			{
				string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				for (string::iterator it2 = alphabet.begin(); it2 != alphabet.end(); ++it2) {
					if (choiceMap.find(toupper(*it2)) == choiceMap.end()) {
						choiceMap[toupper(*it2)] = *it;
						break;
					}
				}
			}
		}
	}
	// Display choices to user
	displayChoices(choiceMap);

	// Request input from user, and return
	return choiceMap[getPlayerInput(choiceMap)];
}

// Display keyboard keys and choices in user-friendly way
void PlayerChoiceHandler::displayChoices(map<char, string> choiceMap)
{
	cout << "Choices:" << endl;
	for (map<char, string>::iterator it = choiceMap.begin(); it != choiceMap.end(); ++it)
		cout << it->first << " : " << it->second << endl;
}

// Get valid key press from user
char PlayerChoiceHandler::getPlayerInput(map<char, string> choiceMap)
{
	while (char tempInput = _getch())
	{
		if (choiceMap.find(toupper(tempInput)) != choiceMap.end())
		{
			map<char, string>::iterator it = choiceMap.begin();
			it = choiceMap.find(toupper(tempInput));
			return it->first;
		}
		cout << "Your entry (" << toupper(tempInput) << ") does not match the options, please try again!" << endl;
	}
}
