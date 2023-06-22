import Menu;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

void Menu::InitVariables()
{
	this->titleText.setPosition(100, 100);
	this->playText.setPosition(100, 250);
	this->settingsText.setPosition(100, 350);
	this->highscoreText.setPosition(100, 450);
	this->exitText.setPosition(100, 550);
    this->highscorevalueText.setPosition(100, 550);
    this->backText.setPosition(100,650);
    this->WinText.setPosition(400, 350);
    this->LoseText.setPosition(400, 350);
    this->Help.setPosition(300, 150);
}

Menu::Menu(sf::RenderWindow* window,Game *game) {
	if (!this->font.loadFromFile(this->font_filename)) {
		std::cout << "FONT ERROR!\n";
	}
	this->menu_window = window;
    this->game = game;
	this->titleText = sf::Text("SPACE INVADERS", this->font, 100);
	this->playText=sf::Text("Play",this->font,60);
	this->highscoreText = sf::Text("HighScore", this->font, 60);
	this->settingsText = sf::Text("Help", this->font, 60);
	this->exitText = sf::Text("Exit", this->font, 60);
    this->highscorevalueText = sf::Text("Your highscore "+std::to_string(this->game->GetHighscorePoints()), this->font, 60);
    this->backText = sf::Text("Back", font, 60);
    this->WinText = sf::Text("YOU WIN", font, 60);
    this->LoseText = sf::Text("YOU LOSE", font, 60);
    this->Help = sf::Text("\nControl\nLeft  Press left\nRight  Press right\nShoot  Press space\nYou have only one life\nGood Luck\n", font, 60);
	this->InitVariables();
}

Menu::~Menu()
{
}

bool Menu::MenuEvent()
{
    while (this->menu_window->isOpen())
    {
        sf::Event event;
        while (this->menu_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->menu_window->close();
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));


                    if (this->playText.getGlobalBounds().contains(mousePos))
                    {
                        return false; 
                    }


                    if (this->exitText.getGlobalBounds().contains(mousePos))
                    {
                        this->menu_window->close();
                        return true;
                    }

                    if (this->highscoreText.getGlobalBounds().contains(mousePos))
                    {
                        DrawHighscore();
                        //std::cout << "Highscore!\n";
                    }
                    if (this->settingsText.getGlobalBounds().contains(mousePos)) {
                        DrawHelp();
                    }
                }
            }
            DrawMenu();
        }
    }
}

void Menu::DrawMenu()
{
    this->menu_window->clear(); 


    this->menu_window->draw(this->titleText);


    this->menu_window->draw(this->playText);


    this->menu_window->draw(this->settingsText);


    this->menu_window->draw(this->highscoreText);

    this->menu_window->draw(this->exitText);

    this->menu_window->display();
}

void Menu::DrawHighscore()
{
    while (this->menu_window->isOpen()) {
        this->menu_window->clear();

        this->menu_window->draw(this->highscoreText);

        this->menu_window->draw(this->highscorevalueText);
        this->menu_window->draw(this->backText);

        this->menu_window->display();
        sf::Event event;
        while (this->menu_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->menu_window->close();
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    // SprawdŸ klikniêcie w tekst "Back"
                    if (this->backText.getGlobalBounds().contains(mousePos))
                    {
                        return;
                    }
                }
            }
        }
    }
}

void Menu::DrawWin()
{
    this->scorevalueText = sf::Text("Your score "+std::to_string(this->game->GetPlayerPoints()), this->font, 60);
    this->scorevalueText.setPosition(100, 550);
        while (this->menu_window->isOpen()) {
            this->menu_window->clear();

            this->menu_window->draw(this->WinText);

            this->menu_window->draw(this->scorevalueText);
            this->menu_window->draw(this->backText);

            this->menu_window->display();
            sf::Event event;
            while (this->menu_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    this->menu_window->close();
                }
                else if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        // SprawdŸ klikniêcie w tekst "Back"
                        if (this->backText.getGlobalBounds().contains(mousePos))
                        {
                            return;
                        }
                    }
                }
            }
        }
}

void Menu::DrawLose()
{
    this->scorevalueText = sf::Text("Your  score " + std::to_string(this->game->GetPlayerPoints()), this->font, 60);
    this->scorevalueText.setPosition(100, 550);
    while (this->menu_window->isOpen()) {
        while (this->menu_window->isOpen()) {
            this->menu_window->clear();

            this->menu_window->draw(this->LoseText);

            this->menu_window->draw(this->scorevalueText);
            this->menu_window->draw(this->backText);

            this->menu_window->display();
            sf::Event event;
            while (this->menu_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    this->menu_window->close();
                }
                else if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        // SprawdŸ klikniêcie w tekst "Back"
                        if (this->backText.getGlobalBounds().contains(mousePos))
                        {
                            return;
                        }
                    }
                }
            }
        }

    }
}
void Menu::DrawHelp() {
    while (this->menu_window->isOpen()) {
        this->menu_window->clear();
        this->menu_window->draw(this->Help);
        this->menu_window->draw(this->backText);
        this->menu_window->display();
        while (this->menu_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->menu_window->close();
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                    // SprawdŸ klikniêcie w tekst "Back"
                    if (this->backText.getGlobalBounds().contains(mousePos))
                    {
                        return;
                    }
                }
            }
        }
    }
}


