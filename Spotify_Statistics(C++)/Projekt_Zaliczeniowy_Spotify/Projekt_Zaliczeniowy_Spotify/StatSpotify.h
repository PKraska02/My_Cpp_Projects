///StatsSpotify.h @file
#pragma once
#include <iostream>
#include <list>
#include <vector>
/// @copyright 
/// Copyrigth 2023 Piotr Kraska 
/// @brief Klasa zawierajaca typy parametrow:
/// @param Author_name Imie Autora.
/// @param Author_lastname Nazwisko Autora.
/// Author_name i Author_last name sa rowniez uzywane do zapisu pseudonimow artystycznych.
/// @param Title Nazwa utworu
/// @param Continent Region swiata.
/// @param playscount Ilosc odsluchan
/// @param Songtime Dlugosc piosenki
/// 
class SpotifyStats {
	std::string Author_name;
	std::string Author_lastname;
	std::string Title;
	std::string Continent;
	int playscount = 0;
	double Songtime = 0;

public:
	/// @brief Funkcja odczytujaca z pliku bazy danych parametry piosenek.
	/// @param spotifystatslist Lista z parametrami.
	/// @param fl Sciezka do pliku bazy danych.
	/// @return True jesli wszystko zadziala poprawnie, false gdy cos pojdzie nie tak
	bool Readfile(std::list<SpotifyStats> &spotifystatslist,std::string &fl);
	/// @brief Funkcja zapisujaca do pliku bazy danych.
	/// @param spotifystatslist Lista z parametrami.
	/// @param fl Sciezka do pliku.
	void SaveDataToFile(std::list<SpotifyStats>& spotifystatslist,std::string &fl);
	/// @brief Funkcja generujaca raport ze statystykami piosenek.
	/// @param spotifystatslist lista piosenek.
	/// @param fl Sciezka do pliku.
	/// @param reg Region z ktorego chcemy wygenerowac raport.
	void GenerateReport(std::list<SpotifyStats>& spotifystatslist, std::string& fl, std::string& reg);
	/// @brief Funkcja wyznaczajaca najpopularniejszego artyste.
	/// @param spotifystatslist Lista piosenek.
	/// @return Wektor par imienia i nazwiska autora oraz sumy wyswietlen.
	std::vector<std::pair<std::string, int>> MostPopularArtist(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja wyznaczajaca najmniej popularnego artyste.
	/// @param spotifystatslist lista piosenek.
	/// @return Wektor par imienia i nazwiska autora oraz sumy wyswietlen.
	std::vector<std::pair<std::string, int>> LeastPopularArtist(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja wyznaczajaca najpopularniejsza piosenke.
	/// @param spotifystatslist Lista piosenek.
	/// @return Wektor zawierajacy dane o Autorze najpopularniejszej piosenki.
	std::vector<SpotifyStats> MostPopularSong(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja wyznaczajaca najmniej popularna piosenke.
	/// @param spotifystatslist Lista piosenek.
	/// @return Wektor zawierajacy dane o Autorze najmniej popularniej piosenki.
	std::vector<SpotifyStats> LeastPopularSong(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja sortujaca Artystow wzgledem odsluchan ich piosenek.
	/// @param spotifystatslist Lista piosenek.
	/// @return Posortowana liste piosenek.
	std::list<SpotifyStats> ArtistSorter(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja wyznaczajaca srednia arytmetyczna odsluchan.
	/// @param spotifystatslist Lista piosenek.
	/// @return Wartosc sredniej arytmetycznej.
	int ArithmeticMeanOfListens(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja wyznaczajaca wspolczynniki korelacji rang Spearmana miedzy regionem a iloscia odsluchan.
	/// @param spotifystatslist Lista piosenek.
	/// @return Wartosc wspolczynnika korelacji.
	double SpearmanKorelation(std::list<SpotifyStats>& spotifystatslist);
	/// @brief Funkcja interfejsu wyswietlajaca nam opcje generowania raportow.
	/// @param spotifystatslist Lista piosenek.
	friend void RaportsGeneratorInterface(std::list<SpotifyStats>& spotifystatslist);
};
/// @brief Funkcja wyswietlajaca nam pomoc.
void Help();