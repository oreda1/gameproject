#include "Enemy.h"

void Enemy::Init()
{
	Enemy_pos[0] = VGet(320, 240, 0);
	Enemy_pos[1] = VGet(320, 240, 0);
	Enemy_pos[2] = VGet(320, 240, 0);
	Enemy_pos[3] = VGet(320, 240, 0);
	Enemy_pos[4] = VGet(320, 240, 0);
	Enemy_pos[5] = VGet(320, 240, 0);
	Enemy_pos[6] = VGet(320, 240, 0);
	Enemy_pos[7] = VGet(320, 240, 0);
	Enemy_pos[8] = VGet(320, 240, 0);
	Enemy_pos[9] = VGet(320, 240, 0);
	Enemy_pos[10] = VGet(320, 240, 0);
	Enemy_pos[11] = VGet(320, 240, 0);
	Enemy_pos[12] = VGet(320, 240, 0);
	Enemy_pos[13] = VGet(320, 240, 0);
	Enemy_pos[14] = VGet(320, 240, 0);
	Enemy_pos[15] = VGet(320, 240, 0);
	Enemy_pos[16] = VGet(320, 240, 0);
	Enemy_pos[17] = VGet(320, 240, 0);
	Enemy_pos[18] = VGet(320, 240, 0);
	Enemy_pos[19] = VGet(320, 240, 0);
	
	crop = VGet(448, 320, 0);


}

void Enemy::Draw()
{
	
	
	for (int i = 0; i < 20; i++)
	{
		
		DrawRectGraph(Enemy_pos[i].x, Enemy_pos[i].y, crop.x, crop.y, 64, 64, PlayerHandle, true);
		
	}
	

}

void Enemy::Collision()
{
	

}
