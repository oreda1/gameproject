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
	void Collision(){};

	
	//�L�����T�C�Y
	static const int Chara_Size = 64;

	//�L�����N�^�[�n���h��

	int handle[77];
	int n_handle = LoadDivGraph("3_DF_Actor.png", 76, 12, 8, Chara_Size, Chara_Size,handle);

	//�L�����N�^�[�ʒu
	VECTOR pos;
	//�ړ���,�d��
	VECTOR velocity,gravity;
    //�L�����`�b�v�؂蔲�����W
	VECTOR crop;
};

