#include "PlayScene.h"
void PlayScene::Init()
{
	BackPos = VGet(320, 240, 2);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{	
	
}

void PlayScene::BackGround()
{
	int Back = LoadGraph("pipo-bg004a.jpg");
	turn -=1.5;
	WaitTimer(20);
	DrawRota2Graph3D(BackPos.x, BackPos.y, 0, BackPos.x, BackPos.y, BackPos.z, BackPos.z, turn, Back, true);
}



void PlayScene::Timer()
{
	time_count += time;
	DrawExtendFormatString(0,0,2,2, 0xffffff, "%f", time_count);
}
