#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"

void Enemy::InitEnemy()
{
	

}

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


void Enemy::KillerRabbit(Character& e_chara)
{
	int EnemyHandle2 = LoadGraph("pyon-manjiro1.png");

	
	
	DrawRectGraph(RabbitX, RabbitY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
	if (RabbitX<0)
	{
		DeleteGraph(EnemyHandle2);
		DrawRectGraph(RabbitX, RabbitY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
	}

	

}


void Enemy::EnemyMove() 
{
	--enemyX;
	
	--RabbitX;
	--RabbitY;

	
	

}

void Enemy::EnemyWallBumped()
{

	//if (enemyX < 0)
	//{
	//	enemyX = 0;
	//}
	//if (enemyX > 608)
	//{
	//	enemyX = 608;

	//}
	//if (RabbitX<0)
	//{
	//	RabbitX = 0;
	//}
	//if (RabbitY < 0)
	//{
	//	RabbitY= 0;
	//}
	if (RabbitY>388)
	{
		RabbitY= 388;
	}


}

void Enemy::EnemyAirCollision(Character& e_chara)
{
	if (RabbitY< e_chara.Player_posY && e_chara.Player_posY - RabbitY<16
		|| RabbitY>e_chara.Player_posY && RabbitY - e_chara.Player_posY<16
		|| RabbitX>e_chara.Player_posX && RabbitX - e_chara.Player_posX<16
		|| e_chara.Player_posX>RabbitX &&RabbitY <e_chara.Player_posY&& e_chara.Player_posX - RabbitX< 16)
	{
		DrawRectRotaGraph(e_chara.Player_posX + 30, e_chara.Player_posY, 0, 0, 120, 120, 1, 0, e_chara.EffectHandle, true);
		
	}
	else
	{
		
		
	}


}






