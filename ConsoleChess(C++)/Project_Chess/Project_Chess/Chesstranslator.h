#pragma once
#include <string>
struct Moveparameters {
	char figuretype{};
	std::string namestartposition{};
	int convertnamestartposition{};
	int numberstartposition{};
	std::string namenextposition{};
	int numbernextposition{};
	int convertnamenextposition{};
	std::vector<std::pair<char, int>>squarenames{ {'a',0},{'b',1},{'c',2},{'d',3},{'e',4},{'f',5},{'g',6},{'h',7} };
};
bool Splitdeclaratedmove(std::string &tposition, Moveparameters& mp);
void Covertlettertonumberposition(Moveparameters &moveparameters);

