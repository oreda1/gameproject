#include "Player.h"
#include "PlayScene.h"



void Player::Init()
{
	pos = VGet(0, 350, 0);
	vibration = VGet(10, 10, 0);
	velocity = VGet(0, -100, 1);
	gravity = VGet(0, 10, 0);
	Chara_Number = 24;
}

void Player::Draw()
{
  
	DrawBillboard3D(pos, 0, 0, 2, 180, handle[Chara_Number], true);
  
   Chara_Number += 1;
   if (Chara_Number>=27)
   {
	   Chara_Number = 24;
	   WaitTimer(10);
   }
  


}

void Player::Update()
{
	prev_y = pos.y;
	gravity.y = -1;
	
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x += 20;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x -= 20;
	}
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		gravity.y = -60;
		
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		
	}
	
	if (pos.y>286)
	{
		pos.y = 350;
	}
	
	


	temp_y = pos.y;
	pos.y += (pos.y - temp_y) + gravity.y;
	prev_y = temp_y;
	gravity.y = 1;

	

}

void Player::Collision()
{
	//画面サイズからプレイヤーの位置を出し当たり判定を行う
	GetScreenState(&Width, &Height, &Color);
	if (Getpos().x>pos.x&&Getpos().x-pos.x<4)
	{
		ClearDrawScreen();

	}

	
	
	

}
