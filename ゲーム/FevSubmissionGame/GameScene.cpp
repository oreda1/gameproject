#include "GameScene.h"
#include "BaseNumber.h"
#include "Dxlib.h"




void GameScene::Draw()
{


	//ƒQ[ƒ€ƒV[ƒ“‚Ìˆ—
	int MapHandle = LoadGraph("[A]Water3_Cave1_pipo.png");

	for (int x = 0; x< SumMapX; x++)
	{
		for (int y = 0; y < SumMapY; y++)
		{
		
                
			if(MakeMap[y][x]==1)
			{
				 
				
				DrawRectGraph(GroundX, GroundY, CropX, CropY, MapIndicationX, MapIndicationY, MapHandle, true);
				
				
			}

			
		}


	}


	


}


void GameScene::Update()
{
}



void GameScene::Init()
{
}
