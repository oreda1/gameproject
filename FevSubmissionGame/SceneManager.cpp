#include "SceneManager.h"


SceneManager::SceneManager():
//シーン作成
base_manager(nullptr)
{
	title = new TitleScene;
	chara = new Character;
	enemy = new Enemy;
	optipn = new OptionScene;
	map = new Map;

}

SceneManager::~SceneManager()
{
	//メモリ解放
	if (base_manager)
	{
		delete base_manager;
		base_manager = nullptr;
	}
	

	
}

//シーンをそれぞれ判別する関数
bool SceneManager::DivideScene()
{
	Scene_ChangeKey();
	if (scene_key[KEY_INPUT_Z])
	{
		NowScene = Playing;
	}
	else if (scene_key[KEY_INPUT_RETURN])
	{
		NowScene = Title;
	}
	else if (scene_key[KEY_INPUT_O])
	{
		NowScene = Option;
	}
	
	return 0;
}

//NowSceneを判別し、それぞれのシーンにあわせた処理を行う
bool SceneManager::ChangeScene()
{ 
	return 0;
}
//上二つをまとめた関数
void SceneManager::ExplanationScene()
{
	ChangeScene();
	DivideScene();
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

	//base_manager->Draw();
}

void SceneManager::Init()
{
	base_manager->Init();
}

//キー入力
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


