#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <conio.h>

using namespace std;

class PlayerChoiceHandler {
public:
	static string getPlayerChoice(vector<string>);

private:
	static void displayChoices(map<char, string>);
	static char getPlayerInput(map<char, string>);
};