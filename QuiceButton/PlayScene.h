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
	
	VECTOR TextPos=VGet(400,200,2);

	RECTDATA Disturbance();

	


	//true ゲーム画面　false スタート画面
	bool SceneFlag;
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
	//1フレーム時間、スコア,ミス
	int frame_count,time_count,miss_count;

	PlayScene* play;

	bool start;
	bool number_check,_or;
	VERTEX3D ver[6];

	RECTDATA rect;
	VECTOR vect;


	
};

