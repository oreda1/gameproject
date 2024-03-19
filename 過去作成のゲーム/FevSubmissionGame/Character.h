#pragma once
#include "Map.h"
#include "SceneManager.h"
#include "DxLib.h"
class Map;
class Enemy;
class Character
{
public:
	 Character();
	~Character();

	void Draw();
	void Move(Map& gamescene);
	void FallCollision();
	void Effect();
	int gpUpdateKey();
	
	//プレイヤーの初期位置
   //キャラの最初のポジション 
	int Player_posX = 300;
	int Player_posY = 400;
	
	
int EffectHandle = LoadGraph("pipo-btleffect088c.png");

private:

	//プレイヤー
	int PlayerHandle = LoadGraph("Cockroach.png");
  //キャラ移動スピード
	int CharaMoveSpeed=5;
	//キャラジャンプフラグ
	bool JumpFlag;
	
	//キャラの初速度
	int JumpInitialVelocity=10;
	//キャラにかかる重力処理の値
	float Jumpgravity=2.5f;
	//キャラのジャンプスピード
	int JumpSpeed = 50;
 
	//キャラ座標の保存
	int exceedY;
	int not_exceedY;

	//キャラ1マス分の大きさ
	int PlayerChipSizeX=64;
	int PlayerChipSizeY=64;


	//キャラ切り抜きサイズ
	int PlayerWidthX=32;
	int PlayerHeightY=32;

};



