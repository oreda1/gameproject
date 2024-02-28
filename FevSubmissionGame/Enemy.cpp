#include "Enemy.h"
#include"DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include <math.h>
class  Character character;
Map en_map;
SceneManager en_scene;


void Enemy::UpdateEnemy()
{
	//false + true -
	//���������̏���
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

	//true�̏ꍇ���������Afalse�̏ꍇ���炷����
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
	//if (RabbitX<350 && RabbitY<250)
	//{
	//	RabbitY += rabgetY;
	//	RabbitX -= rabgetX;
	//}
	if (enemyY<300&&enemyX<100)
	{
		enemyX += getX;
		enemyY -= getY;
	}
	
}

//���ド�C�t�Q�[�W�\��
void Enemy::Drawcircle()
{
	
	for (int i = 0; i < 6; i++)
	{
	   lifecolor[i] = {static_cast<int>(GetColor(255, 255, 255))};
       DrawCircle(circleX[i], circleY[i],5,lifecolor[i], DectionCircle[i]);
	}	

	//DrawFormatString(550, 50, 0xffffff, "%d,%d,\n%d,%d", enemyX, enemyY, RabbitX, RabbitY);
	
	
}

//�b�̕`��
void Enemy::Draw()
{

	DrawRectGraph(enemyX, enemyY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle, true);
	
}

//�E�T�M�̕`��
void Enemy::KillerRabbit(Character& e_chara)
{
	
	DrawRectGraph(RabbitX, RabbitY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
	
}


//false�̎��Ɂ��Ɉړ��@true�̎����Ɉړ�
//�G�l�~�[(�E�T�M)����
void Enemy::EnemyMove() 
{

	if (IsFlag == false)
	{
		RabbitX += rabgetX+1;
		RabbitY -= rabgetY;
		
		//-���
		if (rabbitHitY == true)
		{
			RabbitY +=7;
		}
		else if (rabbitHitX == true)
		{
			RabbitX += 7;

		}
		//+���
		if (rabbitHitY == false)
		{
			RabbitY -=8;

		} 
		else if (rabbitHitX == false)
		{
			RabbitX -= 8;

		}
		//get��0�̎��̏���
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

//�G�l�~�[(�b)����
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
		//get��0�̎��̏���
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

//�����蔻��
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

//�����蔻��
void Enemy::EnemyAirCollision()
{
	//�E��,����,�E��,����
	//���̏�����,�v���C���[���G��艺�ɂ��鎞�̓����蔻��
	//����̏�����,�v���C���[���G����ɂ��鎞�̓����蔻��
	if (RabbitX>character.Player_posX&&RabbitX-character.Player_posX<16
		&&character.Player_posY>RabbitY&&character.Player_posY-RabbitY<16

		||character.Player_posX>RabbitX&&character.Player_posX-RabbitX<16
		&&character.Player_posY>RabbitY && character.Player_posY - RabbitY < 16

		//||RabbitX>character.Player_posX&&RabbitX-character.Player_posX<16
		//&&RabbitY>character.Player_posY&&RabbitY-character.Player_posY<16

		//||character.Player_posX>RabbitX&&character.Player_posX-RabbitX<16
		//&&RabbitY>character.Player_posY&& RabbitY-character.Player_posY<16

        )
	{
		SetDrawBlendMode(DX_BLENDMODE_PMA_INVSRC, 50);
		
		
		
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
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 50);
	}
		
		
		
	
	
	//���̏�����,�v���C���[���G��艺�ɂ��鎞�̓����蔻��
	//����̏�����,�v���C���[���G����ɂ��鎞�̓����蔻��
	if (enemyX>character.Player_posX&&enemyX-character.Player_posX<16
		&&character.Player_posY>enemyY && character.Player_posY - enemyY<16

		||character.Player_posX>enemyX&&character.Player_posX-enemyX<16
		&&character.Player_posY>enemyY && character.Player_posY - enemyY<16

		//||enemyX>character.Player_posX&&enemyX-character.Player_posX<16
		//&&enemyY>character.Player_posY &&enemyY- character.Player_posY<16

		//||character.Player_posX>enemyX&&character.Player_posX-enemyX<16
		//&&enemyY>character.Player_posY&&enemyY-character.Player_posY<16
		
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


	
	if (DectionCircle[5] == false&&en_map.time_count<60)
	{
		
		//en_map.time= en_map.timescore;
		//en_map.timescore = en_map.timelimit - en_map.time;
		en_scene.GameOver = true;
		StopMusic();
		en_map.time_count = 0;
		enemyX, enemyY = 0;
		RabbitX, RabbitY = 0;
		ClearDrawScreen();
		DrawExtendFormatString(200, 200, 4, 3, 0xff0000, "GameOver");
		//DrawFormatString(230, 250, 0xffffff, "Time %f", en_map.timescore);
		DrawFormatString(250, 300, 0xffffff, "Plase Put ESC");
		
		
	}
	else
	{
		en_scene.GameOver = false;
	}
	
		
	
	
	
	
}






