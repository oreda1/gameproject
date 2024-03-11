#pragma once
#include "BaseScene.h"
#include "DxLib.h"
class Player
{
public:
	Player();
	~Player();


	void Init();
	void Draw();
	void Update();

	

	int PlayerHandle = LoadGraph("3_DF_Actor.png");

	VECTOR Player_pos=VGet(0,0,0);

	
	
};

