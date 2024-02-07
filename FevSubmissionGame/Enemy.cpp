#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
Character en_chara;
Map en_map;


void Enemy::UpdateEnemy()
{
	//false + true -
	//Á‚¦‚½‚Ìˆ—
	if (RabbitY<= 0)
	{
		RabbitY = 0;
		rabbitHitY = true;
	}
	else if (RabbitY >= 448)
	{
		RabbitY = 448;
		rabbitHitY = false;
	}
	if (RabbitX<= 0)
	{
		RabbitX = 0;
		rabbitHitX = true;
	}
	else if (RabbitX >= 608)
	{
		RabbitX = 608;
		rabbitHitX = false;
	}


	//true‚Ìê‡‘«‚·ˆ—Afalse‚Ìê‡Œ¸‚ç‚·ˆ—
	if (enemyY<=0)
	{
		enemyY = 0;
		enemyHitY = true;
	}
	else if (enemyY>=448)
	{
		enemyY = 448;
		enemyHitY = false;
	}
	if (enemyX<=0)
	{
		enemyX = 0;
		enemyHitX = true;
	}
    else if (enemyX>=608)
	{
		enemyX = 608;
		enemyHitX = false;
	}
	
}

void Enemy::AdditionMove()
{
	if (RabbitX > 550)
	{
		enemyX = en_chara.Player_posX + 20;
	}
	if (en_map.time_count==10)
	{
		enemyX = rand_rX;
		enemyY =rand_rY;
	}
	
	if (RabbitX<400 && RabbitY<300)
	{
		RabbitY += 5;
	}

}

void Enemy::Drawcircle()
{
	for (int i = 0; i < 6; i++)
	{
       DrawCircle(circleX[i], circleY[i],5,0xffffff,DectionCircle[i]);
	}	
	
	
	
	
}

void Enemy::Draw()
{

	for (int y = 0; y < EnemyChipY; y++)
	{
		for (int x = 0; x < EnemyChipX; x++)
		{
			if (MakeEnemy[y][x]==1)
			{
			
			 DrawRectGraph(enemyX, enemyY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle, true);
				
			}
		}
	}
	
}

void Enemy::KillerRabbit(Character& e_chara)
{
	
	DrawRectGraph(RabbitX, RabbitY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
	
}


//false‚Ì‚É©‚ÉˆÚ“®@true‚Ì¨‚ÉˆÚ“®
void Enemy::EnemyMove() 
{

	if (IsFlag == false)
	{
		RabbitX -= rabgetX;
		RabbitY -=rabgetY;
	
		//-ó‘Ô
		if (rabbitHitY == true)
		{
			RabbitY += rabgetX;
		}
		if (rabbitHitX == true)
		{
			RabbitX += rabgetY;

		}
		//+ó‘Ô
		if (rabbitHitY == false)
		{
			RabbitY -=rabgetX;

		}
		if (rabbitHitX == false)
		{
			RabbitX -= rabgetY;

		}
	}
}

void Enemy::EnemyVerticalMove()
{
	if (IsFlag == false)
	{
		enemyY += getY;
		enemyX -= getX;
		if (enemyHitX == true)
		{
			enemyX += getX;
		}
		if (enemyHitX == false)
		{
			enemyX -= getX;
		}
		if (enemyHitY == true)
		{
			enemyY += getY;
		}
	    if (enemyHitY == false)
		{
			enemyY -= getY;
		}
	}

}

void Enemy::InitEnemy()
{
	
	if (enemyX > GameWidth-EnemyPerChraSize || enemyY > GameHeight-EnemyPerChraSize || enemyX < 0 || enemyY < 0)
	{
		IsFlag = true;	
	}
	else 
	{	
		IsFlag = false;
	}
	if (RabbitX > GameWidth-EnemyPerChraSize || RabbitY > GameHeight-EnemyPerChraSize || RabbitX < 0 || RabbitY < 0)
	{
		IsFlag = true;
		
	}
	else 
	{
		IsFlag = false;
	}
	

}



void Enemy::EnemyAirCollision(Character& e_chara)
{

	if (RabbitX > e_chara.Player_posX && RabbitY < e_chara.Player_posY && RabbitX - e_chara.Player_posX < 8
		|| RabbitY < e_chara.Player_posY && e_chara.Player_posY - RabbitY<8
		|| e_chara.Player_posX>RabbitX && e_chara.Player_posX - RabbitX<8
		|| RabbitY>e_chara.Player_posY && RabbitY - e_chara.Player_posY < 8)
	{
		DrawRectRotaGraph(e_chara.Player_posX + 30, e_chara.Player_posY, 0, 0, 120, 120, 1, 0, e_chara.EffectHandle, true);
		






	}


}






