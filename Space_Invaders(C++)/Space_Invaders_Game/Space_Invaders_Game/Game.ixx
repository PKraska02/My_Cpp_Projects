#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import Player;
import Bullet;
import Enemy;
import EnemyBullet;
import<iostream>;
import <filesystem>;
export module Game;
export class Game {
private:
    //Window parameters
    sf::RenderWindow* render_window;
    sf::VideoMode videomode;
    sf::Event ev;
    sf::Vector2u windowSize;
    //Game Objects
    sf::RectangleShape shield1;
    sf::RectangleShape shield2;
    sf::RectangleShape shield3;
    std::vector<sf::RectangleShape>shields;
    sf::Texture BackGround;
    std::string background_filename="C:/Users/Piotr/source/repos/f03fc1e6-gr21-repo/Projekt/Space_Invaders_Game/Textures/BckGr.png";
    //player
    StarShip* player;
    //bullet
    std::vector<Bullet*> bullets;
    Bullet* bullet;
    std::vector<Bullet*>bulletbin;
    //Enemy
    std::vector< std::vector<Enemy*>> enemies;
    std::vector<Enemy*>enemybin;
    Enemy* enemy;
    sf::Vector2f EnemyStartPosition;
    //
    BlueEnemy *blue_enemy;
    PinkEnemy *pink_enemy;
    YellowEnemy *yellow_enemy;
    //EnemyBullet
    std::vector<std::vector<EnemyBullet*>>blue_enemy_bullets;
    std::vector<std::vector<EnemyBullet*>>yellow_enemy_bullets;
    std::vector<std::vector<EnemyBullet*>>pink_enemy_bullets;
    EnemyBullet* enemybullet;
    //std::vector<EnemyBullet*>enemybulletbin;
    //Inits
    void InitVariables();
    void InitWindow();
    void InitPlayer();
    void InitBullet();
    void InitEnemies();
    void InitEnemyBullets();
    void InitWalls();
    //Gameplay parameters;
    bool GameOver = 0;
    int PlayerPoints = 0;
    int yOffset = 75;
    int EnemyMoveDelay = 20;
    int Highscore = 0;
    static sf::Clock shootClock;
    static sf::Clock BlueEnemyShootClock;
    static sf::Clock YellowEnemyShootClock;
    static sf::Clock PinkEnemyShootClock;
    static sf::Clock EnemyClock;
    sf::Time shootInterval;
    sf::Time BlueEnemyshootInterval;
    sf::Time PinkEnemyshootInterval;
    sf::Time YellowEnemyshootInterval;
    sf::Time EnemyMove;
public:
    Game();
    virtual ~Game();
    sf::RenderWindow* GetWindow()const;
    const bool IsGameRunning();
    bool IsEnemyDead(Enemy * enemy,Bullet *bullet);
    bool IsWin();
    bool IsGameOver();
    void InitBackGroundTexture();
    int GetPlayerPoints();
    int GetHighscorePoints();
    void CreateHighScoreFile();
    void pollEvent();
    void RenderGame();
    void UpdateGame();
    void UpdateBullet();
    void UpdateEnemyBullets();
    void UpdateBounds();
    void UpdateEnemies();
    void UpdatePoolEvent();
    void UpdateInput();

};