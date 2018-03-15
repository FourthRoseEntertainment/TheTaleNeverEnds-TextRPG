#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PlayerChoiceHandler {
public:
	static string getPlayerChoice(vector<string>);

private:
	static void displayChoices(map<char, string>);
	static char getPlayerInput(map<char, string>);
};