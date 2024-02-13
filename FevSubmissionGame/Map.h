#pragma once
class Map
{
public:
	void Draw();
	void Update();
	void Init();

  bool TimeLimit();

	void BackGround();
	
	//地面描画位置
	int GroundX = 300;//320
	int GroundY=400;//540


	float time_count=0.0;

	
private:
	
	//切り抜く場所
	int CropX=0;
	int CropY=128;

	//マップ表示サイズ
	int MapIndicationX =32;
	int MapIndicationY = 160;




};

