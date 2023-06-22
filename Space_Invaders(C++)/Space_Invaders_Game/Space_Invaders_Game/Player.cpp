import Player;
import<iostream>;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>


StarShip::StarShip()
{
	this->InitTexture();
	this->InitSprite();
	this->StartingPosition();
}

StarShip::~StarShip()
{
}

void StarShip::MoveLeft()
{
	this->ship_sprite.move(-(this->STARSHIP_SPEED), 0.f);
	std::cout << "MOVELEFT\n";
}

void StarShip::MoveRight()
{
	this->ship_sprite.move((this->STARSHIP_SPEED), 0.f);
	std::cout << "MOVERIGHT\n";
}

void StarShip::StartingPosition()
{
	sf::Vector2f position(this->ship_x,this->ship_y);
	this->ship_sprite.setPosition(position);
}

void StarShip::InitSprite()
{
	this->ship_sprite.setTexture(this->ship_texture);
	this->ship_sprite.scale(0.1f, 0.1f);

}

void StarShip::InitTexture()
{

	if (!this->ship_image.loadFromFile(this->ship_texture_filename)) {
		std::cout << "ERROR! File not found...\n";
	}
	if (!this->ship_texture.loadFromImage(this->ship_image)) {
		// obs³uga b³êdu, jeœli nie mo¿na utworzyæ tekstury z obrazu
	}
}

const sf::Vector2f& StarShip::getPos() const
{
	return this->ship_sprite.getPosition();
}

const sf::FloatRect StarShip::getBounds() const
{
	return this->ship_sprite.getGlobalBounds();
}

float StarShip::GetShipFireRate()
{
	return this->ship_fireRate;
}

sf::Sprite* StarShip::GetShipSprite()
{
	return &(this->ship_sprite);
}

void StarShip::Update()
{

}

void StarShip::Render(sf::RenderTarget& target)
{
	target.draw(this->ship_sprite);
}