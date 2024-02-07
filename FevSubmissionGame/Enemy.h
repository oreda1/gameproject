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
	void EnemyAirCollision(Character&e_chara);
	void UpdateEnemy();
	void AdditionMove();
	
	int EnemyHandle = LoadGraph("RoperMan.png");

	//�G�l�~�[�����ʒu
	int enemyX= 300;
	int	enemyY=368;

	//�E�T�M�̈ʒu
	int RabbitX=200;
	int	RabbitY= 400;

	int getX = GetRand(10);
	int getY = GetRand(10);

	int rabgetX = GetRand(10);
	int rabgetY = GetRand(10);


	int rand_rX=GetRand(600);
	int rand_rY=GetRand(450);

	int rand_eX=GetRand(600);
	int rand_eY=GetRand(448);

	//�G�̈ړ����� 
	bool rabbitHitX;
	bool rabbitHitY;


	//�G�̈ړ�����
	bool enemyHitX;
	bool enemyHitY;

	//�G����ʂɂ��邩�ǂ����̔���
	bool IsFlag;

	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");



	void Drawcircle();
	int circlecount=6;
	bool DectionCircle[6];
	int circleX[6] = {10,10,10,20,20,20};
	int circleY[6] = {25,45,65,25,45,65};
 

};

