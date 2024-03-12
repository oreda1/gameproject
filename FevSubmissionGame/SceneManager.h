#pragma once
#include "DxLib.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"
#include "Enemy.h"
#include "Character.h"

class SceneManager
{

public:

	//ÉVÅ[ÉìóÒãìå^
	typedef enum Scene
	{
		Title,
		Playing,
		Option,
	};
	Scene NowScene;

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
	Map* map;
	Character* chara;
	Enemy* enemy;
    TitleScene* title;
	OptionScene* optipn;

	void Scene_ChangeKey();
	char scene_key[256];


 

};

