#pragma once
#include "DxLib.h"
#include "PlayScene.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Load();
	void Draw();
	void Update();
	VECTOR& GetPlayerPos() { return pos; }


private:
	VECTOR pos;
	int ModelHandle[3];


};



