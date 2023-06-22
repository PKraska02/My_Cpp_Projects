import Game;
import Player;
import Enemy;
import Bullet;
import EnemyBullet;
import<iostream>;
import<filesystem>;
import<fstream>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

void Game::InitVariables()
{
	this->render_window = nullptr;
    this->EnemyMove = sf::seconds(this->EnemyMoveDelay);
}

void Game::InitWindow()
{
	this->videomode.height = 800;
	this->videomode.width = 1200;
	this->render_window = new sf::RenderWindow(this->videomode, "Space Invaders", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close /* | sf::Style::Fullscreen*/);
    this->render_window->setFramerateLimit(144);
    this->render_window->setVerticalSyncEnabled(false);
    this->windowSize = this->render_window->getSize();
}

void Game::InitPlayer()
{
    this->player = new StarShip();
}

void Game::InitBullet()
{
    this->bullet = new Bullet();
}

void Game::InitEnemies()
{
    int count = 0;
    sf::Vector2f enemySpacing(80.f, 0.f);
    sf::Vector2f position;
    for (int row = 0; row < 3; ++row) {
        std::vector<Enemy*> enemyrow;
        for (int col = 0; col < 13; ++col) {
            if (row == 2) {
                if (count == 0) {
                    this->EnemyStartPosition.x = 100.f;
                    this->EnemyStartPosition.y = 50.f;
                    count++;
                    this->enemy = new YellowEnemy(3, 20, 20, 50, 50, this->EnemyStartPosition);
                }
                else {
                    position.x = this->EnemyStartPosition.x + enemySpacing.x * col;
                    position.y = this->EnemyStartPosition.y + enemySpacing.y * col;
                    this->enemy = new YellowEnemy(3, 20, 20, 50, 50, position);
                }
                // U¿yj rightPoint do wyœwietlenia obiektów obok siebie
            }
            else if (row == 1) {
                if (count == 0) {
                    this->EnemyStartPosition.x = 100.f;
                    this->EnemyStartPosition.y = 150.f;
                    count++;
                    this->enemy = new PinkEnemy(2, 15, 15, 20, 25, this->EnemyStartPosition);
                }
                else {
                    position.x = this->EnemyStartPosition.x + enemySpacing.x * col; 
                    position.y = this->EnemyStartPosition.y + enemySpacing.y * col;
                    this->enemy = new PinkEnemy(2, 15, 15, 20, 25, position);
                }
            }
            else {
                if (count == 0) {
                    this->EnemyStartPosition.x = 100.f;
                    this->EnemyStartPosition.y = 250.f;
                    count++;
                    this->enemy = new BlueEnemy(1, 10, 10, 10, 10, this->EnemyStartPosition);
                }
                else {
                    position.x = this->EnemyStartPosition.x + enemySpacing.x * col;
                    position.y = this->EnemyStartPosition.y + enemySpacing.y * col;
                    this->enemy = new BlueEnemy(1, 10, 10, 10, 10, position);
                }
            }
            enemyrow.push_back(this->enemy);
        }
        this->enemies.push_back(enemyrow);
        count = 0;
        //std::cout << this->enemies.size()<<"\n";
        enemyrow.clear();
    }
    this->blue_enemy = new BlueEnemy();
    this->pink_enemy = new PinkEnemy();
    this->yellow_enemy = new YellowEnemy();
    this->shootInterval = sf::seconds(this->player->GetShipFireRate());
    this->BlueEnemyshootInterval = sf::seconds(this->blue_enemy->GetFireRate());
    this->PinkEnemyshootInterval = sf::seconds(this->pink_enemy->GetFireRate());
    this->YellowEnemyshootInterval = sf::seconds(this->yellow_enemy->GetFireRate());
}

void Game::InitEnemyBullets()
{
    this->enemybullet = new EnemyBullet();
}

void Game::InitWalls()
{
    sf::Vector2f wallsize(155, 20);
    this->shield1.setSize(wallsize);
    this->shield1.setPosition(sf::Vector2f(100.f, 650.f));
    this->shield2.setSize(wallsize);
    this->shield2.setPosition(sf::Vector2f(500.f, 650.f));
    this->shield3.setSize(wallsize);
    this->shield3.setPosition(sf::Vector2f(900.f, 650.f));
    this->shield1.setFillColor(sf::Color::Green);
    this->shield2.setFillColor(sf::Color::Green);
    this->shield3.setFillColor(sf::Color::Green);
    this->shields.push_back(shield1);
    this->shields.push_back(shield2);
    this->shields.push_back(shield3);
}

