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
	

	//�G�l�~�[�����ʒu
 	int enemyX = 300;
	int	enemyY=368;

	int EnemyNum = 30;
	
	//�E�T�M�̈ʒu
	float RabbitX[100] = { 608 };//= 300;
	float RabbitY[100] = { 310 };//= 310;

	int get = GetRand(200);

	//�G�̈ړ�����
	bool enemyHit;

	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	//�G�l�~�[�̈ړ�����
	int enemy_moveX;
	int enemy_moveY;
 

};

