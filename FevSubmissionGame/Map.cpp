#include "Map.h"
#include "BaseNumber.h"
#include "Dxlib.h"
#include "SceneManager.h"
#include "Enemy.h"

SceneManager m_scene;
Enemy m_enemy;

void Map::Draw()
{
	
	//ƒQ[ƒ€ƒV[ƒ“‚Ìˆ—
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

bool Map::TimeLimit()
{
	
	time_count+=0.02;
    
	if (time_count>=60)
	{
		
		ClearDrawScreen();
		InitGraph();
	    m_enemy.DectionCircle;
		DrawExtendFormatString(100,100,5, 5, 0xffffff, "Game Clear");
		DrawFormatString(200, 200, 0xffffff, "Thank You For Playing");

	}

	DrawFormatString(550, 0, 0x0000ff, "%f", time_count);
	
	
	return 0;
}

void Map::BackGround()
{
	DrawGraph(0,0,LoadGraph("pipo-battlebg009.jpg"),true);
}
