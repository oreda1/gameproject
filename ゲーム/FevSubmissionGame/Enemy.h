#pragma once

class Character;
class Enemy
{
	

public:

	void Draw();
	void KillerRabbit(Character&e_chara);
	void EnemyMove();
	void EnemyWallBumped();
	void EnemyAirCollision(Character&e_chara);
	void InitEnemy();
	

	

	//�G�l�~�[�����ʒu
 	int enemyX=300;
	int	enemyY=368;
	
	//�E�T�M�̈ʒu
	float RabbitX = 300;
	float RabbitY = 310;

	

	//�G�l�~�[�̈ړ�����
	int enemy_moveX;
	int enemy_moveY;
 

	

	
	

};

