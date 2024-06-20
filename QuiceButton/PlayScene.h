#pragma once
#include "DxLib.h"
#include "Player.h"

class PlayScene
{
public:
	PlayScene();
	~PlayScene();
	void Init();
	void BarkGround();
	void Text();
	void Button();
	void Clear();
	int Key();
	bool Check();
	void Floor();
	bool Start();

	int CheckKey();

	//true �Q�[����ʁ@false �X�^�[�g���
	bool SceneFlag=true;
private:
	char button[256];
	int key[256];
	typedef enum Push
	{
		A='A',
		B='B',
		X='X',
		Y='Y'
	}push;
	int number;
	char _number;

	int pushPoint;	
	
	int score,_score;
	//1�t���[�����ԁA�X�R�A,�~�X
	int frame_count,time_count,miss_count;

    
	


	bool number_check,_or;
	VERTEX3D ver[6];

	
};

