#pragma once
#include "BaseNumber.h"
#include "DxLib.h"

class Character;
class Map;
class SceneManager;
class Enemy
{
public:

	Enemy();
	void Draw();
	void EnemyMove();
	void EnemyMove_a();
	void EnemyVerticalMove();
	void UpdateEnemy();
	void EnemyAirCollision(Character& character, Map& map, SceneManager& scene);

	
	int EnemyHandle;


	int enemyX;
	int	enemyY;



	int RabbitX;
	int	RabbitY;


	
private:

	int EnemyPerChraSize = 32;

	bool rabbitHitX;
	bool rabbitHitY;

	
	bool enemyHitX;
	bool enemyHitY;

	bool IsFlag;

	int EnemyHandle2;
	int getX;
	int getY;

	int rabgetX;
	int rabgetY;


	int circlecount;
	bool DectionCircle[6];

};

