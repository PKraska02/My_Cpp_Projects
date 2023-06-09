#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import Enemy;
import <map>;
export module Bullet;

export class Bullet {
private:
	sf::Sprite bullet_sprite;
	std::map<std::string, sf::Texture*>bullet_textures;
	std::string bullet_texture_filename = "C:/Users/Piotr/source/repos/f03fc1e6-gr21-repo/Projekt/Space_Invaders_Game/Textures/Bulett.png";
	float bullet_speed = 3.f;
	float bullet_damage;
	float bullet_damage_booster = 1.f;;
	sf::Vector2f direction;
public:
	Bullet();
	Bullet(sf::Texture* texture, float x, float y, float pos_x, float pos_y,float damage);
	virtual ~Bullet();
	const sf::FloatRect GetBounds() const;
	std::map<std::string, sf::Texture*>*GetBulletTextures();
	float GetDamage();
	void InitBulletTexture();
	bool CheckCollision(Enemy* enemy);
	void UpdateBullet();
	void RenderBullet(sf::RenderTarget* target);
};
