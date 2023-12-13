#pragma once
#include "DxLib.h"
namespace 
{
	constexpr int GameWidth = 768;//�Q�[����ʂ̃T�C�Y(��)
	constexpr int GameHeight = 480;//�Q�[����ʂ̃T�C�Y(�c)

	constexpr int PictureWidth = 96;//���̃Q�[����ʂƏc�̃Q�[����ʂ̃T�C�Y�̒l�̍ő����
	constexpr int PicrureHeight = 96;

	//�}�b�v�̃`�b�v��
	constexpr int mapX = GameWidth / PictureWidth;//8
	constexpr int mapY = GameHeight / PicrureHeight;//5

	//�L�����N�^�[�̉摜�T�C�Y
	constexpr int PlayerChipX = 384;
	constexpr int PlayerChipY = 256;
	//�L�����N�^�[�摜�̍ő����
	constexpr int PlayerChip = 128;
	//�L�����N�^�[�`�b�v
	constexpr int PlayerX = PlayerChipX / PlayerChip;//3
	constexpr int PlayerY = PlayerChipY / PlayerChip;//2
	
	//�}�b�v1�}�X���̑傫��
	constexpr int  MapChipSize=10;
	//�L����1�}�X���̑傫��
	constexpr int PlayerChipSize = 12;



	//�v���C���[�ǂݍ��݃n���h��
	int PlayerHandle = LoadGraph("Cockroach.png");

    //�}�b�v�ǂݍ��݃n���h��
	int MapHandle = LoadGraph("[A]Water3_pipo.png");

	//�G�l�~�[�ǂݍ��݃n���h��
	int EnemyHandle = LoadGraph("DevilLeech.png");


	struct CharaMove
	{
		//�ړ�����
		int moveX=0;
		int moveY=0;

		//�W�����v����
		int jumpX=0;
		int jumpY=0;

		//�L�����ɂ�����d�͏����̒l

		float gravity=1.2f;
		
	};

	struct Triangle
	{
		//�R�}���h�O�p�`�������W
		
		int x2 = 200;//2�̒��_x���W(��)
		int y2 = 290;//2�̒��_y���W(��)
		int x3 = 200;//2�̒��_x���W(��)
		int y3 =y2+40;//2�̒��_y���W(��)330
		int x1 = 240;//1�̒��_x���W
        int y1 = (y2+y3)/2;//1�̒��_y���W305
	}triangle;


	struct Title
	{
		int Key[256];
		int fsize, fwidh;

	}title;
	
	struct GameMoveKey
	{
		int gameKey[256];

	}gamekey;

	

	struct MenuElement_t {
		int x, y;			//���W�i�[�p�ϐ�
		char name[256];//���ږ��i�[�p�ϐ�


	};
	MenuElement_t MenuElement[50]{
	 {250,100,"SUPER\n JUMPMAN BROTHERS"},
	 {250,300,"1 PLAYER GAME"},
	 {250,340,"2 PLAYER GAME"}

	};
	

	//�}�b�v�`�b�v
	constexpr int MakeMap[mapY][mapX]
	{
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1}
	

	};
	constexpr int MakePlayer[PlayerChipY][PlayerChipX]
	{
		{1,1,1},
	    {1,1,1}


	};



}