#include "Map.h"
#include "BaseNumber.h"
#include "Dxlib.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "GameClearScene.h"

SceneManager m_scene;
Enemy m_enemy;
GameClearScene map_clear;

void Map::Draw()
{
	
	//ゲームシーンの処理
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


void Map::TimeUpdate()
{
	time_count += 0.02;
	DrawExtendFormatString(220, 0,3,3, 0x0000ff, "%f", time_count);

}



void Map::Init()
{

}

bool Map::TimeLimit()
{
	m_scene.GameClear = false;
	
	if (time_count >= 60)
	{
		m_scene.GameClear = true;
		ClearDrawScreen();
		m_enemy.enemyX = 0;
		m_enemy.enemyY = 0;

		m_enemy.RabbitX = 0;
		m_enemy.RabbitY = 0;

	    
		DrawExtendFormatString(100,100,5, 5, 0xffffff, "Game Clear");
		DrawFormatString(200, 200, 0xffffff, "Thank You For Playing\nPlase Put ESC");

     
	}
	

	 return true;
	
}

void Map::BackGround()
{
	DrawGraph(0,0,LoadGraph("pipo-battlebg009.jpg"),true);
}
