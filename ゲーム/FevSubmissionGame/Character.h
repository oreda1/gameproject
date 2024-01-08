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
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //キャラ移動スピード
	int CharaMoveSpeed=2;
	//キャラジャンプフラグ
	bool JumpFlag;
	
	//キャラクターの移動後のY
	int CharaY;

	//キャラクターの移動する前の座標
	int UpdateCharaY;


	//キャラにかかる重力処理の値
	int  Jumpgravity;

	//キャラクターベクトル
	int CharaVect;

};



