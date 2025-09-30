#pragma once
#include "BaseNumber.h"
#include "DxLib.h"

class Character;
class Enemy
{
public:

	Enemy();
	void Draw();
	void EnemyMove();
	void EnemyMove_a();
	void EnemyVerticalMove();
	void InitEnemy();
	void UpdateEnemy();
	void AdditionMove();
	void EnemyAirCollision(Character& character, Map& map, SceneManager& scene);
	bool CheckCollision(int x1, int y1, int x2, int y2, int distance);
	
	int EnemyHandle;


	int enemyX;
	int	enemyY;



	int RabbitX;
	int	RabbitY;


	void Drawcircle();
	
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


	int rand_rX;
	int rand_rY;

	int rand_eX;
	int rand_eY;
	int circlecount;
	bool DectionCircle[6];
	int circleX[6];
	int circleY[6];
	int lifecolor[6];
	int circlecolor;

};

