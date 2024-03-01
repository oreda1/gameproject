#pragma once
#include "DxLib.h"
class SceneBase;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

bool GameClear;
bool GameOver;

bool DivideScene();
bool ChangeScene();
void ExplanationScene();

void ExplanationText();
void Init();



private:
	SceneBase* base_manager;
	void Scene_ChangeKey();
	char scene_key[256];


 

};

