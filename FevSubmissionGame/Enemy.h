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
	void EnemyWallBumped();
	void EnemyAirCollision(Character&e_chara);
	void UpdateEnemy();
	

	//�G�l�~�[�����ʒu
	int enemyX= 300;
	int	enemyY=368;

	int EnemyNum = 0;
	
	//�E�T�M�̈ʒu
	int RabbitX[100] = {200};
	int	RabbitY[100] = {400};

	int get = GetRand(200);

	//�G�̈ړ����� 
	bool FirstHit;
	bool enemyHit;

	bool FirstHitY;
	bool enemyHitY;

	

	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	//�G�l�~�[�̈ړ�����
	int enemy_moveX;
	int enemy_moveY;


	void Drawcircle();
	bool DectionCircle= true;
	int circleX[3] = {10,10,10};
	int circleY[3] = {25,45,65 };
 

};

