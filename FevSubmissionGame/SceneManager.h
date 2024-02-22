#pragma once
#include "DxLib.h"
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	typedef enum Scene
	{
		Title,
		S_Option,
		Playing,
		Clear,
		Return_Title,
		End,
		Clear
	};

//åªç›ÇÃÉVÅ[ÉìÇîªï 
Scene NowScene;

<<<<<<< HEAD
<<<<<<< HEAD
=======
bool GameClear;
bool GameOver;
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
=======
bool GameClear;
bool GameOver;
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90

bool DivideScene();
bool ChangeScene();
void DecisionScene();

void ExplanationText();

//int NomalFontHandle = CreateFontToHandle(NULL, 30, 1, DX_FONTTYPE_NORMAL);


private:
	void Scene_ChangeKey();
	char scene_key[256];


 

};

