#pragma once
#include "BaseNumber.h"
#include "DxLib.h"
class Character;
class Enemy
{
	
public:

	void Draw();
	void KillerRabbit(Character&e_chara);
	void EnemyMove();
	void EnemyVerticalMove();
	void InitEnemy();
	void EnemyAirCollision();
	void UpdateEnemy();
	void AdditionMove();
	
	int EnemyHandle = LoadGraph("RoperMan.png");

	//エネミー初期位置
	int enemyX= 300;
	int	enemyY=368;

	//ウサギの位置
	int RabbitX=200;
	int	RabbitY= 400;

	int getX = GetRand(5);
	int getY = GetRand(5);
	

	int rabgetX = GetRand(10-5);
	int rabgetY = GetRand(10-5);


	int rand_rX=GetRand(600);
	int rand_rY=GetRand(450);

	int rand_eX=GetRand(600);
	int rand_eY=GetRand(448);

	//敵の移動判定 
	bool rabbitHitX;
	bool rabbitHitY;


	//敵の移動判定
	bool enemyHitX;
	bool enemyHitY;

	//敵が画面にいるかどうかの判定
	bool IsFlag;

	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	void Drawcircle();
	int circlecount=-1;
	bool DectionCircle[6] = { true,true,true,true,true,true };
	int circleX[6] = {10,10,10,25,25,25};
	int circleY[6] = {25,45,65,25,45,65};
	int lifecolor[6];
	int circlecolor=GetColor(255, 0, 0);
 

};

