#pragma once
#include "DxLib.h"
#include "Player.h"

class Camera:Player
{  
public:
	Camera();
	void Init();
	void Look(Player&player);
	void ViewpointShift();


	VECTOR pos;
	VECTOR lookpos;




	

};

