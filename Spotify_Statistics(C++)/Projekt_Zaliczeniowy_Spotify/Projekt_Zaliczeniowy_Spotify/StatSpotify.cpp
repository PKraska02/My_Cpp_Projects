#include "StatSpotify.h"
#include <list>
#include <fstream>
#include <regex>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;

bool SpotifyStats::Readfile(std::list<SpotifyStats>& spotifystatslist, std::string& fl)
{
	std::string temp;
	std::regex songpattern("([a-zA-Z]+)\\s+([a-zA-Z]+)\\s+([a-zA-Z]+)\\s+(\\w+)\\s+(\\d+)\\s(\\d+[.]\\d+)");
	ifstream readfile(fl);
	if (readfile.is_open()) {
		while (getline(readfile,temp))
		{
			if (regex_match(temp, songpattern)) {
				std::smatch wut;
				SpotifyStats spotifystats;
				std::regex_search(temp, wut, songpattern);

				spotifystats.Author_name = wut[1];
				spotifystats.Author_lastname = wut[2];
				spotifystats.Title = wut[3];
				spotifystats.Continent = wut[4];
				spotifystats.playscount = std::stoi(wut[5]);
				spotifystats.Songtime = std::stod(wut[6]);
				spotifystatslist.push_back(spotifystats);
			}
			else {
				throw std::runtime_error("Bledny szablon lub zle zapisane dane w pliku");
			}

		}
		return true;
	}
	else {
		throw std::runtime_error("Plik nie zosta³ otwarty");
	}
}

void SpotifyStats::SaveDataToFile(std::list<SpotifyStats>& spotifystatslist,std::string &fl)
{
	std::string temp;
	ofstream savefile(fl);
	std::list<SpotifyStats>::iterator it;
	for (it = spotifystatslist.begin(); it != spotifystatslist.end(); it++) {
		savefile << it->Author_name <<" " << it->Author_lastname <<" " << it->Title <<" " << it->Continent << " " << it->playscount << " " << it->Songtime << "\n";
	}
}

