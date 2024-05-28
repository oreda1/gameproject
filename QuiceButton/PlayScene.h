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
	bool SceneFlag=true;
private:
	char button[256];
	int key[256];
	typedef enum Push
	{
		one,
		two,
		a,
		b,
		tab,
		click
	};
	Push push;

	int score_count;
	int count;
	VERTEX3D ver[6];

	
};

