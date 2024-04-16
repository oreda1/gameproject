#pragma once
#include "Player.h"
class Enemy : public Player
{
public:
	void Init();
	void Draw();
	void Collision();

	VECTOR Enemy_pos[20];
};

