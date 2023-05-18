#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import <map>;
export module Bullet;

export class Bullet {
private:
	sf::Sprite bullet_sprite;
	std::map<std::string, sf::Texture*>bullet_textures;
	std::vector<Bullet*> bullet;
	std::string bullet_texture_filename = "C:/Users/Piotr/source/repos/f03fc1e6-gr21-repo/Projekt/Space_Invaders_Game/Textures/Bulet.png";
	float bullet_speed = 1.f;
	sf::Vector2f direction;
public:
	Bullet();
	Bullet(sf::Texture* texture, float x, float y);
	virtual ~Bullet();
	void SetBullets();
	std::vector<Bullet*>GetBullets();
	void InitBulletTexture();
	void UpdateBullet();
	void Fire();
	void RenderBullet(sf::RenderTarget* target);
};