Game::Game()
{
    this->InitVariables();
    this->InitWindow();
    this->InitPlayer();
    this->InitBullet();
    this->InitEnemies();
    this->InitEnemyBullets();
    this->InitWalls();
    this->InitBackGroundTexture();
}

Game::~Game()
{
    delete this->render_window;
    delete this->player;
    for (auto& i : this->bullets) {
        delete i;
    }
    for (auto& row : this->enemies) {
        for (Enemy* enemy : row) {
            delete enemy;
        }
        row.clear();
    }

    this->enemies.clear();
    for (auto* enemy : this->enemybin) {
        delete enemy;
    }
    this->enemybin.clear();

}

sf::RenderWindow* Game::GetWindow() const
{
    return this->render_window;
}

const bool Game::IsGameRunning()
{
    return this->render_window->isOpen();
}

bool Game::IsEnemyDead(Enemy* enemy, Bullet* bullet)
{
    int hp = enemy->GetHP();
    int dmg = bullet->GetDamage();
    if (hp - dmg <= 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Game::IsWin()
{
    for (int i = 0; i < this->enemies.size(); i++) {
        if (this->enemies[i].size() != 0) {
            return false;
        }
    }
    return true;
}

bool Game::IsGameOver()
{
    if (this->GameOver == 1) {
        return true;
    }
    else
    {
    return false; 
    }
}

void Game::InitBackGroundTexture()
{
    if (!this->BackGround.loadFromFile(this->background_filename)) {
        std::cout << "Failed to load background texture!" << std::endl;
    }
}

int Game::GetPlayerPoints()
{
    return this->PlayerPoints;
}

int Game::GetHighscorePoints()
{
    std::filesystem::path filePath = "Highscore"; // Œcie¿ka do pliku

    if (!std::filesystem::exists(filePath))
    {
        std::ofstream createFile(filePath);
        createFile.close();
    }

    std::ifstream readFile(filePath); // Otwarcie pliku do odczytu

    if (readFile >> this->Highscore)
    {
        std::cout << "Highscore read successfully: " << this->Highscore << std::endl;
    }
    else
    {
        std::cout << "Failed to read highscore. Setting default value: 0" << std::endl;
    }

    readFile.close(); // Zamkniêcie pliku odczytu

    return this->Highscore;
}


void Game::CreateHighScoreFile()
{
    std::filesystem::path filePath = "Highscore"; 

    if (!std::filesystem::exists(filePath))
    {
        std::ofstream createFile(filePath);
        createFile.close();
    }

    std::ifstream file(filePath); 

    int currentHighscore = this->Highscore;
    if (file >> currentHighscore)
    {
        // Jeœli uda³o siê odczytaæ wartoœæ z pliku, porównaj z nowym wynikiem
        if (this->PlayerPoints > currentHighscore)
        {
            std::ofstream writeFile(filePath); // Otwarcie pliku do zapisu

            if (writeFile.is_open())
            {
                writeFile << this->PlayerPoints; // Zapisz now¹ wartoœæ highscore
                this->Highscore = this->PlayerPoints;
                writeFile.close(); // Zamknij plik
                std::cout << "New highscore saved: " << std::endl;
            }
            else
            {
                std::cout << "Failed to open Highscore file for writing." << std::endl;
            }
        }
        else
        {
            std::cout << "Current highscore is higher: " << currentHighscore << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to read current highscore." << std::endl;
    }

    file.close(); // Zamknij plik odczytu
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
    sf::Sprite backgroundSprite(this->BackGround);
    this->render_window->draw(backgroundSprite);
    this->player->Render(*this->render_window);
    for (const auto& shield : shields) {
        this->render_window->draw(shield);
    }
    for (auto* bullet : this->bullets) {
        bullet->RenderBullet(this->render_window);
    }
    for (auto& row : this->enemies) {
        for (Enemy* enemy : row) {
            if (BlueEnemy* blueEnemy = dynamic_cast<BlueEnemy*>(enemy)) {
                // Jest to obiekt klasy BlueEnemy
                blueEnemy->StartingEnemyPosition();
                blueEnemy->RenderEnemy(this->render_window);
                //std::cout << "Niebieski Pokaz sie!\n";
            }
            else if (PinkEnemy* pinkEnemy = dynamic_cast<PinkEnemy*>(enemy)) {
                // Jest to obiekt klasy PinkEnemy
                pinkEnemy->StartingEnemyPosition();
                pinkEnemy->RenderEnemy(this->render_window);
                //std::cout << "Rozowy Pokaz sie!\n";
            }
            else if (YellowEnemy* yellowEnemy = dynamic_cast<YellowEnemy*>(enemy)) {
                // Jest to obiekt klasy YellowEnemy
                yellowEnemy->StartingEnemyPosition();
                yellowEnemy->RenderEnemy(this->render_window);
                //std::cout << "Zolty Pokaz sie!\n";
            }
        }
        //row.clear();
    }
    for (auto& bulletVector : this->blue_enemy_bullets) {
        for (auto* blueenemybullet : bulletVector) {
            blueenemybullet->RenderEnemyBullet(this->render_window);
        }
    }

    for (auto& bulletVector : this->pink_enemy_bullets) {
        for (auto* pinkenemybullet : bulletVector) {
            pinkenemybullet->RenderEnemyBullet(this->render_window);
        }
    }

    for (auto& bulletVector : this->yellow_enemy_bullets) {
        for (auto* yellowenemybullet : bulletVector) {
            yellowenemybullet->RenderEnemyBullet(this->render_window);
        }
    }

    this->render_window->display();//display screen;
}

void Game::UpdateGame()
{
    this->UpdateInput();
    this->UpdateBounds();
    this->UpdatePoolEvent();
    this->UpdateBullet();
    this->UpdateEnemyBullets();
    this->UpdateEnemies();
}

void Game::UpdateBullet()
{
    unsigned int counter = 0;
    int hp = 0;
    int dmg = 0;
    for (auto* bullet : this->bullets) {
        bullet->UpdateBullet();
        bool HitEnemy = false;
        for (auto& row : this->enemies) {
            for (int i = 0; i < row.size();i++) {
                auto* enemy = row[i];
                if (bullet->CheckCollision(enemy)) {
                    if (BlueEnemy* blueEnemy = dynamic_cast<BlueEnemy*>(enemy)) {
                        if (this->IsEnemyDead(blueEnemy, bullet)) {
                            this->enemybin.push_back(blueEnemy);
                            row.erase(row.begin() + i);
                            --i;
                            this->PlayerPoints += blueEnemy->GetPoints();
                        }
                        else {
                            hp = blueEnemy->GetHP();
                            dmg = bullet->GetDamage();
                            blueEnemy->SetHP(hp - dmg);
                        }
                        HitEnemy = true;
                    }
                    else if (PinkEnemy* pinkEnemy = dynamic_cast<PinkEnemy*>(enemy)) {
                        if (this->IsEnemyDead(pinkEnemy, bullet)) {
                            this->enemybin.push_back(pinkEnemy);
                            row.erase(row.begin() + i);
                            --i;
                            this->PlayerPoints += pinkEnemy->GetPoints();
                        }
                        else {
                            hp = pinkEnemy->GetHP();
                            dmg = bullet->GetDamage();
                            pinkEnemy->SetHP(hp - dmg);
                        }
                        HitEnemy = true;
                    }
                    else if (YellowEnemy* yellowEnemy = dynamic_cast<YellowEnemy*>(enemy)) {
                        if (this->IsEnemyDead(yellowEnemy, bullet)) {
                            this->enemybin.push_back(yellowEnemy);
                            row.erase(row.begin() + i);
                            --i;
                            this->PlayerPoints += yellowEnemy->GetPoints();
                        }
                        else {
                            hp = yellowEnemy->GetHP();
                            dmg = bullet->GetDamage();
                           yellowEnemy->SetHP(hp - dmg);
                        }
                        HitEnemy = true;
                    }
                    if (HitEnemy)
                        break;
                }
            }
        }  
        if (HitEnemy) {
            // Pocisk trafi³ przeciwnika, usuñ go
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            std::cout << "Bullet hit enemy and destroyed!\n";
            counter--;
        }
        if (bullet->GetBounds().top + bullet->GetBounds().height < 0.f)
        {
            //Delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            std::cout << "Erase!\n";
            counter--;
        }

        ++counter;

    }
}
sf::Clock Game::BlueEnemyShootClock;
sf::Clock Game::PinkEnemyShootClock;
sf::Clock Game::YellowEnemyShootClock;
//Zrobic ograniczenia czasowe strzelania i wgl samo strzelanie
void Game::UpdateEnemyBullets()
{
        int counter = 0;
        std::map<std::string, sf::Texture*>* enemybulletTextures = this->enemybullet->GetEnemyBulletTextures();

        // Strza³y niebieskich przeciwników
        for (auto& row : this->enemies) {
            if (BlueEnemyShootClock.getElapsedTime() >= this->BlueEnemyshootInterval) {
                for (Enemy* enemy : row) {
                    if (BlueEnemy* blueEnemy = dynamic_cast<BlueEnemy*>(enemy)) {
                            if (this->blue_enemy_bullets.size() <= counter) {
                                this->blue_enemy_bullets.push_back(std::vector<EnemyBullet*>());
                            }
                            EnemyBullet* bullet = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], 0.f, 1.f, blueEnemy->GetCenterPosition().x, blueEnemy->GetCenterPosition().y, blueEnemy->GetEnemyDamage());
                            this->blue_enemy_bullets[counter].push_back(bullet);
                            std::cout << "Shoot Blue!" << counter << "\n";
                            counter++;
                            this->BlueEnemyShootClock.restart();
                    }
                }
            }
            counter = 0;
        }

        // Strza³y ró¿owych przeciwników
        for (auto& row : this->enemies) {
            if (PinkEnemyShootClock.getElapsedTime() >= this->PinkEnemyshootInterval) {
                for (Enemy* enemy : row) {
                    if (PinkEnemy* pinkEnemy = dynamic_cast<PinkEnemy*>(enemy)) {
                            if (this->pink_enemy_bullets.size() <= counter) {
                                this->pink_enemy_bullets.push_back(std::vector<EnemyBullet*>());
                            }
                            EnemyBullet* bullet1 = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], 1.f, 1.f, pinkEnemy->GetCenterPosition().x, pinkEnemy->GetCenterPosition().y, pinkEnemy->GetEnemyDamage());
                            this->pink_enemy_bullets[counter].push_back(bullet1);
                            bullet1 = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], -1.f, 1.f, pinkEnemy->GetCenterPosition().x, pinkEnemy->GetCenterPosition().y, pinkEnemy->GetEnemyDamage());
                            this->pink_enemy_bullets[counter].push_back(bullet1);
                            std::cout << "Shoot Pink!" << counter << "\n";
                            counter++;
                            this->PinkEnemyShootClock.restart();
                    }
                }
            }
            counter = 0;
        }

        // Strza³y ¿ó³tych przeciwników
        for (auto& row : this->enemies) {
            if (YellowEnemyShootClock.getElapsedTime() >= this->YellowEnemyshootInterval) {
                for (Enemy* enemy : row) {
                    if (YellowEnemy* yellowEnemy = dynamic_cast<YellowEnemy*>(enemy)) {
                            if (this->yellow_enemy_bullets.size() <= counter) {
                                this->yellow_enemy_bullets.push_back(std::vector<EnemyBullet*>());
                            }
                            EnemyBullet* bullet2 = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], 0.f, 1.f, yellowEnemy->GetCenterPosition().x, yellowEnemy->GetCenterPosition().y, yellowEnemy->GetEnemyDamage());
                            this->yellow_enemy_bullets[counter].push_back(bullet2);
                            bullet2 = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], 1.f, 1.f, yellowEnemy->GetCenterPosition().x, yellowEnemy->GetCenterPosition().y, yellowEnemy->GetEnemyDamage());
                            this->yellow_enemy_bullets[counter].push_back(bullet2);
                            bullet2 = new EnemyBullet((*enemybulletTextures)["ENEMYBULLET"], -1.f, 1.f, yellowEnemy->GetCenterPosition().x, yellowEnemy->GetCenterPosition().y, yellowEnemy->GetEnemyDamage());
                            this->yellow_enemy_bullets[counter].push_back(bullet2);
                            std::cout << "Shoot Yellow!" << counter << "\n";
                            counter++;
                            this->YellowEnemyShootClock.restart();
                    }
                }
            }
            counter = 0;
        }


        // Usuñ pociski, które przekroczy³y doln¹ czêœæ ekranu
        for (auto& bulletVector : this->blue_enemy_bullets) {
            for (auto it = bulletVector.begin(); it != bulletVector.end();) {
                EnemyBullet* blue = *it;
                blue->UpdateEnemyBullet();

                // SprawdŸ, czy pocisk osi¹gn¹³ doln¹ czêœæ ekranu
                if (blue->GetBulletPosition().y >= windowSize.y || blue->GetBulletPosition().x < 0.f) {
                    delete blue;
                    std::cout << "EraseB!\n";
                    it = bulletVector.erase(it);
                }
                else if(blue->CheckCollision(this->player)) {
                    delete blue;
                    std::cout << "GameOver!!\n";
                    it = bulletVector.erase(it);
                    this->GameOver = 1;
                }
                else if (blue->CheckWallCollision(this->shield1) || (blue->CheckWallCollision(this->shield2)) || (blue->CheckWallCollision(this->shield3))) {
                    delete blue;
                    std::cout << "Wall!!\n";
                    it = bulletVector.erase(it);
                }
                else {
                    ++it;
                }
            }
        }

        for (auto& bulletVector : this->pink_enemy_bullets) {
            for (auto it = bulletVector.begin(); it != bulletVector.end();) {
                EnemyBullet* pink = *it;
                pink->UpdateEnemyBullet();

                // SprawdŸ, czy pocisk osi¹gn¹³ doln¹ czêœæ ekranu
                if (pink->GetBulletPosition().y >= windowSize.y || pink->GetBulletPosition().x < 0.f) {
                    delete pink;
                    std::cout << "EraseP!\n";
                    it = bulletVector.erase(it);
                }
                else if (pink->CheckCollision(this->player)) {
                    delete pink;
                    std::cout << "GameOver!!\n";
                    it = bulletVector.erase(it);
                    this->GameOver = 1;
                }
                else if (pink->CheckWallCollision(this->shield1) || (pink->CheckWallCollision(this->shield2)) || (pink->CheckWallCollision(this->shield3))) {
                    delete pink;
                    std::cout << "Wall!!\n";
                    it = bulletVector.erase(it);
                }
                else {
                    ++it;
                }
            }
        }

        for (auto& bulletVector : this->yellow_enemy_bullets) {
            for (auto it = bulletVector.begin(); it != bulletVector.end();) {
                EnemyBullet* yellow = *it;
                yellow->UpdateEnemyBullet();

                // SprawdŸ, czy pocisk osi¹gn¹³ doln¹ czêœæ ekranu
                if (yellow->GetBulletPosition().y >= windowSize.y || yellow->GetBulletPosition().x < 0.f) {
                    delete yellow;
                    std::cout << "EraseY!\n";
                    it = bulletVector.erase(it);
                }
                else if (yellow->CheckCollision(this->player)) {
                    delete yellow;
                    std::cout << "GameOver!!\n";
                    it = bulletVector.erase(it);
                    this->GameOver = 1;
                }
                else if (yellow->CheckWallCollision(this->shield1) || (yellow->CheckWallCollision(this->shield2)) || (yellow->CheckWallCollision(this->shield3))) {
                    delete yellow;
                    std::cout << "Wall!!\n";
                    it = bulletVector.erase(it);
                }
                else {
                    ++it;
                }
            }
        }

}

