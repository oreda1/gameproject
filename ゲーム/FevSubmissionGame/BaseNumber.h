#pragma once
#include "DxLib.h"

namespace
{
	constexpr int GameWidth = 640;//ゲーム画面のサイズ(横)
	constexpr int GameHeight = 480;//ゲーム画面のサイズ(縦)

	constexpr int PictureWidth = 160;//横のゲーム画面と縦のゲーム画面のサイズの値の最大公約数
	constexpr int PicrureHeight = 160;

	//マップのチップの合計数
	constexpr int SumMapX = GameWidth / PictureWidth;//16
	constexpr int SumMapY = GameHeight / PicrureHeight;//12

	//マップ1マス分の大きさ
	constexpr int  MapChipSize = 10;
	//マップの座標
	/*int MapPosX= (MapDate % SumMapX) * GameWidth;
     int MapPosY= (MapDate / SumMapY) * GameHeight;
	 int MapDate =MakeMap[SumMapY][SumMapX];*/


	//キャラクターの画像サイズ
	constexpr int PlayerChipX = 384;
	constexpr int PlayerChipY = 256;
	//キャラ1マス分の大きさ
	constexpr int PlayerChipSizeX = 16;
	constexpr int PlayerChipSizeY = 32;
	
	//キャラクターチップ1マスあたりの大きさ
	constexpr int PlayerPerChipX=PlayerChipX/PlayerChipSizeX;
	constexpr int PlayerPerChipY=PlayerChipY/PlayerChipSizeY;
	

	
	
	
    //プレイヤーの初期位置
	//キャラの最初のポジション
	int start_posX=200;
	int start_posY = 200;

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
	 {250,100,"SUPER\n JUMPMAN BROTHERS"},
	 {250,300,"1 PLAYER GAME"},
	 {250,340,"2 PLAYER GAME"}

	};
	

	//マップチップ
	constexpr int MakeMap[SumMapY][SumMapX]
	{
		
	

	};
	constexpr int MakePlayer[PlayerPerChipY][PlayerPerChipX]
	{
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}

	};
}