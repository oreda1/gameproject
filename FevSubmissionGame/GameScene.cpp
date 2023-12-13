#include "DxLib.h"
#include "GameScene.h"
#include "BaseNuber.h"	
#include "Character.h"
#include <iostream>
#include <fstream>
#include<string>
using namespace std;





GameScene::GameScene() :
	water3(0)
{
	
}
GameScene::~GameScene()
{




}


void GameScene::DrawPicture()
{
	
	for (int x = 0; x < mapX; x++)
	{
		for (int y = 0; y < mapY; y++)
		{
			if (MakeMap[y][x] == 1)
			{
				DrawGraph(384,240, MapHandle, false);

			}
		}


	}

	


}

//ƒ}ƒbƒv‚Ì‰Šú‰»
void GameScene::InitriseMap()
{




}