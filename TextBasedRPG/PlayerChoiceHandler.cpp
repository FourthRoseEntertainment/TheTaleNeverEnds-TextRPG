#include "PlayerChoiceHandler.h"

// Given a list of choices, get player to choose one via a keyboard mapping
string PlayerChoiceHandler::getPlayerChoice(vector<string> choiceList)
{
	if (choiceList.size < 1) throw invalid_argument("Not enough choices");
	if (choiceList.size > 26) throw invalid_argument("More choices than keyboard keys");

	// Decide character -> string mapping
	map<char, string> choiceMap;
	vector<string> remainder;

	// First pass: Go through the choices, and use their first letter if we can
	for (Vector<string>::iterator it = choiceList.first(); it != choiceList.end(); ++it) {
		// Try the first character
		char firstChar = *it[0];
		if (choiceMap.find(firstChar) != choiceMap.end()) {
			choiceMap[firstChar] = *it;
			continue;
		}
		else {
			remainder.push_back(*it);
		}
	}
	// Second pass: Go through the choices we failed to assign, and just pick the first available alphabet character
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (vector<string>::iterator it = remainder.first(); it != remainder.end(); ++it) {
		for (string::iterator it2 = alphabet.first(); it2 != alphabet.end(); ++it2) {
			if (choiceMap.find(*it2) != choiceMap.end()) {
				choiceMap[*it2] = *it;
				break;
			}
		}
	}

	// Display choices to user
	displayChoices(&choiceMap);

	// Request input from user, and return
	return choiceMap[getPlayerInput(&choiceMap)];
}

// Display keyboard keys and choices in user-friendly way
void PlayerChoiceHandler::displayChoices(map<char, string> choiceMap)
{
	cout << "Choices:" << endl;
	for (map<char, string>::iterator it = choiceMap.begin(); it != choiceMap.end(); ++it)
		cout << *it << " : " << choiceMap[*it] << endl;
}

// Get valid key press from user
char PlayerChoiceHandler::getPlayerInput(map<char, string> choiceMap)
{
	while (1)
	{
		char tempInput = _getch();
		if (choiceMap.find(char) != choiceMap.end())
			return choiceMap[char];
		cout << "Your entry (" << tempInput << ") does not match the options, please try again!" << endl;
	}
}
