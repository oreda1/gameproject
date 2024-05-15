#pragma once
#include "DxLib.h"
#include "Player.h"

class Camera:Player
{  
public:
	Camera();
	void Init();
	void Look();
	void ViewpointShift();
	VECTOR pos;
	VECTOR lookpos;




	

};

