#pragma once

class  Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move();
    void Update();
	void Collision();
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //キャラ移動スピード
	int CharaMoveSpeed=5;
	//キャラジャンプフラグ
	bool JumpFlag;
	
	//キャラの初速度
	int JumpInitialVelocity=0;
	//キャラにかかる重力処理の値
	float Jumpgravity=0.5f;
	//キャラのジャンプスピード
	int JumpSpeed = 1;

	//キャラ1マス分の大きさ
	 int PlayerChipSizeX=32;
	 int PlayerChipSizeY=32;


	//キャラ切り抜きサイズ
	int PlayerWidthX=32;
	int PlayerHeightY=32;





};



