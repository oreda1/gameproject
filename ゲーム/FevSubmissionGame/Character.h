#pragma once
#include "GameScene.h"
class GameScene;
class  Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move(GameScene& gamescene);
    void Update();
	void Collision();
	void FallCollision();
	int gpUpdateKey();

	
private:
	int PlayerHandle;
  //�L�����ړ��X�s�[�h
	int CharaMoveSpeed=5;
	//�L�����W�����v�t���O
	bool JumpFlag;
	//�L�������W�̕ۑ�
	int preservationY;

	//�L�����̏����x
	int JumpInitialVelocity=1;
	//�L�����ɂ�����d�͏����̒l
	float Jumpgravity=1.2f;
	//�L�����̃W�����v�X�s�[�h
	int JumpSpeed = 60;

	//�L����1�}�X���̑傫��
	int PlayerChipSizeX=32;
	int PlayerChipSizeY=32;


	//�L�����؂蔲���T�C�Y
	int PlayerWidthX=32;
	int PlayerHeightY=32;


	GameScene* m_gamescene;




};



