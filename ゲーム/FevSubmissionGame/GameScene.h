#pragma once
class GameScene
{
public:
	void Draw();
	void Update();
	void Init();


private:
	//�n�ʕ`��ʒu
	int GroundX=0;
	int GroundY=400;

	//�؂蔲���ꏊ
	int CropX=0;
	int CropY=128;

	//�}�b�v�\���T�C�Y
	int MapIndicationX = 340;
	int MapIndicationY = 32;




};

