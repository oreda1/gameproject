#pragma once
#include "DxLib.h"
class Character
{
public:
	Character(){};
	~Character(){};
	void Init(){};
	void Draw(){} ;
	void Update(){};

	
	//�L�����T�C�Y
	static const int Chara_Size = 64;

	//�L�����N�^�[�n���h��
    int handle = LoadGraph("3_DF_Actor.png");

	//�L�����N�^�[�ʒu
	VECTOR pos;
	//�ړ���
	VECTOR velocity;
    //�L�����`�b�v�؂蔲�����W
	VECTOR crop;
};

