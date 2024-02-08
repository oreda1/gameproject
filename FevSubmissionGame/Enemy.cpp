#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
class  Character character;
Map en_map;


void Enemy::UpdateEnemy()
{
	//false + true -
	//Á‚¦‚½‚Ìˆ—
	if (RabbitY< 0)
	{
		RabbitY = 0;
		rabbitHitY = true;
	}
	else if (RabbitY >448)
	{
		RabbitY = 448;
		rabbitHitY = false;
	}
	if (RabbitX< 0)
	{
		RabbitX = 0;
		rabbitHitX = true;
	}
	else if (RabbitX > 608)
	{
		RabbitX = 608;
		rabbitHitX = false;
	}

	//true‚Ìê‡‘«‚·ˆ—Afalse‚Ìê‡Œ¸‚ç‚·ˆ—
	if (enemyY<0)
	{
		enemyY = 0;
		enemyHitY = true;
	}
	else if (enemyY>448)
	{
		enemyY = 448;
		enemyHitY = false;
	}
	if (enemyX<0)
	{
		enemyX = 0;
		enemyHitX = true;
	}
    else if (enemyX>608)
	{
		enemyX = 608;
		enemyHitX = false;
	}
	
}

void Enemy::AdditionMove()
{
	if (RabbitX > 550)
	{
		enemyX = character.Player_posX + 20;
	}
	if (en_map.time_count==10)
	{
		enemyX = rand_rX;
		enemyY =rand_rY;
	}
	
	if (RabbitX<400 && RabbitY<250)
	{
		RabbitY += 5;
	}
	
}

void Enemy::Drawcircle()
{
	
	for (int i = 0; i < 6; i++)
	{
	   lifecolor[i] = {static_cast<int>(GetColor(255, 255, 255))};
       DrawCircle(circleX[i], circleY[i],5,lifecolor[i], DectionCircle[i]);
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
		RabbitX +=rabgetY;
		RabbitY -=rabgetX;
	
		//-ó‘Ô
		if (rabbitHitY == true)
		{
			RabbitY += rabgetX;
		}
		else if (rabbitHitX == true)
		{
			RabbitX += rabgetY;

		}
		//+ó‘Ô
		if (rabbitHitY == false)
		{
			RabbitY -=rabgetX;

		} 
		else if (rabbitHitX == false)
		{
			RabbitX -= rabgetY;

		}
	}
}

void Enemy::EnemyVerticalMove()
{
	if (IsFlag == false)
	{
		
		enemyY +=getY+2;
		enemyX -=getX+2;
		if (enemyHitX == true)
		{
			enemyX += 1+getY;
		}
		else if (enemyHitX == false)
		{
			enemyX -= 1+getY;
		}
		if (enemyHitY == true)
		{
			enemyY += 1+getX;
		}
	    else if (enemyHitY == false)
		{
			enemyY -= 1+getX;
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

void Enemy::EnemyAirCollision()
{

	if (character.Player_posY>RabbitY&&character.Player_posX<RabbitX&&character.Player_posY-RabbitY<16&&character.Player_posX-RabbitX<16)
	{
		DrawRectRotaGraph(character.Player_posX + 30, character.Player_posY, 0, 0, 120, 120, 1, 0, character.EffectHandle, true);
		circlecount = circlecount + 1;
		switch (circlecount)
		{
		case 0:
			DectionCircle[circlecount] = false;
			break;
		case 1:
			DectionCircle[circlecount] = false;
			break;
		case 2:
			DectionCircle[circlecount] = false;
			break;
		case 3:
			DectionCircle[circlecount] = false;
			break;
		case 4:
			DectionCircle[circlecount] = false;
			break;
		case 5:
			DectionCircle[circlecount] = false;
			break;
		default:
			break;
		}
	}
	//‹ó’†‚É‚¢‚é‚Æ‚«‚Ì©‚Æª‚Ì“–‚½‚è”»’è,¨‚©‚ç‚Ì‚Ì“–‚½‚è”»’è,
	if (enemyX > character.Player_posX && enemyX - character.Player_posX<4
		|| character.Player_posX>enemyX && character.Player_posX - enemyX<4
		|| enemyY>character.Player_posY && enemyY - character.Player_posY<4
		|| character.Player_posY>enemyY && character.Player_posY - enemyY < 4)
	{
		SetDrawBlendMode(DX_BLENDMODE_INVSRC, 50);

		switch (circlecount)
		{
		case 0:
			DectionCircle[circlecount] = false;
			break;
		case 1:
			DectionCircle[circlecount] = false;
			break;
		case 2:
			DectionCircle[circlecount] = false;
			break;
		case 3:
			DectionCircle[circlecount] = false;
			break;
		case 4:
			DectionCircle[circlecount] = false;
			break;
		case 5:
			DectionCircle[circlecount] = false;
			break;
		default:
			break;
		}
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

}