void Game::UpdateBounds()
{
    sf::FloatRect shipBounds = this->player->getBounds();
    sf::Sprite *ship = this->player->GetShipSprite();

    if (shipBounds.left <= 0) {
        // Statek dotar³ do lewej krawêdzi ekranu
        ship->setPosition(0, ship->getPosition().y);
    }
    else if (shipBounds.left + shipBounds.width >= windowSize.x) {
        // Statek dotar³ do prawej krawêdzi ekranu
        ship->setPosition(windowSize.x - shipBounds.width, ship->getPosition().y);
    }
}

sf::Clock Game::EnemyClock;
// Przesuwanie w dol przeciwnikow po jakims czasie
void Game::UpdateEnemies()
{
    int counter = 0;
    if (EnemyClock.getElapsedTime() >= this->EnemyMove) {
        for (auto& row : this->enemies) {
            for (Enemy* enemy : row) {
                enemy->SetPosition(enemy->GetEnemyPosition().x, enemy->GetEnemyPosition().y + this->yOffset);
            }
        }
        counter++;
        if (counter == 5) {
            this->GameOver = 1;
        }
        EnemyClock.restart();
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
        this->bullets.push_back(new Bullet((*bulletTextures)["BULLET"], 0.f, -1.f, this->player->getPos().x + (this->player->getBounds().width / 2.f), this->player->getPos().y,5));
        std::cout << "Fire!\n";
        this->shootClock.restart();

    }
}




