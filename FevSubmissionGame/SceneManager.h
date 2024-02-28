#pragma once
#include "DxLib.h"
class SceneBase;
class SceneManager
{
public:
	SceneManager();
	virtual~SceneManager();

	typedef enum Scene
	{
		Title,
		S_Option,
		Playing,
		Clear,
		Return_Title,
		End,
	};


//åªç›ÇÃÉVÅ[ÉìÇîªï 
Scene NowScene;

bool GameClear;
bool GameOver;

bool DivideScene();
bool ChangeScene();
void ExplanationScene();

void ExplanationText();

//int NomalFontHandle = CreateFontToHandle(NULL, 30, 1, DX_FONTTYPE_NORMAL);


private:
	void Scene_ChangeKey();
	char scene_key[256];


 

};

