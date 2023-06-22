import EnemyBullet;
import<iostream>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

EnemyBullet::EnemyBullet()
{
	this->enemy_bullet_textures["ENEMYBULLET"] = nullptr;
	this->InitEnemyBulletTexture();
}

EnemyBullet::EnemyBullet(sf::Texture* texture, float x, float y, float pos_x, float pos_y, float damage)
{
	this->enemy_bullet_sprite.setTexture(*texture);
	this->enemy_bullet_sprite.scale(0.1f, 0.1f);
	this->enemy_bullet_sprite.setPosition(pos_x, pos_y);
	this->direction.x = x;
	this->direction.y = y;
	this->enemy_bullet_damage = damage;
}

EnemyBullet::~EnemyBullet()
{
	for (auto& i : this->enemy_bullet_textures)
	{
		delete i.second;
	}
}

const sf::FloatRect EnemyBullet::GetBounds() const
{
	return this->enemy_bullet_sprite.getGlobalBounds();
}

std::map<std::string, sf::Texture*>* EnemyBullet::GetEnemyBulletTextures()
{
	return &this->enemy_bullet_textures;
}

sf::Vector2f EnemyBullet::GetBulletPosition()
{
	return this->enemy_bullet_sprite.getPosition();
}

float EnemyBullet::GetDamage()
{
	return this->enemy_bullet_damage;
}

void EnemyBullet::InitEnemyBulletTexture()
{
	this->enemy_bullet_textures["ENEMYBULLET"] = new sf::Texture();
	if (!this->enemy_bullet_textures["ENEMYBULLET"]->loadFromFile(this->enemy_bullet_texture_filename)) {
		std::cout << "ERROR\n";
	}
}

bool EnemyBullet::CheckCollision(StarShip* player)
{
	sf::FloatRect bulletBounds = this->GetBounds();
	sf::FloatRect playerbounds = player->getBounds();
	return bulletBounds.intersects(playerbounds);
}

bool EnemyBullet::CheckWallCollision(sf::RectangleShape wall)
{
	sf::FloatRect wallbounds = wall.getGlobalBounds();
	sf::FloatRect bulletBounds = this->GetBounds();
	return bulletBounds.intersects(wallbounds);
}

void EnemyBullet::UpdateEnemyBullet()
{
	this->enemy_bullet_sprite.move(this->direction * this->enemy_bullet_speed);
}

void EnemyBullet::RenderEnemyBullet(sf::RenderTarget* target)
{
	target->draw(this->enemy_bullet_sprite);
}
