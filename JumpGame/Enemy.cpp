#include "Enemy.h"

void Enemy::Init()
{
	pos = VGet(400, 350, 0);
	velocity = VGet(0, 0, 0);
	
	
}

void Enemy::Draw()
{
	DrawGraph(pos.x, pos.y, handle[66], true);
}

void Enemy::Update()
{

	
}


