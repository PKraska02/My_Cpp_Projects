#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
export module Enemy;

export class Enemy {
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;
public:
	virtual void EnemyFire() = 0;
	virtual void InitVariables() = 0;
	virtual void InitShape() = 0;

};
export class BlueEnemy :public Enemy {
	//BlueEnemy();
	//void EnemyFire() override;

	//void InitVariables() override;

	//void InitShape() override;
};
export class GreenEnemy :public Enemy {
	//GreenEnemy();
	//void EnemyFire() override;

	//void InitVariables() override;

	//void InitShape() override;
};
export class RedEnemy :public Enemy {
	//RedEnemy();
	//void EnemyFire() override;

	//void InitVariables() override;

	//void InitShape() override;
};