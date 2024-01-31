#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"


TitleScene *scene_title;
Map* scene_map;
OptionScene *scene_option;

TitleScene s_title;



SceneManager::SceneManager()
{
	scene_title = new TitleScene;
	scene_map = new Map;
	scene_option = new OptionScene;

}

SceneManager::~SceneManager()
{
	delete scene_title;
	scene_title = nullptr;
	delete scene_map;
	scene_map = nullptr;
	delete scene_option;
	scene_option = nullptr;

}

void SceneManager::DecisionScene()
{
	DivideScene();
	ChangeScene();
}



bool SceneManager::DivideScene()
{
	
	NowScene=Title;

	if (scene_title->triangle.y2==290)
	{
		NowScene = Playing;
	}
	else if (scene_title->triangle.y2==330)
	{
		NowScene = S_Option;
	}
	else if (titleP.Key[KEY_INPUT_RETURN]&&NowScene==Playing||NowScene==S_Option)
	{
		NowScene = Return_Title;
	}
	return false;
}

//実行式
bool SceneManager::ChangeScene()
{
	
	if (NowScene==Title)
	{ 
		return true;
		scene_title->gpUpdateKey();
		scene_title->Update();
		scene_title->MakeSelectTriangle();
		
	}
	else if (NowScene==S_Option)
	{ 
	  scene_option->OptionText(s_title);
	  scene_option->DrawFrame();
	
	}
    else if (NowScene==Playing)
	{
		return false;
		scene_map->Draw();
		scene_map->TimeLimit();
		scene_map->BackGround();
	}
	else if (NowScene==Return_Title)
	{
		return true;
	
	}
	else if (NowScene==End)
	{
		
	}

}

void SceneManager::ExplanationScene()
{

	DrawString(0, 100, "スペースキーでジャンプ", 0xffffff);
	DrawString(0, 130, "敵に60秒当たるな!!",0xffffff);

}
