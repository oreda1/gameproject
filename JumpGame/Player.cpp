#include "Player.h"

void Player::Init()
{
	pos = VGet(0, 350, 0);
	velocity = VGet(0, -100, 1);
	gravity = VGet(0, 10, 0);
	
}

void Player::Draw()
{
	
	for (int i = 24; i < 27; i++)
	{
       DrawGraph(pos.x, pos.y, handle[i], true);
	   
	}
	
	
	
	

	
}

void Player::Update()
{
	prev_y = pos.y;
	gravity.y = -1;
	
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
	
	}
	if (CheckHitKey(KEY_INPUT_SPACE)==1)
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

}
