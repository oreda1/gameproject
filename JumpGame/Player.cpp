#include "Player.h"

void Player::Init()
{
	pos = VGet(300, 350, 0);
	velocity = VGet(0, -100, 20);
	crop = VGet(0, 128, 0);

}

void Player::Draw()
{
	
	DrawRectGraph(pos.x, pos.y,crop.x, crop.y, Chara_Size, Chara_Size,handle, true);
	
}

void Player::Update()
{
	
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos = VAdd(pos, VGet(100, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos = VAdd(pos, VGet(-100, 0, 0));
	}
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		pos= VAdd(pos, VGet(0, -100, 0));
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos= VAdd(pos, VGet(0, -100, 0));
	}
	velocity.y += velocity.z;
	pos.y += velocity.y;
	if (pos.y>286)
	{
		pos.y = 350;
	}

	
	

}
