#include "Enemy.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include "SceneBase.h"
// <math.h> not needed after removing CheckCollision
// Removed global variables - now passed as parameters

Enemy::Enemy() : RabbitX(200), RabbitY(400), enemyX(300), enemyY(368)
{
    // Initialize movement variables
    getX = GetRand(5);
    getY = GetRand(5);
    rabgetX = GetRand(5);
    rabgetY = GetRand(5);

    // Initialize hit flags and state
    rabbitHitX = false;
    rabbitHitY = false;
    enemyHitX = false;
    enemyHitY = false;
    IsFlag = false;

    // Initialize circle detection state
    circlecount = -1;
    for (int i = 0; i < 6; i++) {
        DectionCircle[i] = true;
    }

    // Load graphics
    EnemyHandle = LoadGraph("RoperMan.png");
    EnemyHandle2 = LoadGraph("pyon-manjiro1.png");
};



// Removed unused Start()



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


// Removed unused AdditionMove()

// Removed unused Drawcircle()


//�b�̕`��
void Enemy::Draw()
{
	
	DrawRectGraph(enemyX, enemyY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle, true);
	DrawRectGraph(RabbitX, RabbitY, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyPerChraSize, EnemyHandle2, true);
}




//false�̎��Ɂ��Ɉړ��@true�̎����Ɉړ�
//�G�l�~�[(�E�T�M)����
void Enemy::EnemyMove()
{

	EnemyMove_a();
	EnemyVerticalMove();

} 

void Enemy::EnemyMove_a()
{
	

	if (IsFlag == false)
	{
		RabbitX += rabgetX + 1;
		RabbitY -= rabgetY;

		//-���
		if (rabbitHitY == true)
		{
			RabbitY += 7;
		}
		else if (rabbitHitX == true)
		{
			RabbitX += 7;

		}
		//+���
		if (rabbitHitY == false)
		{
			RabbitY -= 8;

		}
		else if (rabbitHitX == false)
		{
			RabbitX -= 8;

		}
		//get��0�̎��̏���
		if (rabgetX == 0 && rabbitHitX == true)
		{
			RabbitX += 6;
		}
		if (rabgetX == 0 && rabbitHitX == false)
		{
			RabbitX -= 7;
		}
		if (rabgetY == 0 && rabbitHitY == true)
		{
			RabbitY += 6;
		}
		if (rabgetY == 0 && rabbitHitY == false)
		{
			RabbitY -= 6;
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

// Removed unused InitEnemy()

//�����蔻��
void Enemy::EnemyAirCollision(Character& character, Map& map, SceneManager& scene)
{
	//�E��,����,�E��,����
	//���̏�����,�v���C���[���G��艺�ɂ��鎞�̓����蔻��
	//����̏�����,�v���C���[���G����ɂ��鎞�̓����蔻��
	if (RabbitX>character.Player_posX&&RabbitX-character.Player_posX<16
		&& character.Player_posY > this->RabbitY && character.Player_posY - this->RabbitY < 16

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
			this->DectionCircle[this->circlecount] = false;
			 break;
		 case 1:
			 this->DectionCircle[this->circlecount] = false;
			 break;
		 case 2:
			 this->DectionCircle[this->circlecount] = false;
			 break;
		 case 3:
			 this->DectionCircle[this->circlecount] = false;
			 break;
		 case 4:
			 this->DectionCircle[this->circlecount] = false;
			 break;
		 case 5:
			 this->DectionCircle[this->circlecount] = false;
			 break;
		 default:
			 break;
		 }
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 50);
	}
		
		
		
	
	

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


	
	if (DectionCircle[5] == false && map.time_count < 60)
	{
		// Game over condition
		scene.GameOver = true;
		StopMusic();
		map.time_count = 0;
		ClearDrawScreen();
		DrawExtendFormatString(200, 200, 4, 3, 0xff0000, "GameOver");
		DrawFormatString(250, 300, 0xffffff, "Please Press ESC");
	}
	else
	{
		scene.GameOver = false;
	}
	
		
	
	
	
	
}










