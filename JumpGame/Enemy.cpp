#include "Enemy.h"

void Enemy::Init()
{
	int handle[20] = {LoadGraph("3_DF_Actor.png")};
	pos = VGet(400, 350, 0);
	velocity = VGet(0, 0, 0);
	crop = VGet(384, 320, 0);
}

void Enemy::Draw()
{
	DrawRectGraph(pos.x, pos.y, crop.x, crop.y, Chara_Size, Chara_Size, handle, true);
}

void Enemy::Update()
{
}
