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

	VECTOR TextPos = VGet(0, 300, 2);

	void Disturbance();

	bool start;


	//true ゲーム画面　false スタート画面
	bool SceneFlag;

protected:
	
	int number;
	char _number;
	//1フレーム時間、スコア,ミス
	int frame_count, time_count, miss_count;
	typedef enum Push
	{
		A = 'A',
		B = 'B',
		X = 'X',
		Y = 'Y'
	}push;
	int score;
private:
	
	char button[256];
	int key[256];




	int pushPoint;




	PlayScene* play;


	bool number_check, _or;
	VERTEX3D ver[6];
	MATRIX matrix[5][5];

	RECTDATA rect;
	VECTOR vect;



};

