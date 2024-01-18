#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"

/*メイン*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib初期化処理(設定込み)*/
	//SetGraphMode(GameWidth, GameHeight, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);//裏画面書き込み

	/*ゲームオブジェクトの作成*/
	TitleScene title;
	Map map;
	Character character;
	Enemy enemy;

	/*ゲームループ*/
	bool sceneFlag = true;//true:タイトルシーン,false:ゲームシーン
	while (TRUE)
	{
		/*画面の初期化*/
		ClearDrawScreen();

		/*ゲーム処理*/
		if (sceneFlag)
		{
			
			sceneFlag = title.Update();
		}
		else
		{
			map.BackGround();
			map.Update();
			character.Draw();
			character.Move(map);
			map.Draw();
			enemy.Draw();
			enemy.EnemyMove();
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

