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

	
	//キャラサイズ
	static const int Chara_Size = 64;

	//キャラクターハンドル
    int handle = LoadGraph("3_DF_Actor.png");

	//キャラクター位置
	VECTOR pos;
	//移動量
	VECTOR velocity;
    //キャラチップ切り抜き座標
	VECTOR crop;
};

