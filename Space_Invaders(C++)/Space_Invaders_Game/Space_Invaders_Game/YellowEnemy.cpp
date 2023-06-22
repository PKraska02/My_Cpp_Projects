#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import <iostream>;
import Enemy;

YellowEnemy::YellowEnemy(int type,int hp, int hpMax, int damage, int points, sf::Vector2f position) : Enemy(type, hp, hpMax, damage, points, position) {
	this->InitShape();
}

YellowEnemy::YellowEnemy()
{
}

void YellowEnemy::InitShape()
{
	if (!this->Yellow_Enemy_Texture.loadFromFile(this->Yellow_Texture_filename)) {
		std::cout << "ERROR! File not found...\n";
	}
	this->Yellow_Enemy_Sprite.setTexture(this->Yellow_Enemy_Texture);
	this->Yellow_Enemy_Sprite.scale(0.3f, 0.3f);
}

YellowEnemy::~YellowEnemy()
{
}

sf::Sprite* YellowEnemy::GetSprite()
{
	return &this->Yellow_Enemy_Sprite;
}

sf::FloatRect YellowEnemy::GetBounds()
{
	return this->Yellow_Enemy_Sprite.getGlobalBounds();
}

int YellowEnemy::GetHP()
{
	return this->hp;
}

void YellowEnemy::SetHP(int hp)
{
	this->hp = hp;
}

const sf::Vector2f& YellowEnemy::GetEnemyPosition()
{
	return this->Yellow_Enemy_Sprite.getPosition();
}

void YellowEnemy::UpdateEnemy()
{
	//Shooting
}

void YellowEnemy::RenderEnemy(sf::RenderTarget* target)
{
	target->draw(this->Yellow_Enemy_Sprite);
}

void YellowEnemy::StartingEnemyPosition()
{
	this->Yellow_Enemy_Sprite.setPosition(this->position);
}

sf::Vector2f YellowEnemy::GetCenterPosition()
{
	sf::FloatRect bounds = Yellow_Enemy_Sprite.getGlobalBounds();
	return sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height - bounds.height / 2);
}

float YellowEnemy::GetFireRate()
{
	return this->yellow_enemy_fire_rate;
}

float YellowEnemy::GetEnemyDamage()
{
	return this->damage;
}

void YellowEnemy::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

int YellowEnemy::GetPoints()
{
	return this->points;
}

