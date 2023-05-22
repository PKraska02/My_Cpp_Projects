import Bullet;
import <map>;
import <iostream>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

Bullet::Bullet()
{
	this->bullet_textures["BULLET"] = nullptr;
	this->InitBulletTexture();
}

Bullet::Bullet(sf::Texture* texture, float x, float y, float pos_x, float pos_y)
{
	this->bullet_sprite.setTexture(*texture);
	this->bullet_sprite.scale(0.1f, 0.1f);
	this->direction.x = x;
	this->direction.y = y;
	this->bullet_sprite.setPosition(pos_x, pos_y);
}

Bullet::~Bullet()
{
	for (auto& i : this->bullet_textures)
	{
		delete i.second;
	}
}

const sf::FloatRect Bullet::GetBounds() const
{
	return this->bullet_sprite.getGlobalBounds();
}
std::map<std::string, sf::Texture*>* Bullet::GetBulletTextures()
{
	return &this->bullet_textures;
}

void Bullet::InitBulletTexture()
{
	this->bullet_textures["BULLET"] = new sf::Texture();
	if (!this->bullet_textures["BULLET"]->loadFromFile(this->bullet_texture_filename)) {
		std::cout << "ERROR\n";
	}
}

void Bullet::UpdateBullet()
{
	this->bullet_sprite.move(this->direction*this->bullet_speed);
}

void Bullet::RenderBullet(sf::RenderTarget* target)
{
	target->draw(this->bullet_sprite);
}
