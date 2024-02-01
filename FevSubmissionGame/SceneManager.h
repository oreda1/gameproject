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
		Return_Title,
		End
	};

//åªç›ÇÃÉVÅ[ÉìÇîªï 
Scene NowScene;



bool DivideScene();
bool ChangeScene();
void DecisionScene();

void ExplanationScene();

int NomalFontHandle = CreateFontToHandle(NULL, 30, 1, DX_FONTTYPE_NORMAL);





};

