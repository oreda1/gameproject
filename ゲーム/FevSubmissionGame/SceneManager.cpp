#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"


TitleScene *scene_title;
Map* scene_map;
OptionScene *scene_option;




SceneManager::SceneManager()
{
	scene_title = new TitleScene;
	scene_map = new Map;
	scene_option = new OptionScene;

}

SceneManager::~SceneManager()
{


}

void SceneManager::DecisionScene()
{
	
	DivideScene();
	ChangeScene();

}



void SceneManager::DivideScene()
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
	
	

}

//Às®
void SceneManager::ChangeScene()
{
	
	if (NowScene==Title)
	{ 
		scene_title->gpUpdateKey();
		scene_title->Update();
		scene_title->MakeSelectTriangle();
		
	}
	else if (NowScene==S_Option)
	{ 

	  scene_option->OptionText();
	  scene_option->DrawFrame();
	
	}
    else if (NowScene==Playing)
	{
		
		scene_map->Draw();
		scene_map->TimeLimit();
		scene_map->BackGround();
	}
	else if (NowScene==End)
	{
		return;
	}

}

void SceneManager::ExplanationScene()
{
	DrawString(100, 100, "¨ƒL[‚ÅˆÚ“®", 0xffffff);

}
