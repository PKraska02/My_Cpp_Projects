#include <iostream>
#include <regex>
#include "Chess.h"
#include "Chesstranslator.h"
#include "ChessBoard.h"

using namespace std;

bool Splitdeclaratedmove(std::string &tposition ,Moveparameters &mp)
{
	std::string temp;
	temp = tposition;
	std::regex moveregex("([a-zA-Z])([a-zA-Z])(\\d)([a-zA-Z])(\\d)");
	if (std::regex_match(temp, moveregex)) {
		std::smatch what;
		std::regex_search(temp, what, moveregex);
		std::string t = what[1];
		std::string t2 = what[2];
		std::string t3 = what[4];
		mp.figuretype = t[0];
		mp.namestartposition = tolower(t2[0]);
		mp.numberstartposition = std::stoi(what[3]);
		mp.namenextposition = tolower(t3[0]);
		mp.numbernextposition = std::stoi(what[5]);
		mp.convertnamestartposition = 0;
		mp.convertnamenextposition = 0;
		return true;
	}
	else {
		cout << "Your move was write incorrect. Try again...\n";
		return false;
	}
}
void Covertlettertonumberposition(Moveparameters &moveparameters) {
	std::string temp = moveparameters.namestartposition;
	std::string temp2 = moveparameters.namenextposition;
	//std::cout << moveparameters.squarenames.size();
	for (int i = 0; i < moveparameters.squarenames.size(); i++) {
		if (temp[0] == moveparameters.squarenames[i].first) {
			moveparameters.convertnamestartposition = moveparameters.squarenames[i].second;
		}
		if (temp2[0] == moveparameters.squarenames[i].first) {
			moveparameters.convertnamenextposition = moveparameters.squarenames[i].second;
		}
	}
}


