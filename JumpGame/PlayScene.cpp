#include "PlayScene.h"
void PlayScene::Init()
{
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
	turn -= 1.5+1.5;
	DrawRota2Graph3D(320,240,0,320,240,2,2,turn,Back,true);
}

void PlayScene::Timer()
{
	time_count += time;
	DrawExtendFormatString(0,0,2,2, 0xffffff, "%f", time_count);
}
