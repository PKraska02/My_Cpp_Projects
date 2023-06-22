#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
export module Enemy;

export class Enemy {
protected:
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;
	sf::Vector2f position;
public:
	virtual void InitShape() = 0;
	virtual sf::Sprite* GetSprite() = 0;
	virtual sf::FloatRect GetBounds() = 0;
	virtual void StartingEnemyPosition() = 0;
	virtual void UpdateEnemy() = 0;
	virtual void RenderEnemy(sf::RenderTarget* target) = 0;
	virtual int GetHP() = 0;
	virtual void SetHP(int hp) = 0;
	virtual const sf::Vector2f& GetEnemyPosition() = 0;
	virtual sf::Vector2f GetCenterPosition() = 0;
	virtual float GetFireRate()=0;
	virtual float GetEnemyDamage() = 0;
	virtual void SetPosition(float x, float y) = 0;
	virtual int GetPoints() = 0;

	Enemy(int type, int hp, int hpMax, int damage, int points, sf::Vector2f position);
	Enemy();
	virtual ~Enemy();

};
export class BlueEnemy :public Enemy {
private:
	sf::Sprite Blue_Enemy_Sprite;
	sf::Texture Blue_Enemy_Texture;
	std::string Blue_Texture_filename = "C:\\Users\\Piotr\\source\\repos\\f03fc1e6-gr21-repo\\Projekt\\Space_Invaders_Game\\Textures\\BluEn.png";
	float blue_enemy_fire_rate = 3.f;
public:
	BlueEnemy(int type, int hp, int hpMax, int damage, int points, sf::Vector2f position);
	BlueEnemy();
	void InitShape() override;
	virtual ~BlueEnemy();
	sf::Sprite* GetSprite() override;
	sf::FloatRect GetBounds() override;
	int GetHP() override;
	void SetHP(int hp) override;
	const sf::Vector2f& GetEnemyPosition();
	void UpdateEnemy() override;
	void RenderEnemy(sf::RenderTarget* target) override;
	void StartingEnemyPosition() override;
	sf::Vector2f GetCenterPosition() override;
	float GetFireRate() override;
	float GetEnemyDamage()override;
	void SetPosition(float x, float y) override;
	int GetPoints() override;
};
export class PinkEnemy :public Enemy {
private:
	sf::Sprite Pink_Enemy_Sprite;
	sf::Texture Pink_Enemy_Texture;
	std::string Pink_Texture_filename = "C:\\Users\\Piotr\\source\\repos\\f03fc1e6-gr21-repo\\Projekt\\Space_Invaders_Game\\Textures\\PnkEn.png";
	float pink_enemy_fire_rate = 7.5f;
public:
	PinkEnemy(int type,int hp, int hpMax, int damage, int points, sf::Vector2f position);
	PinkEnemy();
	void InitShape() override;
	virtual ~PinkEnemy();
	sf::Sprite* GetSprite() override;
	sf::FloatRect GetBounds() override;
	int GetHP() override;
	void SetHP(int hp) override;
	const sf::Vector2f& GetEnemyPosition();
	void UpdateEnemy() override;
	void RenderEnemy(sf::RenderTarget* target) override;
	void StartingEnemyPosition() override;
	sf::Vector2f GetCenterPosition() override;
	float GetFireRate() override;
	float GetEnemyDamage()override;
	void SetPosition(float x, float y) override;
	int GetPoints() override;

};
export class YellowEnemy :public Enemy {
private:
	sf::Sprite Yellow_Enemy_Sprite;
	sf::Texture Yellow_Enemy_Texture;
	std::string Yellow_Texture_filename = "C:\\Users\\Piotr\\source\\repos\\f03fc1e6-gr21-repo\\Projekt\\Space_Invaders_Game\\Textures\\YlwEn.png";
	float yellow_enemy_fire_rate = 10.f;
public:
	YellowEnemy(int type, int hp, int hpMax, int damage, int points, sf::Vector2f position);
	YellowEnemy();
	void InitShape() override;
	virtual ~YellowEnemy();
	sf::Sprite* GetSprite() override;
	sf::FloatRect GetBounds() override;
	int GetHP() override;
	void SetHP(int hp) override;
	const sf::Vector2f& GetEnemyPosition();
	void UpdateEnemy() override;
	void RenderEnemy(sf::RenderTarget* target) override;
	void StartingEnemyPosition() override;
	sf::Vector2f GetCenterPosition() override;
	float GetFireRate() override;
	float GetEnemyDamage()override;
	void SetPosition(float x, float y) override;
	int GetPoints() override;
};




