#pragma once
#include "Character.h"
class Player :public Character
{
public:
	void Init();
	void Draw();
	void Update();
	void Collision();

    int prev_y,temp_y;
	bool Jumpflag;

};

