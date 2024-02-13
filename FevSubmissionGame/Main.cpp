#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "OptionScene.h"
#include "SceneManager.h"
#include "GameClearScene.h"
#include <memory>


/*メイン*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib初期化処理(設定込み)*/
	//SetGraphMode(GameWidth, GameHeight, 32);
	ChangeWindowMode(true);
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
	title.TitleMusic();
	bool sceneFlag = true;//true:タイトルシーン,false:ゲームシーン
	while (TRUE)
	{
		/*画面の初期化*/
		ClearDrawScreen();
		/*ゲーム処理*/
		if(sceneFlag)
		{
			sceneFlag = title.Update();
		    scene.ExplanationScene();
			scene.DecisionScene();
			
		}
		else if (scene.NowScene==scene.Playing)
		{	
			map.BackGround();
			map.Draw();
			map.TimeLimit();
			character.Effect();
			character.Draw();
			character.Move(map);
			enemy.Draw();
			enemy.InitEnemy();	
			enemy.EnemyVerticalMove();
			enemy.EnemyMove();	
			enemy.Drawcircle();
			enemy.KillerRabbit(character);
			enemy.EnemyAirCollision();
			enemy.UpdateEnemy();
			enemy.AdditionMove();
			clear.Draw();

		
		}
		else if(scene.NowScene==scene.S_Option)
		{
			
			option.DrawFrame();
			option.OptionText(title);
		}
		
		/*描画の確定*/
		ScreenFlip();

		/*ゲームループ終了処理*/
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0) { break; }
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
		
	}

	/*Dxlib終了処理*/
	DxLib::DxLib_End();
	return 0;
}

