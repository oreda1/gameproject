#include "Enemy.h"
#include"DxLib.h"

void Enemy::Draw()
{
	int EnemyHandle=LoadGraph("RoperMan.png");
	DrawGraph(enemyX, enemyY, EnemyHandle,false);
}

void Enemy::EnemyMove()
{
	

}

void Enemy::EnemyCollision()
{
}


