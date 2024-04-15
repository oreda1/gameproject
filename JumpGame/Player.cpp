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




Player::Player() 
{
	
}

Player::~Player()
{
}

void Player::Init()
{
	
	Player_pos = VGet(200, 300, 0);
	crop = VGet(0, 128, 0);
	velocity = VGet(0, 100, 0);
	
}

//64*12,64*8
void Player::Draw()
{
	DrawRectGraph(Player_pos.x, Player_pos.y, crop.x , crop.y, ChipNum, ChipNum, PlayerHandle, true);
	

}

void Player::Update()
{
	
	
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		Player_pos = VSub(Player_pos, velocity);
		
	}
	
	
	
}
