#pragma once
#include "DxLib.h"
#include "PlayScene.h"

class Player
{
public:
	Player();

	void Init();
	void Load();
	void Draw();
	void Update();
	void Delete();

	VECTOR& GetPlayerPos(){ return pos;}


private:
  
   VECTOR pos;
   int ModelHandle;
   VERTEX3D ver[6];

};

