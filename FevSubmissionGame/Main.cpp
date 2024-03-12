#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "OptionScene.h"
#include "SceneManager.h"
#include "GameClearScene.h"



/*メイン*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib初期化処理(設定込み)*/
	SetWindowText("UNNAMED");
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);//裏画面書き込み

	/*ゲームオブジェクトの作成*/
	TitleScene title;
	Map map;
	Character character;
	Enemy enemy;
	OptionScene option;
	SceneManager scene;
	GameClearScene clear;
	
	/*ゲームループ*/
	bool sceneFlag = true;//true:タイトルシーン,false:ゲームシーン
	//ゲームシーン繰り返し処理
	while (true)
	{
		
		/*画面の初期化*/
		ClearDrawScreen();
		scene.DivideScene();
		/*ゲーム処理*/
		if (sceneFlag)
		{
			sceneFlag=title.Update();
			title.TitleMusic(); 
			scene.ExplanationText(); 

		}
		//ゲーム実行画面
		else if (scene.NowScene==scene.Playing)
		{
			map.Draw();
			map.BackGround();
			map.TimeLimit();
			map.TimeUpdate();
			character.Draw();
			character.FallCollision();
			character.Move(map);
			enemy.Drawcircle();
			enemy.Draw();
			enemy.InitEnemy();
			enemy.UpdateEnemy();
			enemy.AdditionMove();
			enemy.EnemyMove();
			enemy.EnemyAirCollision();
		}
	
		
		/*描画の確定*/
		ScreenFlip();

		/*ゲームループ終了処理*/
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0) { return true; }
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { return true; }

	 
	}
		
	/*Dxlib終了処理*/
	DxLib::DxLib_End();
	return 0;
}
