#pragma once
class GameScene
{
public:
	void Draw();
	void Update();
	void Init();
	
	//�n�ʕ`��ʒu
	int GroundX=0;
	int GroundY=400;

	
private:
	

	//�؂蔲���ꏊ
	int CropX=0;
	int CropY=128;

	//�}�b�v�\���T�C�Y
	int MapIndicationX = 256;
	int MapIndicationY = 160;




};

