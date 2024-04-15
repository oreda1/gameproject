#pragma once
#include "BaseScene.h"
#include "DxLib.h"
class Camera
{
public:
   Camera();
	~Camera();

	void Watch();

	const VECTOR& GetPos() const { return pos; }
	const VECTOR& GetDir() const { return dir; }
	VECTOR pos;

};

