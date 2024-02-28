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

	void Draw();
	void Move(Map& gamescene);
	void FallCollision();
	void Effect();
	int gpUpdateKey();
	
	//�v���C���[�̏����ʒu
   //�L�����̍ŏ��̃|�W�V���� 
	int Player_posX = 300;
	int Player_posY = 400;
	
	
int EffectHandle = LoadGraph("pipo-btleffect088c.png");

private:

	//�v���C���[
	int PlayerHandle = LoadGraph("Cockroach.png");
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
 
	//�L�������W�̕ۑ�
	int exceedY;
	int not_exceedY;

	//�L����1�}�X���̑傫��
	int PlayerChipSizeX=64;
	int PlayerChipSizeY=64;


	//�L�����؂蔲���T�C�Y
	int PlayerWidthX=32;
	int PlayerHeightY=32;

};



