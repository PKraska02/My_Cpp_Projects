#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import <iostream>;
import Enemy;


PinkEnemy::PinkEnemy(int type,int hp, int hpMax, int damage, int points, sf::Vector2f position) : Enemy(type, hp, hpMax, damage, points, position) {
	this->InitShape();
}

PinkEnemy::PinkEnemy()
{
}

PinkEnemy::~PinkEnemy()
{

}

sf::Sprite* PinkEnemy::GetSprite()
{
	return &this->Pink_Enemy_Sprite;
}

sf::FloatRect PinkEnemy::GetBounds()
{
	return this->Pink_Enemy_Sprite.getGlobalBounds();
}

int PinkEnemy::GetHP()
{
	return this->hp;
}

void PinkEnemy::SetHP(int hp)
{
	this->hp = hp;
}

const sf::Vector2f& PinkEnemy::GetEnemyPosition()
{
	return this->Pink_Enemy_Sprite.getPosition();
}

void PinkEnemy::UpdateEnemy()
{
	//Shooting
}

void PinkEnemy::RenderEnemy(sf::RenderTarget* target)
{
	target->draw(this->Pink_Enemy_Sprite);
}

void PinkEnemy::StartingEnemyPosition()
{
	this->Pink_Enemy_Sprite.setPosition(this->position);
}

sf::Vector2f PinkEnemy::GetCenterPosition()
{
	sf::FloatRect bounds = Pink_Enemy_Sprite.getGlobalBounds();
	return sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height - bounds.height / 2);
}

float PinkEnemy::GetFireRate()
{
	return this->pink_enemy_fire_rate;
}

float PinkEnemy::GetEnemyDamage()
{
	return this->damage;
}

void PinkEnemy::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

int PinkEnemy::GetPoints()
{
	return this->points;
}


void PinkEnemy::InitShape()
{
	if (!this->Pink_Enemy_Texture.loadFromFile(this->Pink_Texture_filename)) {
		std::cout << "ERROR! File not found...\n";
	}
	this->Pink_Enemy_Sprite.setTexture(this->Pink_Enemy_Texture);
	this->Pink_Enemy_Sprite.scale(0.3f, 0.3f);
}