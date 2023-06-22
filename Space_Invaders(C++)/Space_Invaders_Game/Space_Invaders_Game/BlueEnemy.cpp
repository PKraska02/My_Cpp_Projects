#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import <iostream>;
import Enemy;

BlueEnemy::BlueEnemy(int type, int hp, int hpMax, int damage, int points, sf::Vector2f position): Enemy(type, hp, hpMax, damage, points, position) {
	this->InitShape();
}

BlueEnemy::BlueEnemy()
{
}

void BlueEnemy::InitShape()
{
	if (!this->Blue_Enemy_Texture.loadFromFile(this->Blue_Texture_filename)) {
		std::cout << "ERROR! File not found...\n";
	}
	this->Blue_Enemy_Sprite.setTexture(this->Blue_Enemy_Texture);
	this->Blue_Enemy_Sprite.scale(0.3f, 0.3f);
}

BlueEnemy::~BlueEnemy()
{

}

sf::Sprite* BlueEnemy::GetSprite()
{
	return &this->Blue_Enemy_Sprite;
}

sf::FloatRect BlueEnemy::GetBounds()
{
	return this->Blue_Enemy_Sprite.getGlobalBounds();
}

int BlueEnemy::GetHP()
{
	return this->hp;
}

void BlueEnemy::SetHP(int hp)
{
	this->hp = hp;
}

const sf::Vector2f& BlueEnemy::GetEnemyPosition()
{
	return this->Blue_Enemy_Sprite.getPosition();
}


void BlueEnemy::UpdateEnemy()
{
	//Shooting
}

void BlueEnemy::RenderEnemy(sf::RenderTarget* target)
{
	target->draw(this->Blue_Enemy_Sprite);
}

void BlueEnemy::StartingEnemyPosition()
{
	this->Blue_Enemy_Sprite.setPosition(this->position);
}

sf::Vector2f BlueEnemy::GetCenterPosition()
{
	sf::FloatRect bounds = Blue_Enemy_Sprite.getGlobalBounds();
	return sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height - bounds.height / 2);
}

float BlueEnemy::GetFireRate()
{
	return this->blue_enemy_fire_rate;
}

float BlueEnemy::GetEnemyDamage()
{
	return this->damage;
}

void BlueEnemy::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

int BlueEnemy::GetPoints()
{
	return this->points;
}

