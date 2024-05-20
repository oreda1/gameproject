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
	int button_count; 
	int count;

	
};

