#pragma once
#include "BaseScene.h"
#include "DxLib.h"
class PlayScene:public BaseScene
{
public:
	virtual void Init();
	virtual void Update();
    virtual void Draw();
	void BackGround();

	//�w�i�摜�ʒu
	VECTOR BackPos;


	void Timer();

	float time_count=0;
	float time=0.02;

	int turn=0;
};

