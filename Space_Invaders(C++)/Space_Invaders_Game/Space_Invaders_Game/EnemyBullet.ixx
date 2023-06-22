import<iostream>;
import Player;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
export module EnemyBullet;

export class EnemyBullet {

private:
    sf::Sprite enemy_bullet_sprite;
    std::map<std::string, sf::Texture*> enemy_bullet_textures;
    std::string enemy_bullet_texture_filename = "C:/Users/Piotr/source/repos/f03fc1e6-gr21-repo/Projekt/Space_Invaders_Game/Textures/Enemybulett.png";
    float enemy_bullet_speed = 3.f;
    float enemy_bullet_damage;
    sf::Vector2f direction;

public:
    EnemyBullet();
    EnemyBullet(sf::Texture* texture, float x, float y, float pos_x, float pos_y, float damage);
    virtual ~EnemyBullet();

    const sf::FloatRect GetBounds() const;
    std::map<std::string, sf::Texture*>* GetEnemyBulletTextures();
    sf::Vector2f GetBulletPosition();
    float GetDamage();
    void InitEnemyBulletTexture();
    bool CheckCollision(StarShip* player);
    bool CheckWallCollision(sf::RectangleShape wall);
    void UpdateEnemyBullet();
    void RenderEnemyBullet(sf::RenderTarget* target);
};


