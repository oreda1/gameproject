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
private:
	char button[256];
	int score_count; 
	int count;
	VERTEX3D ver[6];

	
};

