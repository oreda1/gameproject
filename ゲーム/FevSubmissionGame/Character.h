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
	
	//キャラクターの移動後のY
	int CharaY;

	//キャラクターの移動する前の座標
	int UpdateCharaY;


	//キャラにかかる重力処理の値
	int  Jumpgravity;

	//キャラ1マス分の大きさ
	 int PlayerChipSizeX=32;
	 int PlayerChipSizeY=32;


	//キャラ切り抜きサイズ
	int PlayerWidthX=32;
	int PlayerHeightY=32;





};



