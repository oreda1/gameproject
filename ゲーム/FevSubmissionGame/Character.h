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
	int CharaMoveSpeed=10;
	//�L�����W�����v�t���O
	bool JumpFlag;
	
	//�L�����N�^�[�̈ړ����Y
	int CharaY;

	//�L�����N�^�[�̈ړ�����O�̍��W
	int UpdateCharaY;


	//�L�����ɂ�����d�͏����̒l
	int  Jumpgravity;

	//�L�����N�^�[�x�N�g��
	int CharaVect;



};



