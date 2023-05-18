import Bullet;
import <map>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture, float x, float y)
{
	this->bullet_sprite.setTexture(*texture);
	this->direction.x = x;
	this->direction.y = y;
}

Bullet::~Bullet()
{
	for (auto& i : this->bullet_textures)
	{
		delete i.second;
	}
}

void Bullet::SetBullets()
{
}

std::vector<Bullet*> Bullet::GetBullets()
{
	return std::vector<Bullet*>();
}

void Bullet::InitBulletTexture()
{
	this->bullet_textures["BULLET"] = new sf::Texture();
	this->bullet_textures["BULLET"]->loadFromFile(this->bullet_texture_filename);
}

void Bullet::UpdateBullet()
{
	this->bullet_sprite.move(this->direction*this->bullet_speed);
}

void Bullet::Fire()
{

}

void Bullet::RenderBullet(sf::RenderTarget* target)
{
	target->draw(this->bullet_sprite);
}
