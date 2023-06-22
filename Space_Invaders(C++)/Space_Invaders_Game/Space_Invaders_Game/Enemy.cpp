#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
import Enemy;

Enemy::Enemy(int type, int hp, int hpMax, int damage, int points, sf::Vector2f position)
    : type(type), hp(hp), hpMax(hpMax), damage(damage), points(points), position(position){
}

Enemy::Enemy()
{
}

Enemy::~Enemy() {
 
}


