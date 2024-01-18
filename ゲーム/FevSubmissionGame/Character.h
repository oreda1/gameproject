#pragma once
#include "Map.h"
class Map;
class  Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move(Map& gamescene);
    void Update();
	void Collision();
	void FallCollision();
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //キャラ移動スピード
	int CharaMoveSpeed=5;
	//キャラジャンプフラグ
	bool JumpFlag;
	
	//キャラの初速度
	int JumpInitialVelocity=10;
	//キャラにかかる重力処理の値
	float Jumpgravity=1.2f;
	//キャラのジャンプスピード
	int JumpSpeed = 30;
	//ジャンプ1秒当たりのフレーム
	int JumpFlame;
	//キャラ座標の保存
	int preservationY;

	//キャラ1マス分の大きさ
	int PlayerChipSizeX=32;
	int PlayerChipSizeY=32;


	//キャラ切り抜きサイズ
	int PlayerWidthX=32;
	int PlayerHeightY=32;


	Map* m_map;




};



