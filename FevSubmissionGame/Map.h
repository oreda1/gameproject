#pragma once
class Map
{
public:
	void Draw();
	void TimeUpdate();
	void Init();

  bool TimeLimit();

	void BackGround();
	
	//地面描画位置
	int GroundX = 300;//320
	int GroundY=400;//540
	

	float timescore;
	float time;
	float timelimit=60.0;

	float time_count;

	
private:
	
	//切り抜く場所
	int CropX=0;
	int CropY=128;

	//マップ表示サイズ
	int MapIndicationX =32;
	int MapIndicationY = 160;




};

