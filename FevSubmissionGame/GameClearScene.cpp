#include "GameClearScene.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "Map.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include <memory>

SceneManager clear_scene;
Map map;
TitleScene*title;



GameClearScene::GameClearScene()
{
	

}

GameClearScene::~GameClearScene()
{
}

void GameClearScene::Init()
{
}

void GameClearScene::Draw()
{
	char key[256];
	GetHitKeyStateAll(key);
	for (int i = 0; i < 256; i++) {	//i番のキーコードに対応するキーが押されていたら
		if (key[i] != 0) {
			key[i]++;				//加算
		}
		else {						//押されていなければ
		   key[i] = 0;
		}
		
		return;

	}

	
}

void GameClearScene::Update()
{
}

void GameClearScene::End()
{
}
