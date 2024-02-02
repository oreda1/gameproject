#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
Character en_chara;


void Enemy::UpdateEnemy()
{
	//false + true -
	//Á‚¦‚½‚Ìˆ—
	if (RabbitY<= 0)
	{
		rabbitHitY = true;
	}
	else if (RabbitY >= 448)
	{
		rabbitHitY = false;
	}
	if (RabbitX<= 0)
	{
		rabbitHitX = true;
	}
	else if (RabbitX >= 608)
	{
		rabbitHitX = false;
	}


	//true‚Ìê‡‘«‚·ˆ—Afalse‚Ìê‡Œ¸‚ç‚·ˆ—
	if (enemyY<=0)
	{
		enemyHitY = true;
	}
	if (enemyY>=448)
	{
		enemyHitY = false;
	}
	if (enemyX<=0)
	{
		enemyHitX = true;
	}
    if (enemyX>=608)
	{
		enemyHitX = false;
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
	

	
	//-ó‘Ô
	if (rabbitHitY == true)
	{
		RabbitY += getX;
	}
	if (rabbitHitX == true)
	{
		RabbitX+= getY;

	}
	//+ó‘Ô
	if (rabbitHitY == false)
	{
		RabbitY -= getX;

	}
	if (rabbitHitX== false)
	{
		RabbitX -= getY;

	}
	//—¼•û–‚½‚·®
	if (rabbitHitX == true && rabbitHitY == true)
	{
		RabbitX += 3;
		RabbitY+= 3;
	}
	if (rabbitHitX == false && rabbitHitY == false)
	{
		RabbitX -= 3;
		RabbitY-= 3;
	}
	
	if (IsFlag==false)
	{
      RabbitX -= 4;
	  RabbitY += 2;
	}
	

}

void Enemy::EnemyVerticalMove()
{

	if (IsFlag==false)
	{
		enemyX+= getX;
		enemyY-= getY;
	}
		
	//0<enemyX<640
	//0<enemyY<448 

		//-ó‘Ô
		if (enemyHitY == true)
		{
			enemyY += getX;
		}
		if (enemyHitX == true)
		{
			enemyX += getY;

		}
		//+ó‘Ô
		if (enemyHitY == false)
		{
			enemyY -= getX;

		}
		if (enemyHitX == false)
		{
		   enemyX -= getY;

		}
		//—¼•û–‚½‚·®
		if (enemyHitX == true && enemyHitY == true)
		{
			enemyX += 2;
			enemyY += 2;
		}
		if (enemyHitX == false && enemyHitY == false)
		{
			enemyY -= 2;
			enemyX -= 2;
		}


		
}

void Enemy::InitEnemy()
{
	
	if (enemyX > GameWidth-EnemyPerChraSize || enemyY > GameHeight-EnemyPerChraSize || enemyX < 0 || enemyY < 0)
	{
		IsFlag = true;
		enemyX = rand_eX; enemyY = rand_eY;
	}
	else
	{	
		IsFlag = false;
	}
	if (RabbitX > GameWidth-EnemyPerChraSize || RabbitY > GameHeight-EnemyPerChraSize || RabbitX < 0 || RabbitY < 0)
	{
		IsFlag = true;
		RabbitX = rand_rX; RabbitY = rand_rY;
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
		for (int i = 0; i < 6; i++)
		{
			
			DectionCircle[i]= false;



		}
	}


}






