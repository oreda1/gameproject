#pragma once
#include "DxLib.h"
namespace 
{
	constexpr int GameWidth = 768;//ゲーム画面のサイズ(横)
	constexpr int GameHeight = 480;//ゲーム画面のサイズ(縦)

	constexpr int PictureWidth = 96;//横のゲーム画面と縦のゲーム画面のサイズの値の最大公約数
	constexpr int PicrureHeight = 96;

	//マップのチップ数
	constexpr int mapX = GameWidth / PictureWidth;//8
	constexpr int mapY = GameHeight / PicrureHeight;//5

	//キャラクターの画像サイズ
	constexpr int PlayerChipX = 384;
	constexpr int PlayerChipY = 256;
	//キャラクター画像の最大公約数
	constexpr int PlayerChip = 128;
	//キャラクターチップ
	constexpr int PlayerX = PlayerChipX / PlayerChip;//3
	constexpr int PlayerY = PlayerChipY / PlayerChip;//2
	
	//マップ1マス分の大きさ
	constexpr int  MapChipSize=10;
	//キャラ1マス分の大きさ
	constexpr int PlayerChipSize = 12;



	//プレイヤー読み込みハンドル
	int PlayerHandle = LoadGraph("Cockroach.png");

    //マップ読み込みハンドル
	int MapHandle = LoadGraph("[A]Water3_pipo.png");

	//エネミー読み込みハンドル
	int EnemyHandle = LoadGraph("DevilLeech.png");


	struct CharaMove
	{
		//移動処理
		int moveX=0;
		int moveY=0;

		//ジャンプ処理
		int jumpX=0;
		int jumpY=0;

		//キャラにかかる重力処理の値

		float gravity=1.2f;
		
	};

	struct Triangle
	{
		//コマンド三角形を作る座標
		
		int x2 = 200;//2つの頂点x座標(上)
		int y2 = 290;//2つの頂点y座標(上)
		int x3 = 200;//2つの頂点x座標(下)
		int y3 =y2+40;//2つの頂点y座標(下)330
		int x1 = 240;//1つの頂点x座標
        int y1 = (y2+y3)/2;//1つの頂点y座標305
	}triangle;


	struct Title
	{
		int Key[256];
		int fsize, fwidh;

	}title;
	
	struct GameMoveKey
	{
		int gameKey[256];

	}gamekey;

	

	struct MenuElement_t {
		int x, y;			//座標格納用変数
		char name[256];//項目名格納用変数


	};
	MenuElement_t MenuElement[50]{
	 {250,100,"SUPER\n JUMPMAN BROTHERS"},
	 {250,300,"1 PLAYER GAME"},
	 {250,340,"2 PLAYER GAME"}

	};
	

	//マップチップ
	constexpr int MakeMap[mapY][mapX]
	{
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1}
	

	};
	constexpr int MakePlayer[PlayerChipY][PlayerChipX]
	{
		{1,1,1},
	    {1,1,1}


	};



}