#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import Player;
import Bullet;
export module Game;
import<iostream>;
export class Game {
private:
    //Window parameters
    sf::RenderWindow* render_window;
    sf::VideoMode videomode;
    sf::Event ev;
    StarShip* player;
    std::vector<Bullet*> bullets;
    Bullet* bullet;
    void InitVariables();
    void InitWindow();
    void InitPlayer();
    void InitBullet();
    //Gameplay parameters;
    bool GameOver = 0;
    static sf::Clock shootClock;
    sf::Time shootInterval;
public:
    Game();
    virtual ~Game();
    const bool IsGameRunning();
    void pollEvent();
    void RenderGame();
    void UpdateGame();
    void UpdateBullet();
    void UpdatePoolEvent();
    void UpdateInput();
};