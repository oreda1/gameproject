#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
Character en_chara;



void Enemy::UpdateEnemy()
{

	if (RabbitX[EnemyNum] < 0 || RabbitY[EnemyNum] < 0)
	{
		RabbitX[EnemyNum] = 608;
        RabbitY[EnemyNum] = 310;
		if (RabbitY[EnemyNum]<0)
		{
			enemyHit = true;
		}

		for (int i = 0; i < 30; i++)
		{
			
			DrawRectGraph(RabbitX[i], RabbitY[i], EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
			
		}
		if (enemyHit==true)
		{
			RabbitY[EnemyNum] += 5;
			
		
		}
		
	}


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
	RabbitX[EnemyNum] = 608;
	RabbitY[EnemyNum] = 310;
	DrawRectGraph(RabbitX[EnemyNum], RabbitY[EnemyNum], EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
}


void Enemy::EnemyMove() 
{
	if (RabbitY[EnemyNum]>448)
	{
		enemyHit = false;
	}
	
	if (enemyHit==false&&RabbitY[EnemyNum]>0)
	{
		RabbitY[EnemyNum] -= 3;
	}
	
	--enemyX;
	--RabbitX[EnemyNum];
	--RabbitY[EnemyNum];
	

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
	if (RabbitY[EnemyNum]>388)
	{
		RabbitY[EnemyNum] = 388;
	}


}

void Enemy::EnemyAirCollision(Character& e_chara)
{
	if (RabbitY[EnemyNum] < e_chara.Player_posY && e_chara.Player_posY - RabbitY[EnemyNum]<16
		|| RabbitY[EnemyNum]>e_chara.Player_posY && RabbitY[EnemyNum] - e_chara.Player_posY<16
		|| RabbitX[EnemyNum]>e_chara.Player_posX && RabbitX[EnemyNum] - e_chara.Player_posX<16
		|| e_chara.Player_posX>RabbitX[EnemyNum] &&RabbitY[EnemyNum] <e_chara.Player_posY&& e_chara.Player_posX - RabbitX[EnemyNum] < 16)
	{
		DrawRectRotaGraph(e_chara.Player_posX + 30, e_chara.Player_posY, 0, 0, 120, 120, 1, 0, e_chara.EffectHandle, true);
		
	}
	else
	{
		
		
	}


}






