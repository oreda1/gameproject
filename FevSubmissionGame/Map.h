#pragma once
class Map
{
public:
	void Draw();
	void TimeUpdate();
	void Init();

  bool TimeLimit();

	void BackGround();
	
	//�n�ʕ`��ʒu
	int GroundX = 300;//320
	int GroundY=400;//540
	

	float timescore;
	float time;
	float timelimit=60.0;

<<<<<<< HEAD
<<<<<<< HEAD
	float time_count=0.0;
	float time = 0.02;
=======
	float time_count;
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
=======
	float time_count;
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90

	
private:
	
	//�؂蔲���ꏊ
	int CropX=0;
	int CropY=128;

	//�}�b�v�\���T�C�Y
	int MapIndicationX =32;
	int MapIndicationY = 160;




};

