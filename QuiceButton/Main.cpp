#include "Camera.h"
#include "PlayScene.h"



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	Player* player = new Player;
	Camera* camera = new Camera;
	PlayScene* play = new PlayScene;







	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	
	//初期化
	player->Load();
	player->Init();
	play->Init();

	//スタートシーン
    play->Start();
	

	SetDrawScreen(DX_SCREEN_BACK);
	// ゲームループ(ゲームシーン)
	while (play->SceneFlag)
	{
		
		// このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();
		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		// ゲームの処理
		play->BarkGround();
		play->Disturbance();
		camera->Look(*player);
		camera->ViewpointShift();
		player->Draw();
		player->Update();
		play->CheckKey();
		play->Key();
		play->Text();
		play->Check();
		play->Button();
		play->Clear();
		// 画面が切り替わるのを待つ
		ScreenFlip();


		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}


	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}