#include "Player.h"

namespace{

	//画面サイズ
	constexpr int ScreenX = 640;
	constexpr int ScreenY = 480;
	//画像サイズからキャラチップ一枚あたりのサイズ
	constexpr int ChipX = 12;
	constexpr int ChipY = 8;
	//キャラチップ 8*8
	int ChipNum = 64;
}

int Player_Chip[ChipY][ChipX]
{
	{1,0,0,0,0,0,0,0,0,0,0,0},
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
	for (int i = 0; i < ChipY; i++)
	{
		for (int i = 0; i < ChipX; i++)
		{
			DrawGraph(Player_pos.x, Player_pos.y, PlayerHandle, false);
		}

	}
	
}

void Player::Update()
{
	
}
