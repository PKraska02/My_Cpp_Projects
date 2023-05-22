#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
export module Player;
import <iostream>;
export class StarShip{
private:
    //StarShip parameters
    sf::Sprite ship_sprite;     
    sf::Texture ship_texture;
    std::string ship_texture_filename = "C:\\Users\\Piotr\\source\\repos\\f03fc1e6-gr21-repo\\Projekt\\Space_Invaders_Game\\Textures\\PlrSp.png";
    sf::Image ship_image;
    float ship_fireTimer;
    float ship_fireRate = 0.5f;
    const float STARSHIP_SPEED = 2.f;
    const float ship_x = 350.f;
    const float ship_y = 700.f;
public:
    // StarShip Constructor
    StarShip();
    //StarShip Destructor
    ~StarShip();
    // Left
    void MoveLeft();
    // Right
    void MoveRight();
    void StartingPosition();
    void InitSprite();
    void InitTexture();
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    float GetShipFireRate();
    void Update();
    void Render(sf::RenderTarget& target);

};