void SpotifyStats::GenerateReport(std::list<SpotifyStats>& spotifystatslist, std::string& fl, std::string& reg)
{
	std::string temp;
	ofstream savefile(fl);
	std::list<SpotifyStats>::iterator it;
	std::vector<SpotifyStats>v_mls = MostPopularSong(spotifystatslist);
	std::vector<SpotifyStats>v_lps = LeastPopularSong(spotifystatslist);
	std::vector<std::pair<std::string, int>> v_buf = MostPopularArtist(spotifystatslist);
	std::vector<std::pair<std::string, int>> v_buf2 = LeastPopularArtist(spotifystatslist);
	double x = SpearmanKorelation(spotifystatslist);
	std::list<SpotifyStats>list_buf;
	if (reg != "WorldWide") {
		savefile << "Report from " << reg << "\n";
		savefile << "\n";
		savefile << "Author/s with the most listens: \n";
		for (int i = 0; i < v_buf.size(); i++) {
			savefile << "Author: " << v_buf[i].first << "  Number of listens: " << v_buf[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Author/s with least listens: \n";
		for (int i = 0; i < v_buf2.size(); i++) {
			savefile << "Author: " << v_buf2[i].first << "  Number of listens: " << v_buf2[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Song with most listens: \n";
		for (int i = 0; i < v_mls.size(); i++) {
			savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
		}
		savefile << "\n";
		savefile << "Song with least listens: \n";
		for (int i = 0; i < v_lps.size(); i++) {
			savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
		}
		savefile << "\n";
		savefile << "Arithmetic mean of listens: " << ArithmeticMeanOfListens(spotifystatslist) << "\n";
	}
	else {
		savefile << "Report from " << reg << "\n";
		savefile << "\n";
		savefile << "Author/s with the most listens: \n";
		for (int i = 0; i < v_buf.size(); i++) {
			savefile << "Author: " << v_buf[i].first << "  Number of listens: " << v_buf[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Author/s with least listens: \n";
		for (int i = 0; i < v_buf2.size(); i++) {
			savefile << "Author: " << v_buf2[i].first << "  Number of listens: " << v_buf2[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Song with most listens: \n";
		for (int i = 0; i < v_mls.size(); i++) {
			savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
		}
		savefile << "\n";
		savefile << "Song with least listens: \n";
		for (int i = 0; i < v_lps.size(); i++) {
			savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
		}
		savefile << "\n";
		//EU
		savefile << "Author/s with the most listens in EU: \n";
		for (auto x : spotifystatslist) {
			if (x.Continent == "EU") {
				list_buf.push_back(x);
			}
		}
		savefile << "\n";
		std::vector<std::pair<std::string, int>>vregsmax = MostPopularArtist(list_buf);
		std::vector<std::pair<std::string, int>>vregsmin = LeastPopularArtist(list_buf);
		v_mls = MostPopularSong(list_buf);
		v_lps = LeastPopularSong(list_buf);
		for (int i = 0; i < vregsmax.size(); i++) {
			savefile << "Author: " << vregsmax[i].first << "  Number of listens: " << vregsmax[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Author/s with least listens in EU: \n";
		for (int i = 0; i < vregsmin.size(); i++) {
			savefile << "Author: " << vregsmin[i].first << "  Number of listens: " << vregsmin[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Song with most listens in EU: \n";
		for (int i = 0; i < v_mls.size(); i++) {
			savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
		}
		savefile << "\n";
		savefile << "Song with least listens in EU: \n";
		for (int i = 0; i < v_lps.size(); i++) {
			savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
		}
		savefile << "\n";
		list_buf.clear();
		//NA
		savefile << "Author/s with the most listens in NA: \n";
		for (auto x : spotifystatslist) {
			if (x.Continent == "NA") {
				list_buf.push_back(x);
			}
		}
		savefile << "\n";
		vregsmax = MostPopularArtist(list_buf);
		vregsmin = LeastPopularArtist(list_buf);
		v_mls = MostPopularSong(list_buf);
		v_lps = LeastPopularSong(list_buf);
		for (int i = 0; i < vregsmax.size(); i++) {
			savefile << "Author: " << vregsmax[i].first << "  Number of listens: " << vregsmax[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Author/s with least listens in NA: \n";
		for (int i = 0; i < vregsmin.size(); i++) {
			savefile << "Author: " << vregsmin[i].first << "  Number of listens: " << vregsmin[i].second << "\n";
		}
		savefile << "\n";
		savefile << "Song with most listens in NA: \n";
		for (int i = 0; i < v_mls.size(); i++) {
			savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
		}
		savefile << "\n";
			savefile << "Song with least listens in NA: \n";
			for (int i = 0; i < v_lps.size(); i++) {
				savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
			}
			savefile << "\n";
			list_buf.clear();
			//AS
			savefile << "Author/s with the most listens in AS: \n";
			for (auto x : spotifystatslist) {
				if (x.Continent == "AS") {
					list_buf.push_back(x);
				}
			}
			savefile << "\n";
			vregsmax = MostPopularArtist(list_buf);
			vregsmin = LeastPopularArtist(list_buf);
			v_mls = MostPopularSong(list_buf);
			v_lps = LeastPopularSong(list_buf);
			for (int i = 0; i < vregsmax.size(); i++) {
				savefile << "Author: " << vregsmax[i].first << "  Number of listens: " << vregsmax[i].second << "\n";
			}
			savefile << "\n";
			savefile << "Author/s with least listens in AS: \n";
			for (int i = 0; i < vregsmin.size(); i++) {
				savefile << "Author: " << vregsmin[i].first << "  Number of listens: " << vregsmin[i].second << "\n";
			}
			savefile << "\n";
			savefile << "Song with most listens in AS: \n";
			for (int i = 0; i < v_mls.size(); i++) {
				savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
			}
			savefile << "\n";
			savefile << "Song with least listens in AS: \n";
			for (int i = 0; i < v_lps.size(); i++) {
				savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
			}
			savefile << "\n";
			list_buf.clear();
			//AF
			savefile << "Author/s with the most listens in AF: \n";
			for (auto x : spotifystatslist) {
				if (x.Continent == "AF") {
					list_buf.push_back(x);
				}
			}
			savefile << "\n";
			vregsmax = MostPopularArtist(list_buf);
			vregsmin = LeastPopularArtist(list_buf);
			v_mls = MostPopularSong(list_buf);
			v_lps = LeastPopularSong(list_buf);
			for (int i = 0; i < vregsmax.size(); i++) {
				savefile << "Author: " << vregsmax[i].first << "  Number of listens: " << vregsmax[i].second << "\n";
			}
			savefile << "\n";
			savefile << "Author/s with least listens in AF: \n";
			for (int i = 0; i < vregsmin.size(); i++) {
				savefile << "Author: " << vregsmin[i].first << "  Number of listens: " << vregsmin[i].second << "\n";
			}
			savefile << "\n";
			savefile << "Song with most listens in AF: \n";
			for (int i = 0; i < v_mls.size(); i++) {
				savefile << "Author: " << v_mls[i].Author_name << " " << v_mls[i].Author_lastname << "  Number of listens: " << v_mls[i].playscount << " Region: " << v_mls[i].Continent << "\n";
			}
			savefile << "\n";
			savefile << "Song with least listens in AF: \n";
			for (int i = 0; i < v_lps.size(); i++) {
				savefile << "Author: " << v_lps[i].Author_name << " " << v_lps[i].Author_lastname << "  Number of listens: " << v_lps[i].playscount << " Region: " << v_lps[i].Continent << "\n";
			}
			savefile << "\n";
			list_buf.clear();
			//

			savefile << "Arithmetic mean of listens: " << ArithmeticMeanOfListens(spotifystatslist) << "\n";
			savefile << "Spearman's rank correlation coefficient: " << x << "\n";
			savefile << "\n";
		}
		savefile << "Sorted list:" << "\n";
		for (auto x : ArtistSorter(spotifystatslist)) {
			savefile << x.Author_name << " " << x.Author_lastname << " " << x.Title << " " << x.Continent << " " << x.playscount << " " << x.Songtime << "\n";
		}
	}



std::vector<std::pair<std::string, int>> SpotifyStats::MostPopularArtist(std::list<SpotifyStats>& spotifystatslist)
{
	std::vector<std::pair<std::string,int>> v;
	std::vector<SpotifyStats> v_buf;
	int max = 0;
	std::string buf_name;
	std::string buf_lastname;
	std::string savename;
	std::string savelastname;
	std::string Author;
	int sum = 0;
	for (auto x : spotifystatslist) {
		v_buf.push_back(x);
	}
	buf_name = v_buf[0].Author_name;
	buf_lastname = v_buf[0].Author_lastname;
	for (int i = 0; i < v_buf.size(); i++) {
		if (v_buf[i].Author_name == buf_name and v_buf[i].Author_lastname == buf_lastname) {
			sum = sum + v_buf[i].playscount;
		}
		else {
			if (sum > max) {
				max = sum;
				savename = v_buf[i-1].Author_name;
				savelastname = v_buf[i-1].Author_lastname;
			}
			sum = v_buf[i].playscount;
			buf_name = v_buf[i].Author_name;
			buf_lastname = v_buf[i].Author_lastname;
		}
		if (i == v_buf.size()-1) {
			if (sum > max) {
				max = sum;
				savename = buf_name;
				savelastname = buf_lastname;
			}
		}
	}
	Author = savename + " " + savelastname;
	v.push_back(std::make_pair(Author, max));

	return v;
}

std::vector< std::pair<std::string, int >> SpotifyStats::LeastPopularArtist(std::list<SpotifyStats>& spotifystatslist)
{
	std::vector<std::pair<std::string, int>> v;
	std::vector<SpotifyStats> v_buf;
	int min = 0;
	std::string buf_name;
	std::string buf_lastname;
	std::string savename;
	std::string savelastname;
	std::string Author;
	int sum = 0;
	int count = 0;
	for (auto x : spotifystatslist) {
		v_buf.push_back(x);
	}
	buf_name = v_buf[0].Author_name;
	buf_lastname = v_buf[0].Author_lastname;
	for (int i = 0; i < v_buf.size(); i++) {
		if (v_buf[i].Author_name == buf_name and v_buf[i].Author_lastname == buf_lastname) {
			sum = sum + v_buf[i].playscount;
		}
		else {
			if (count == 0) {
				min = sum;
				count++;
			}
			if (sum < min) {
				min = sum;
				savename = v_buf[i].Author_name;
				savelastname = v_buf[i].Author_lastname;
			}
			sum = v_buf[i].playscount;
			buf_name = v_buf[i].Author_name;
			buf_lastname = v_buf[i].Author_lastname;
		}
		if (i == v_buf.size()-1) {
			if (sum < min) {
				min = sum;
				savename = buf_name;
				savelastname = buf_lastname;
			}

		}
	}
	Author = savename + " " + savelastname;
	v.push_back(std::make_pair(Author, min));

	return v;
}
std::vector<SpotifyStats> SpotifyStats::MostPopularSong(std::list<SpotifyStats>& spotifystatslist)
{
	std::vector<SpotifyStats> v;
	int max = 0;
	for (auto x : spotifystatslist) {
		if (x.playscount > max) {
			max = x.playscount;
		}
	}
	for (auto y : spotifystatslist) {
		if (y.playscount == max) {
			v.push_back(y);

		}

	}
	return v;
}


std::vector<SpotifyStats> SpotifyStats::LeastPopularSong(std::list<SpotifyStats>& spotifystatslist)
{
	std::vector<SpotifyStats> v;
	int min = 0;
	int a_switch = 0;
	for (auto x : spotifystatslist) {
		if (a_switch == 0) {
			min = x.playscount;
			a_switch++;
		}
		if (x.playscount < min) {
			min = x.playscount;
		}
	}
	for (auto y : spotifystatslist) {
		if (y.playscount == min) {
			v.push_back(y);

		}
	}
	return v;
}

std::list<SpotifyStats> SpotifyStats::ArtistSorter(std::list<SpotifyStats>& spotifystatslist)
{
	std::list<SpotifyStats>l_sort(spotifystatslist);

	l_sort.sort([](const SpotifyStats& x, const SpotifyStats& y) {return x.playscount > y.playscount; });
	return l_sort;
}


int SpotifyStats::ArithmeticMeanOfListens(std::list<SpotifyStats>& spotifystatslist)
{
	int sum = 0;
	int value = 0;
	for (auto x : spotifystatslist) {
		sum = x.playscount + sum;
	}
	value = sum / spotifystatslist.size();
	return value;
}



double SpotifyStats::SpearmanKorelation(std::list<SpotifyStats>& spotifystatslist)
{
	std::vector<std::pair<string,double>> x_region;
	std::vector<std::pair<int,double>> y_playscount;
	double Rang_x = 0;
	double Rang_y = 1;
	string EUregname = "EU";
	string NAregname = "NA";
	string ASregname = "AS";
	string AFregname = "AF";
	int EU_count = 0;
	int NA_count = 0;
	int AS_count = 0;
	int AF_count = 0;
	int count = 0;
	for (auto a : spotifystatslist) {
		x_region.push_back(std::make_pair(a.Continent,0));
		y_playscount.push_back(std::make_pair(a.playscount,0));
	}
	//Find value of duplicates of regions
	for (auto x : spotifystatslist) {
		if (x.Continent == EUregname)
			EU_count++;
	}
	for (auto x : spotifystatslist) {
		if (x.Continent == NAregname)
			NA_count++;
	}
	for (auto x : spotifystatslist) {
		if (x.Continent == ASregname)
			AS_count++;
	}
	for (auto x : spotifystatslist) {
		if (x.Continent == AFregname)
			AF_count++;
	}
	// Write Rangs for regions
	//AF
	double sum = 0;
	int buf_count = 0;
	for (int i = 1; i <= AF_count; i++) {
		sum = sum + i;
	}
	Rang_x = sum / AF_count;
	for (int i = 0; i < x_region.size(); i++) {
		if (x_region[i].first == AFregname) {
			x_region[i].second = Rang_x;
		}
	}
	Rang_x = 0;
	sum = 0;
	buf_count = AS_count + AF_count;
	//AS
	for (int i = AF_count; i <buf_count; i++) {
		sum = sum + i;
	}
	Rang_x = sum / AS_count;
	for (int i = 0; i < x_region.size(); i++) {
		if (x_region[i].first == ASregname) {
			x_region[i].second = Rang_x;
		}
	}
	Rang_x = 0;
	sum = 0;
	//NA
	for (int i = buf_count; i < buf_count+NA_count; i++) {
		sum = sum + i;
	}
	Rang_x = sum / NA_count;
	for (int i = 0; i < x_region.size(); i++) {
		if (x_region[i].first == NAregname) {
			x_region[i].second = Rang_x;
		}
	}
	Rang_x = 0;
	sum = 0;
	buf_count = buf_count + NA_count;
	//EU
	for (int i = buf_count; i <= EU_count+buf_count; i++) {
		sum = sum + i;
	}
	Rang_x = sum / EU_count;
	for (int i = 0; i < x_region.size(); i++) {
		if (x_region[i].first == EUregname) {
			x_region[i].second = Rang_x;
		}
	}
	//Write Rangs for playscount
	double sum2 = 0;
	double buff = 0;
	double buff2 = 0;
	for (int i = 0; i < y_playscount.size(); i++) {
		for (int j= 0; j < y_playscount.size()-1; j++) {
			if (y_playscount[i].first == y_playscount[j].first+1) {
				count++;
				buff = y_playscount[i].first;
			}
		}
		if (count == 0) {
			y_playscount[i].second = Rang_y;
			Rang_y++;
		}
		else
		{
			for (int i = Rang_y; i <= Rang_y+count; i++) {
				sum2 = sum2 + i;
			}
			buff2 = Rang_y + count;
			Rang_y = sum2 / count;
			for (int i = 0; i < y_playscount.size(); i++) {
				if (y_playscount[i].first == buff) {
					y_playscount[i].second = Rang_y;
				}
			}
			Rang_y=buff2;
		}
		count = 0;
		sum2 = 0;

	}
	//Get Values of di^2
	std::vector<int>di2;
	if (y_playscount.size() != x_region.size())
		throw std::runtime_error("Tablice z parametrami i rangami ro¿nej d³ugosci!");
	else {
		for (int i = 0; i < y_playscount.size(); i++) {
			di2.push_back(pow((x_region[i].second - y_playscount[i].second), 2));
		}
	}
	//Get value of di^2
	double sumdi2 = 0;
	for (int i = 0; i < di2.size(); i++) {
		sumdi2 = sumdi2 + di2[i];
	}
	double ri = 0;
	double mianownik = (y_playscount.size() * (pow(y_playscount.size(), 2) - 1));
	ri = 1 - ((6 * sumdi2) / mianownik);
	return ri;
	
}


void RaportsGeneratorInterface(std::list<SpotifyStats> &spotifystatslist)
{
	enum  Region { Europe = 1, Asia = 3, America = 2 , Africa = 4 ,WorldWide = 5};
	int i = 0;
	char y;
	string EUregname = "EU";
	string NAregname = "NA";
	string ASregname = "AS";
	string AFregname = "AF";
	string Worldwide = "WorldWide";
	string EUfilename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStats_EU_report.txt";
	string NAfilename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStats_NA_report.txt";
	string ASfilename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStats_AS_report.txt";
	string AFfilename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStats_AF_report.txt";
	string WWfilename = "C:/Users/Piotr/source/repos/10266093-gr21-repo/Projekt/Projekt_Zaliczeniowy_Spotify/SpotifyStats_WorldWide_report.txt";
	list<SpotifyStats>list_buf;
	SpotifyStats obj2;
	system("cls");
	std::cout << "Welcome in RaportsGenerator!\n";
	std::cout << "Select the region you want to report from: \n";
	std::cout << "1: Europe\n";
	std::cout << "2: North America\n";
	std::cout << "3: Asia\n";
	std::cout << "4: Africa\n";
	std::cout << "5: WorldWide\n";
	std::cout << "To quit the program press 6: \n";
	while (true)
	{
		cin >> i;
		switch (i)
		{
		case Europe:
			for (auto x : spotifystatslist) 
			{
				if (x.Continent==EUregname) {
					list_buf.push_back(x);
				}
			}
			obj2.GenerateReport(list_buf, EUfilename,EUregname);
			list_buf.clear();
			std::cout << "The report was generated in the file: " << EUfilename << "\n";
			std::cout << "Press y to back to continue...\n";
			while (true)
			{
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
			}
			system("cls");
			return;
			break;
		case America:
			for (auto x : spotifystatslist)
			{
				if (x.Continent == NAregname) {
					list_buf.push_back(x);
				}
			}
			obj2.GenerateReport(list_buf, NAfilename, NAregname);
			list_buf.clear();
			std::cout << "The report was generated in the file: " << NAfilename << "\n";
			std::cout << "Press y to back to continue...\n";
			while (true)
			{
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
			}
			system("cls");
			return;
			break;
		case Asia:
			for (auto x : spotifystatslist)
			{
				if (x.Continent == ASregname) {
					list_buf.push_back(x);
				}
			}
			obj2.GenerateReport(list_buf, ASfilename, ASregname);
			list_buf.clear();
			std::cout << "The report was generated in the file: " << ASfilename << "\n";
			std::cout << "Press y to back to continue...\n";
			while (true)
			{
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
			}
			system("cls");
			return;
			break;
		case Africa:
			for (auto x : spotifystatslist)
			{
				if (x.Continent == AFregname) {
					list_buf.push_back(x);
				}
			}
			obj2.GenerateReport(list_buf, AFfilename, AFregname);
			list_buf.clear();
			std::cout << "The report was generated in the file: " << AFfilename << "\n";
			std::cout << "Press y to back to continue...\n";
			while (true)
			{
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
			}
			system("cls");
			return;
			break;
		case WorldWide:
			obj2.GenerateReport(spotifystatslist, WWfilename, Worldwide);
			list_buf.clear();
			std::cout << "The report was generated in the file: " << WWfilename << "\n";
			std::cout << "Press y to back to continue...\n";
			while (true)
			{
				cin >> y;
				if (y == 'y') {
					system("cls");
					return;
				}
			}
			system("cls");
			return;
			break;
		case 6:
			std::cout << "Quitting...\n";
			system("cls");
			return;
			break;
		default:
			std::cout << "Option does not exist... Try again.\n";
			break;
		}
	}


	return;
}

void Help()
{
	system("cls");
	char y;
	std::cout << "Welcome in Help section:\n";
	std::cout << "In main menu you will have 3 choices...\n";
	std::cout << "Zero will get you to help section. In Help section you will find everything about the program.\n";
	std::cout << "One will get you to the ReportGenerator. In this section you can generate report about Arthist in different regions.\n";
	std::cout << "Two will shut down the program.\n";
	std::cout << "\n";
	std::cout << "StatisticSpotify version alpha 1.0.2\n";
	std::cout << "Press y to back to the main menu...\n";
	while (true)
	{	
		cin >> y;
		if (y == 'y') {
			system("cls");
			return;
		}
	}
}
