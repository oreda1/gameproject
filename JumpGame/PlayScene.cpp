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
	DrawGraph(0, 0, Back, false);
}
