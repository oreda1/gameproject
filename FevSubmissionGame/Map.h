#pragma once
class Map
{
public:
	void Draw();
	void Update();
	void Init();

  bool TimeLimit();

	void BackGround();
	
	//�n�ʕ`��ʒu
	int GroundX = 300;//320
	int GroundY=400;//540


	float time_count=0.0;

	
private:
	
	//�؂蔲���ꏊ
	int CropX=0;
	int CropY=128;

	//�}�b�v�\���T�C�Y
	int MapIndicationX =32;
	int MapIndicationY = 160;




};

