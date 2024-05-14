#pragma once
#include "DxLib.h"
#include "PlayScene.h"

class Player
{
public:
	Player();

	void Init();
	void Draw();
	void Update();
	void Delete();

private:
  
	VECTOR pos;
   int ModelHandle;
   VERTEX3D ver[6];

};

