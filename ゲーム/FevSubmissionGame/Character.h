#pragma once
#include "Map.h"
#include "SceneManager.h"
#include "DxLib.h"
class Map;
class Enemy;
class Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move(Map& gamescene);
    void Update();
	void Collision(Enemy&cEnemy);
	void FallCollision();
	int gpUpdateKey();
	
	//�v���C���[�̏����ʒu
   //�L�����̍ŏ��̃|�W�V���� 
	int Player_posX = 0;
	int Player_posY = 300;
	
	int PlayerHandle=LoadGraph("Cockroach.png");


private:

	


  //�L�����ړ��X�s�[�h
	int CharaMoveSpeed=5;
	//�L�����W�����v�t���O
	bool JumpFlag;
	
	//�L�����̏����x
	int JumpInitialVelocity=10;
	//�L�����ɂ�����d�͏����̒l
	float Jumpgravity=2.5f;
	//�L�����̃W�����v�X�s�[�h
	int JumpSpeed = 50;
	//�W�����v1�b������̃t���[��
	int JumpFlame;
	//�L�������W�̕ۑ�
	int preservationY;

	//�L����1�}�X���̑傫��
	int PlayerChipSizeX=32;
	int PlayerChipSizeY=32;


	//�L�����؂蔲���T�C�Y
	int PlayerWidthX=32;
	int PlayerHeightY=32;






};



