

#include "game.h"
#include "Loop.h"
int main()
{
	Mloop loop;
	return 0;
}

/*#include "json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using json = nlohmann::json;
int main()
{
char text[] = R"(
{
"key1":
{
"keyA":["value1","value2","value3"]
},
"key2" :
{
"keyA":["value1","value2","value3"]
},
"key3" :
{
"keyA":["value1","value2","value3"]
}
}
)";

std::vector<std::string> test;
json js = json::parse(text);
json data = js["key1"]["keyA"];
for (int i = 0; i != data.size(); i++)
{
test.push_back(data[i]);
}

std::cin.get();
return 0;
}*/