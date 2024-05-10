#include "Enemy.h"

void Enemy::Init()
{
	pos = VGet(400, 350, 0);
	velocity = VGet(0, 0, 0);
	Chara_Number = 66;
	
	
}

void Enemy::Draw()
{
	DrawGraph(pos.x, pos.y, handle[Chara_Number], true);
	Chara_Number += 1;
	if (Chara_Number>=69)
	{
		Chara_Number = 66;
	}
	WaitTimer(10);
	if (pos.x<-128)
	{
		pos = VGet(700, 350, 0);
	
	}
	
}

void Enemy::Update()
{
	pos.x-=3;

	
}


