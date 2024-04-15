#pragma once
#include "BaseScene.h"
#include <vector>
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

	VECTOR Player_pos;
	VECTOR crop;
	VECTOR velocity;

	
	
};

