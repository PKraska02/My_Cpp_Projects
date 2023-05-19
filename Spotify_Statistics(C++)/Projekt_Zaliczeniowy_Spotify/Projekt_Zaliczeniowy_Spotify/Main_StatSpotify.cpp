#include <iostream>
#include <list>
#include "StatSpotify.h"
#include <fstream>
using namespace std;

int main() {
	try {
		string filename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStatsDatabase.txt";
		list<SpotifyStats>SongList;
		SpotifyStats obj;
		std::cout << "Welcome in StatsSpotify!" << "\n";
		obj.Readfile(SongList, filename);
		obj.SaveDataToFile(SongList, filename);
		int i = -1;
		char y;
		while (true) {
			std::cout << "Choose list:" << "\n";
			std::cout << " If you want read help choose 0.\n";
			std::cout << " If you want use Statisticgenerator choose 1.\n";
			std::cout << " If you want exit choose 2.\n";
			std::cin >> i;
			switch (i)
			{
			case 0:
				Help();
				break;
			case 1:
				RaportsGeneratorInterface(SongList);
				break;
			case 2:
				cout << "Quitting...\n";
				return 0;
			default:
				cout << "The option you choose does not exist";
				break;
			}
		}
	}
	catch (std::runtime_error& error) {
		std::cout << "/////////////////////////\n";
		std::cout << error.what() << "\n";;
		std::cout << "/////////////////////////\n";
	}
	return 0;
}