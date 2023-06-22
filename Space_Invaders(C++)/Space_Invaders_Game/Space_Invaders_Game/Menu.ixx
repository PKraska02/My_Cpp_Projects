import <iostream>;
import Game;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
export module Menu;

export class Menu {
private:
	Game* game;
	sf::RenderWindow* menu_window;
	sf::Event event;
	sf::Text titleText;
	sf::Text playText;
	sf::Text highscoreText;
	sf::Text settingsText;
	sf::Text exitText;
	sf::Text highscorevalueText;
	sf::Text scorevalueText;
	sf::Text backText;
	sf::Text WinText;
	sf::Text LoseText;
	sf::Text Help;
	sf::Font font;
	std::string font_filename = "C:/Users/Piotr/source/repos/f03fc1e6-gr21-repo/Projekt/Space_Invaders_Game/Textures/RaceF.ttf";
	void InitVariables();
public:
	Menu(sf::RenderWindow* window,Game*game);
	virtual~Menu();
	bool MenuEvent();
	void DrawMenu();
	void DrawHighscore();
	void DrawWin();
	void DrawLose();
	void DrawHelp();


};