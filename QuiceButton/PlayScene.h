#pragma once
#include "DxLib.h"
#include "Player.h"

class PlayScene
{
public:
	PlayScene();

	void BarkGround();
	void Text();
	void Button();
	void Clear();
	int Key();
	bool Check();
	void Floor();
	//true �Q�[����ʁ@false �X�^�[�g���
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
	};
	Push push;
	int number;
	int*_number;
	int score_count;
	int count;
	VERTEX3D ver[6];

	
};

