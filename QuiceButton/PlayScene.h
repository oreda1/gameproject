#pragma once
#include "DxLib.h"
#include "Player.h"

class PlayScene
{
public:
	PlayScene();
	void Init();
	void BarkGround();
	void Text();
	void Button();
	void Clear();
	int Key();
	bool Check();
	void Floor();

	void CheckKey();

	//true ゲーム画面　false スタート画面
	bool SceneFlag=true;
private:
	char button[256];
	int key[256];
	typedef enum Push
	{
		A,
		B,
		X,
		Y
	}push;
	int number;
	int _number;
	int score_count;
	int pushPoint;
	int frameCount;
	bool number_check,_or;
	VERTEX3D ver[6];

	
};

