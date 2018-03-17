#include "PlayerChoiceHandler.h"

// Given a list of choices, get player to choose one via a keyboard mapping
string PlayerChoiceHandler::getPlayerChoice(vector<string> choiceList)
{
	if (choiceList.size() < 1) throw invalid_argument("Not enough choices");
	if (choiceList.size() > 26) throw invalid_argument("More choices than keyboard keys");
	map<char, string> choiceMap;
	// set of choices which have already been assigned
	set<string> assigned;

	// 1) Decide character -> string mapping

	// First pass: Go through the choices, and use their first letter, if we can
	for (string choice : choiceList) {
		// try the first character
		char firstChar = toupper(choice.front());
		// check if first character is already mapped
		if (choiceMap.find(firstChar) == choiceMap.end()) {
			choiceMap[firstChar] = choice;
			assigned.insert(choice);
		}
	}

	// Second pass: Go through the choices, and use an available letter from their word, if we can
	for (string choice : choiceList) {
		// check if already assigned
		if (assigned.find(choice) != assigned.end()) continue;
		// try each letter of the word
		for (char letter : choice) {
			char upLetter = toupper(letter);
			if (choiceMap.find(upLetter) == choiceMap.end())
			{
				choiceMap[upLetter] = choice;
				assigned.insert(choice);
				break;
			}
		}
	}

	// Final pass: Use an arbitrary letter from the alphabet
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (string choice : choiceList) {
		// check if already assigned
		if (assigned.find(choice) != assigned.end()) continue;
		// try each character of alphabet
		for (char letter : alphabet) {
			if (choiceMap.find(letter) == choiceMap.end()) {
				choiceMap[letter] = choice;
				break;
			}
		}
	}

	// 2) Display choices to user
	displayChoices(choiceMap);

	// 3) Request input from user, and return
	return choiceMap[getPlayerInput(choiceMap)];
}

// Display keyboard keys and choices in user-friendly way
void PlayerChoiceHandler::displayChoices(map<char, string> choiceMap)
{
	// In the special case of yes/no, we don't want to print in alphabetical order
	if (choiceMap.size() == 2) {
		if (choiceMap.find('Y') != choiceMap.end() && choiceMap['Y'] == "Yes" &&
			choiceMap.find('N') != choiceMap.end() && choiceMap['N'] == "No") {
			cout << "Y : Yes" << endl;
			cout << "N : No" << endl;
			return;
		}
	}
	cout << "Choices:" << endl;
	for (pair<char, string> p : choiceMap)
		cout << p.first << " : " << p.second << endl;
}

// Get valid key press from user
char PlayerChoiceHandler::getPlayerInput(map<char, string> choiceMap)
{
	while (char tempInput = toupper(_getch()))
	{
		if (choiceMap.find(tempInput) != choiceMap.end())
			return choiceMap.find(tempInput)->first;
		cout << "Your entry (" << tempInput << ") does not match the options, please try again!" << endl;
	}
}
