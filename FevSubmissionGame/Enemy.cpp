#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
Character en_chara;


void Enemy::UpdateEnemy()
{
	//false + true -
	//Á‚¦‚½Žž‚Ìˆ—
	if (RabbitX[0]>640||RabbitY[0]>452)
	{
		enemyHit = false;
	}
	if (RabbitX[0] < -10 || RabbitY[0] < -10)
	{
		enemyHit = true;
	}
	if (enemyY<0||enemyY > 448)
	{
		enemyHitY = true;
	}
	if (enemyX<0||enemyX > 608)
	{
	  enemyHitY = false;
	
	}
	
	

}

void Enemy::Drawcircle()
{
	for (int i = 0; i < 3; i++)
	{
       DrawCircle(circleX[i], circleY[i],5,0xffffff,DectionCircle);
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
			
			DrawRectGraph(enemyX, enemyY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle, true);
				
			}
		}
	}
	
}


void Enemy::KillerRabbit(Character& e_chara)
{
	
	DrawRectGraph(RabbitX[0], RabbitY[0], EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
	
	
}


//false‚ÌŽž‚É©‚ÉˆÚ“®@true‚ÌŽž¨‚ÉˆÚ“®
void Enemy::EnemyMove() 
{
	
	
	if (enemyHit!=false&& enemyHit!=true)
	{
		RabbitX[0] += 5;
		
	}
	//‰Šú‚ÌˆÚ“®
	if (enemyHit == false)
	{
		RabbitX[0] -= 5;
		FirstHit = false;
		
	}
	if (enemyHit == true)
	{
		
		RabbitX[0] += 5;
		RabbitY[0] -= 5;
		FirstHit = true;
		
	}
	//‚»‚êˆÈŠO‚ÌˆÚ“®
	if (enemyHit == false&&FirstHit==false)
	{
		RabbitX[0] -= 5;
		RabbitY[0] += 5;
	}
	
	
	if (RabbitY[0] < 0 && FirstHit == true)
	{
		
		RabbitY[0] += 5;
		RabbitX[0] += 5;
	}
	


	

}

void Enemy::EnemyVerticalMove()
{

	//Å‰‚ÌˆÚ“®
	if (FirstHitY!=true&&FirstHitY!=false)
	{
		enemyY -= 5;
		enemyHitY = true;
		
	}
	if (enemyHitY==true)
	{
		enemyY += 5;
		

	}
	if (enemyHitY==false)
	{
		enemyY += 2;
		enemyX -= 5;

	}
	//-ó‘Ô
	if (FirstHitY==false&&enemyHitY==false)
	{
		enemyX += 5;
	
	}
	//+ó‘Ô
	if (FirstHitY==true&&enemyHitY==true)
	{
		
		enemyY -= 5;
		
	}


}

void Enemy::EnemyWallBumped()
{

	if (RabbitY[0]>388)
	{
		RabbitY[0] = 388;
	}


}

void Enemy::EnemyAirCollision(Character& e_chara)
{
	if (RabbitX[0]>e_chara.Player_posX&&RabbitY[0]<e_chara.Player_posY&&RabbitX[0]-e_chara.Player_posX<8
		||RabbitY[0]<e_chara.Player_posY&&e_chara.Player_posY-RabbitY[0]<8
		||e_chara.Player_posX>RabbitX[0]&&e_chara.Player_posX-RabbitX[0]<8
		||RabbitY[0]>e_chara.Player_posY&&RabbitY[0]-e_chara.Player_posY<8)
	{
		DrawRectRotaGraph(e_chara.Player_posX + 30, e_chara.Player_posY, 0, 0, 120, 120, 1, 0, e_chara.EffectHandle, true);
		
	}
	

}






