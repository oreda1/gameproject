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
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //�L�����ړ��X�s�[�h
	int CharaMoveSpeed=2;

	//�L�����N�^�[�x�N�g��
	int CharaVect;

};



