#pragma once
#include "DxLib.h"
#include <math.h>
#include "Player.h"	

class Player;
class Camera
{  
public:
	Camera();
	void Init();
	void Look(Player&player);
	void ViewpointShift();

private:
	VECTOR pos,lookpos;
	Player* _player;




	

};

