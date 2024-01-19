﻿#pragma once
#include "DxLib.h"
namespace{

	constexpr int GameWidth = 640;//ゲーム画面のサイズ(横)
	constexpr int GameHeight = 480;//ゲーム画面のサイズ(縦)

	//マップ　縦と横
	constexpr int MapWidth = 40;//256
	constexpr int MapHeight = 40;//160

	constexpr int MapPer = 32;//32

	//マップのチップの合計数
	constexpr int SumMapX = GameWidth/MapHeight;//4
	constexpr int SumMapY = GameHeight / MapHeight;//3

	constexpr int MakeMap[SumMapY][SumMapX]
	{

	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	

	//マップ1マス分の大きさ
	constexpr int  MapChipSize = 10;

	 

	//384:256=12:8=3:2
	// 384:12= 96:3=32:1
	// 256:8=32:1
	//キャラクターの画像サイズ
	constexpr int PlayerChipX = 384;
	constexpr int PlayerChipY = 256;
	
	
	//キャラクターチップ1マスあたりの大きさ
	constexpr int PlayerPerChipX=PlayerChipX/32;
	constexpr int PlayerPerChipY=PlayerChipY/32;
	

	
	
	
    //プレイヤーの初期位置
	//キャラの最初のポジション 
	int Player_posX=0;
	int Player_posY=300;

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



	struct TitleP
	{
		int Key[256];
		int fsize, fwidh;

	}titleP;
	
	struct GameMoveKey
	{
		int gameKey[256];

	}gamekey;

	

	struct MenuElement_t {
		int x, y;			//座標格納用変数
		char name[256];//項目名格納用変数


	};

	MenuElement_t MenuElement[50]{

	{250, 100, "SUPER\n JUMPMAN BROTHERS"},
	 {250,300,"1 PLAYER GAME"},
	 {250,340,"2 PLAYER GAME"},
	 {250,380,"OPTION"},
	 {0,0,"ＭＡ〇ＩＯ\n００００００"},
	 {400,0,"ＷＯＲＬＤ"},
	 {420,20,"１ー１"}

	};

	
	


	constexpr int MakePlayer[PlayerPerChipY][PlayerPerChipX]
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0}

	

	};


	 constexpr int EnemyTextureX = 384;
     constexpr int EnemyTextureY = 256;

	constexpr int EnemyPerChraSize = 32;


	constexpr int EnemyChipX = EnemyTextureX / EnemyPerChraSize;
    constexpr int EnemyChipY = EnemyTextureY / EnemyPerChraSize;

  
	int MakeEnemy[EnemyChipY][EnemyChipX]
	{
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,0}



	};

	

	
}