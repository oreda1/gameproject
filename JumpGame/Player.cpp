#include "Player.h"

namespace{

	//��ʃT�C�Y
	constexpr int ScreenX = 640;
	constexpr int ScreenY = 480;
	//�`�b�v�T�C�Y
	constexpr int Chara_ChipX = 768;
	constexpr int Chara_ChipY = 512;

    //�L�����`�b�v 8*8=��,12 �c,8  
	int ChipNum = 64;
	//�摜�T�C�Y����L�����`�b�v�ꖇ������̃T�C�Y
	constexpr int ChipX = 12;
	constexpr int ChipY = 8;
	
}

int Player_Chip[ChipY][ChipX]
{
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0}
	
};


Player::Player() 
{
	
}

Player::~Player()
{
}

void Player::Init()
{
	
	Player_pos = VGet(0, 0, 0);
	
}


//64*12,64*8
void Player::Draw()
{

	for (int y = 0; y < ChipY; y++)
	{
		for (int x = 0; x < ChipX; x++)
		{
			DrawGraph(Player_pos.x, Player_pos.y, PlayerHandle, true);
		}

	}
	
}

void Player::Update()
{
	
}
