#include "Map.h"
#include "BaseNumber.h"
#include "Dxlib.h"


void Map::Draw()
{
	
	//�Q�[���V�[���̏���
	int MapHandle = LoadGraph("[A]Water3_Cave1_pipo.png");

	for (int x = 0; x< SumMapX; x++)
	{
		for (int y = 0; y < SumMapY; y++)
		{
		
                
			if (MakeMap[y][x] == 1)
			{				

			DrawRectGraph(GroundX, GroundY, CropX, CropY, MapIndicationX, MapIndicationY, MapHandle, true);

			}

			
		}


	}

}


void Map::Update()
{
}



void Map::Init()
{

}

void Map::TimeLimit()
{
	time_count+=0.02;
	if (time_count>=60)
	{
		DrawExtendFormatString(300, 240, 2, 2, 0xffffff, "Game Clear");
	}

	DrawFormatString(550, 0, 0x0000ff, "%f", time_count);
}

void Map::BackGround()
{
	DrawGraph(0,0,LoadGraph("pipo-battlebg009.jpg"),true);
}