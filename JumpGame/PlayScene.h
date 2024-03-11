#pragma once
#include "BaseScene.h"
#include "DxLib.h"
class PlayScene:public BaseScene
{
public:
	virtual void Init();
	virtual void Update();
    virtual void Draw();
	virtual void BackGround();

};

