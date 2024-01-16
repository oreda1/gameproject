#pragma once
class GameScene
{
public:
	void Draw();
	void Update();
	void Init();
	
	//地面描画位置
	int GroundX=0;
	int GroundY=400;

	
private:
	

	//切り抜く場所
	int CropX=0;
	int CropY=128;

	//マップ表示サイズ
	int MapIndicationX = 256;
	int MapIndicationY = 160;




};

