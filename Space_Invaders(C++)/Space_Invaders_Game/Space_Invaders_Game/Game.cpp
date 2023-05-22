import Player;
import Game;
import Bullet;
import<iostream>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

void Game::InitVariables()
{
	this->render_window = nullptr;
}

void Game::InitWindow()
{
	this->videomode.height = 800;
	this->videomode.width = 800;
	this->render_window = new sf::RenderWindow(this->videomode, "Space Invaders", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close /* | sf::Style::Fullscreen*/);
    this->render_window->setFramerateLimit(144);
    this->render_window->setVerticalSyncEnabled(false);
}

void Game::InitPlayer()
{
    this->player = new StarShip();
    this->shootInterval = sf::seconds(this->player->GetShipFireRate());
}

void Game::InitBullet()
{
    this->bullet = new Bullet();
}

Game::Game()
{
    this->InitVariables();
    this->InitWindow();
    this->InitPlayer();
    this->InitBullet();
}

Game::~Game()
{
    delete this->render_window;
    delete this->player;
    for (auto& i : this->bullets) {
        delete i;
    }
}

const bool Game::IsGameRunning()
{
    return this->render_window->isOpen();
}

void Game::pollEvent()
{
    while (this->render_window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->render_window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->render_window->close();
            break;
        default:
            break;
        }
    }
}

void Game::RenderGame()
{
    this->render_window->clear(sf::Color::Black);//Clear screen;
    this->player->Render(*this->render_window);
    for (auto* bullet : this->bullets) {
        bullet->RenderBullet(this->render_window);
    }
    this->render_window->display();//display screen;
}

void Game::UpdateGame()
{
    this->UpdateInput();
    this->UpdatePoolEvent();
    this->UpdateBullet();
}

void Game::UpdateBullet()
{
    unsigned int counter = 0;
    for (auto* bullet : this->bullets) {
        bullet->UpdateBullet();
        if (bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
        }

        ++counter;

    }
}

void Game::UpdatePoolEvent()
{
    this->pollEvent();
}
sf::Clock Game::shootClock;
void Game::UpdateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->player->MoveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->player->MoveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&& shootClock.getElapsedTime() >= this->shootInterval) {
        std::map<std::string, sf::Texture*>* bulletTextures = this->bullet->GetBulletTextures();
        this->bullets.push_back(new Bullet((*bulletTextures)["BULLET"], 0.f, -1.f, this->player->getPos().x + (this->player->getBounds().width / 2.f)-60, this->player->getPos().y-50));
        std::cout << "Fire!\n";
        this->shootClock.restart();

    }

  
}
