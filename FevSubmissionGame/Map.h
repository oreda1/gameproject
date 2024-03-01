#pragma once
#include "SceneBase.h"
class Map:public SceneBase
{
public:
	Map();
	virtual~Map();
	virtual void Draw();

	void TimeUpdate();
	virtual void Init();

	bool TimeLimit();

	void BackGround();

	virtual void End();

	virtual SceneBase*Update();

	//地面描画位置
	int GroundX = 300;//320
	int GroundY = 400;//540


	float timescore;
	float timelimit = 60.0;


	float time_count = 0.0;
	float time = 0.02;


private:

	//切り抜く場所
	int CropX = 0;
	int CropY = 128;

	//マップ表示サイズ
	int MapIndicationX = 32;
	int MapIndicationY = 160;




};

