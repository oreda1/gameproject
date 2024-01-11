#pragma once

class  Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move();
    void Update();
	void Collision();
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //�L�����ړ��X�s�[�h
	int CharaMoveSpeed=5;
	//�L�����W�����v�t���O
	bool JumpFlag;
	
	//�L�����N�^�[�̈ړ����Y
	int CharaY;

	//�L�����N�^�[�̈ړ�����O�̍��W
	int UpdateCharaY;


	//�L�����ɂ�����d�͏����̒l
	int  Jumpgravity;

	//�L����1�}�X���̑傫��
	 int PlayerChipSizeX=32;
	 int PlayerChipSizeY=32;


	//�L�����؂蔲���T�C�Y
	int PlayerWidthX=32;
	int PlayerHeightY=32;





};



