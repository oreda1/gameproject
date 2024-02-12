#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"



TitleScene *scene_title;
Map* scene_map;
OptionScene *scene_option;

TitleScene s_title;



SceneManager::SceneManager():
	NowScene(Title)
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

//���s��
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
	//ChangeFont("NomalFontHandle");
	DrawString(0, 100, "�X�y�[�X�L�[�ŃW�����v\nESC�L�[�ŏI��", 0xff0000);
	DrawString(0, 135, "�G��60�b�����炸\n�����c��΃Q�[���N���A��!!",0xff0000);
	DrawString(470, 0, "�f�ޒ񋟎җl", 0xfffff);
	DrawString(430, 20, "    �҂ۂ�q�ɗl\nArtificial Providence�l\n       ���ꓯ",0xffffff);

}
