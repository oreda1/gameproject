#include "GameScene.h"
#include "BaseNumber.h"
#include "Dxlib.h"

void GameScene::Update()
{
	
	//�Q�[���V�[���̏���
	int MapHandle = LoadGraph("[A]Water3_Cave1_pipo.png");
	DrawGraph(100,100, MapHandle, false);
}



void GameScene::Init()
{
}
