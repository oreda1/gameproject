#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"



void Enemy::Draw()
{
	int EnemyHandle=LoadGraph("RoperMan.png");
	
	for (int y = 0; y < EnemyChipY; y++)
	{
		for (int x = 0; x < EnemyChipX; x++)
		{
			if (MakeEnemy[y][x]==1)
			{
				DrawRectGraph(enemyX, enemyY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize,EnemyPerChraSize, EnemyHandle, true);
				
			}
		}
	}
	
}

void Enemy::KillerRabbit()
{
	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	DrawRectGraph(enemyX, enemyY - 50, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
}

void Enemy::EnemyMove() 
{

	--enemyX;
	
	if (enemyX<0)
	{
		enemyX = 0;
		
	}
	
	if (enemyX>608)
	{
		enemyX = 608;

	}

}

void Enemy::EnemyCollision()
{

	
	

}




