#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"
#include "Enemy.h"
#include "Character.h"




TitleScene *scene_title;
Map* scene_map;
OptionScene *scene_option;
Enemy* scene_enemy;
Character* scene_character;



TitleScene title;






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


//シーンをそれぞれ判別する関数
bool SceneManager::DivideScene()
{
	NowScene=Title;
	if (titleP.Key[KEY_INPUT_Z])
	{
		NowScene = Playing;
	}
	else if (titleP.Key[KEY_INPUT_O])
	{
		NowScene = S_Option;
	}
	else if (scene_map->time_count>60)
	{
		NowScene = Clear;
	}
	else if (titleP.Key[KEY_INPUT_RETURN]&&NowScene==Playing||NowScene==S_Option)
	{
		NowScene = Return_Title;
	}
	return NowScene;

	
	
}

//NowSceneを判別し、それぞれのシーンにあわせた処理を行う
bool SceneManager::ChangeScene()
{
	
	if (NowScene == Title)
	{
		scene_title->Update();
		ExplanationText();
		scene_title->TitleMusic();

	}
	else if (NowScene == S_Option)
	{
		scene_option->DrawFrame();
		scene_option->OptionText(title);
	

	}
	else if (NowScene == Playing)
	{
		scene_character->Draw();
		scene_character->FallCollision();
		scene_enemy->Draw();
		scene_enemy->EnemyMove();
		scene_enemy->EnemyVerticalMove();
		scene_enemy->InitEnemy();
		scene_enemy->UpdateEnemy();
		scene_enemy->AdditionMove();
		scene_enemy->EnemyAirCollision();
		scene_enemy->Drawcircle();
		scene_map->BackGround();
		scene_map->Draw();
		scene_map->TimeLimit();
		scene_map->BackGround();
	}
	else if (NowScene==Return_Title)
	{
		return true;
		scene_title->gpUpdateKey();
		scene_title->Update();
		scene_title->MakeSelectTriangle();
	
	}
	else if(NowScene==Clear)
	{
		scene_map->TimeLimit();
	}
	else if (NowScene == Return_Title)
	{
		title.Update();
		ExplanationText();
		title.TitleMusic();

	}
	
	//現在のシーンを返す　　
	return NowScene;
}
//上二つをまとめた関数
void SceneManager::ExplanationScene()
{

	DivideScene();
	ChangeScene();
	
}

//スタートテキスト
void SceneManager::ExplanationText()
{
	int x0 = 0;
	int x1 = 470;
	int x2 = 430;
	int y0 = 100;
	int y1 = 135;
	int y2 = 170;
	int y3 = 20;

	
	DrawString(x0, y0, "スペースキーでジャンプ\nESCキーで終了", 0xff0000);
	DrawString(x0, y1, "敵に60秒当たらず\n生き残ればゲームクリアだ!!",0xff0000);
	DrawString(x0, y2, "Zキーでスタート",0xff0000);
	DrawString(x1, x0, "素材提供者様", 0xfffff);
	DrawString(x2, y2, "    ぴぽや倉庫様\nArtificial Providence様\n       他一同",0xffffff);

	//ChangeFont("NomalFontHandle");
	DrawString(0, 100, "スペースキーでジャンプ\nESCキーで終了", 0xff0000);
	DrawString(0, 135, "敵に60秒当たらず\n生き残ればゲームクリアだ!!",0xff0000);
	DrawString(0, 170, "Zキーでスタート\n左上のライフが無くなるとゲームオーバーになるぞ!!",0xff0000);
	DrawString(470, 0, "素材提供者様", 0xfffff);
	DrawString(430, 20, "    ぴぽや倉庫様\nArtificial Providence様\n       他一同",0xffffff);


}

void SceneManager::Scene_ChangeKey()
{
	GetHitKeyStateAll(scene_key);
	for (int i = 0; i < 256; i++)
	{
		if (scene_key[i] != 0) {
		   scene_key[i]++;				//加算
		}
		else {						//押されていなければ
			scene_key[i] = 0;

		}
	}
}
