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
	//消えた時の処理
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

	//trueの場合足す処理、falseの場合減らす処理
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

	if (en_map.time_count==10)
	{
		enemyX = rand_rX;
		enemyY =rand_rY;
	}
	if (RabbitX<350 && RabbitY<250)
	{
		RabbitY += rabgetY;
		RabbitX -= rabgetX;
	}
	if (enemyY<300&&enemyX<100)
	{
		enemyX += getX;
		enemyY -= getY;
	}
	
}

void Enemy::Drawcircle()
{
	
	for (int i = 0; i < 6; i++)
	{
	   lifecolor[i] = {static_cast<int>(GetColor(255, 255, 255))};
       DrawCircle(circleX[i], circleY[i],5,lifecolor[i], DectionCircle[i]);
	}	

	DrawFormatString(550, 50, 0xffffff, "%d,%d,\n%d,%d", enemyX, enemyY, RabbitX, RabbitY);
	
	
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


//falseの時に←に移動　trueの時→に移動
void Enemy::EnemyMove() 
{

	if (IsFlag == false)
	{
		RabbitX += rabgetX-1;
		RabbitY -= rabgetY;
		
		//-状態
		if (rabbitHitY == true)
		{
			RabbitY +=7;
		}
		else if (rabbitHitX == true)
		{
			RabbitX += 7;

		}
		//+状態
		if (rabbitHitY == false)
		{
			RabbitY -=8;

		} 
		else if (rabbitHitX == false)
		{
			RabbitX -= 8;

		}
		//getが0の時の処理
		if (rabgetX== 0 && rabbitHitX == true)
		{
			RabbitX += 6;
		}
		if (rabgetX == 0 && rabbitHitX == false)
		{
			RabbitX-= 7;
		}
		if (rabgetY == 0 && rabbitHitY == true)
		{
			RabbitY+= 6;
		}
		if (rabgetY == 0 && rabbitHitY== false)
		{
			RabbitY-= 6;
		}
	}
}

void Enemy::EnemyVerticalMove()
{
	if (IsFlag == false)
	{
		enemyX-=getX;
		enemyY+=getY;

		if (enemyHitX == true)
		{
			enemyX += 7;
		}
		else if (enemyHitX == false)
		{
			enemyX -= 5;
		}
		if (enemyHitY == true)
		{
			enemyY += 8;
		}
	    else if (enemyHitY == false)
		{
			enemyY -= 7;
		}
		//getが0の時の処理
		if (getX==0&&enemyHitX==true)
		{
			enemyX += 8;
		}
		if (getX==0&&enemyHitX==false)
		{
			enemyX -= 5;
		}
		if (getY==0&&enemyHitY==true)
		{
			enemyY += 7;
		}
		if (getY==0&&enemyHitY==false)
		{
			enemyY -= 5;
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
	
	if (RabbitX>character.Player_posX&&RabbitX-character.Player_posX<8
		&&character.Player_posX>RabbitX&&character.Player_posX-RabbitX<8
		&&RabbitY>character.Player_posY&&RabbitY-character.Player_posY<8
		&&character.Player_posY>RabbitY&&character.Player_posY-RabbitY<8)
	{
		DrawRectRotaGraph(character.Player_posX+30, character.Player_posY, 0, 0, 120, 120, 1, 0, character.EffectHandle, true);
		
		
         circlecount = circlecount+1;

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
	//空中にいるときの←と↑の当たり判定,→からのの当たり判定,
	if (enemyX>character.Player_posX&&enemyX-character.Player_posX<8
		&& character.Player_posY>enemyY && character.Player_posY - enemyY<8
		||character.Player_posX>enemyX&&character.Player_posX-enemyX<8
		&&enemyY>character.Player_posY&&enemyY-character.Player_posY<8
		)
	{
		SetDrawBlendMode(DX_BLENDMODE_INVSRC, 50);
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
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}



	if (DectionCircle[5] == false)
	{
		StopMusic();
		ClearDrawScreen();
		DrawExtendFormatString(250, 200, 2, 2, 0xffffff, "GameOver\nPlase Put ESC");
		
		
	}
	
}






