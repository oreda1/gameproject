#include "Enemy.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "Character.h"
#include "SceneBase.h"
#include <math.h>
// Removed global variables - now passed as parameters

Enemy::Enemy(), RabbitX(200), RabbitY(400), enemyX(300), enemyY(368)
{
};



void Enemy::Start()
{
	RabbitX = 200;
	RabbitY = 400;
	
	// Initialize enemy variables
	enemyX = 300;
	enemyY = 368;
	
	// Initialize movement variables
	getX = GetRand(5);
	getY = GetRand(5);
	rabgetX = GetRand(5);
	rabgetY = GetRand(5);
	
	// Initialize hit flags
	rabbitHitX = false;
	rabbitHitY = false;
	enemyHitX = false;
	enemyHitY = false;
	IsFlag = false;
	
	// Initialize random positions
	rand_rX = GetRand(600);
	rand_rY = GetRand(450);
	rand_eX = GetRand(600);
	rand_eY = GetRand(448);
	
	// Initialize circle detection
	circlecount = -1;
	for (int i = 0; i < 6; i++) {
		DectionCircle[i] = true;
	}
	
	// Initialize circle positions
	circleX[0] = 10; circleX[1] = 10; circleX[2] = 10;
	circleX[3] = 25; circleX[4] = 25; circleX[5] = 25;
	circleY[0] = 25; circleY[1] = 45; circleY[2] = 65;
	circleY[3] = 25; circleY[4] = 45; circleY[5] = 65;
	
	// Initialize colors
	circlecolor = GetColor(255, 0, 0);
	for (int i = 0; i < 6; i++) {
		lifecolor[i] = GetColor(255, 255, 255);
	}
	
	// Load graphics
	EnemyHandle = LoadGraph("RoperMan.png");
	EnemyHandle2 = LoadGraph("pyon-manjiro1.png");
}



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

	// Random enemy repositioning logic can be implemented here if needed
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

	
	
}


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
			 this->DectionCircle[tnis->circlecount] = false;
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

// 衝突判定のヘルパー関数
bool Enemy::CheckCollision(int x1, int y1, int x2, int y2, int distance)
{
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	return (dx < distance && dy < distance);
}








