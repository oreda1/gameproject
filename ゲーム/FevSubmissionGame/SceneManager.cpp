#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"


TitleScene *scene_title;
Map* scene_map;
OptionScene* scene_option;


SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{


}

void SceneManager::ChangeScene()
{
	if (NowScene==sceneitem::Title)
	{
		TitleScene&gpUpdateKey();
		scene_title->Update();
		scene_title->MakeSelectTriangle();
		NowScene = sceneitem::Title;
	}
	if (NowScene==sceneitem::S_Option)
	{
		OptionScene&OptionText();
	    OptionScene&DrawFrame();
		NowScene = sceneitem::S_Option;
	}
	if (NowScene==sceneitem::Playing)
	{
		scene_map->Draw();
		scene_map->BackGround();
		NowScene = sceneitem::Playing;
	}
	if (NowScene==sceneitem::End)
	{
		false;
		NowScene = sceneitem::End;
	}

	
}

void SceneManager::DecisionScene(sceneitem NextScene)
{
	NowScene = NextScene;
}

void SceneManager::DivideScene()
{
	

}
