#pragma once
#include "DxLib.h"
class Character;
class Enemy
{
public:

	void Draw();
	void KillerRabbit(Character&e_chara);
	void EnemyMove();
	void EnemyWallBumped();
	void EnemyAirCollision(Character&e_chara);
	void UpdateEnemy();
	

	//エネミー初期位置
 	int enemyX = 300;
	int	enemyY=368;

	int EnemyNum = 30;
	
	//ウサギの位置
	float RabbitX[100] = { 608 };//= 300;
	float RabbitY[100] = { 310 };//= 310;

	int get = GetRand(200);

	//敵の移動判定
	bool enemyHit;

	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	//エネミーの移動処理
	int enemy_moveX;
	int enemy_moveY;
 

};

