#pragma once
#include "DxLib.h"
class Character
{
public:
	Character(){};
	~Character(){};
	void Init(){};
	void Draw(){} ;
	void Update(){};
	void Collision(){};

	
	//キャラサイズ
	static const int Chara_Size = 64;

	//キャラクターハンドル

	int handle[77];
	int n_handle = LoadDivGraph("3_DF_Actor.png", 76, 12, 8, Chara_Size, Chara_Size,handle);
    
	//画面サイズ
	struct 
	{
		int Width;
		int Height;
		int Color;
	};


	//キャラクター位置
	VECTOR pos;
	//移動量,重力
	VECTOR velocity,gravity;
    //キャラチップ切り抜き座標
	VECTOR crop;

	//ポジションを返す
	VECTOR& Getpos() { return pos; };


};

