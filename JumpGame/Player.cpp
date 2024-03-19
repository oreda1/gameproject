#include "Player.h"

namespace{

	//画面サイズ
	constexpr int ScreenX = 640;
	constexpr int ScreenY = 480;
	//チップサイズ
	constexpr int Chara_ChipX = 768;
	constexpr int Chara_ChipY = 512;

    //キャラチップ 8*8=横,12 縦,8  
	int ChipNum = 64;
	//画像サイズからキャラチップ一枚あたりのサイズ
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
