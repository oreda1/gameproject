#include "OptionScene.h"
#include "DxLib.h"

OptionScene::OptionScene()
{
}

OptionScene::~OptionScene()
{
}

void OptionScene::DrawFrame()
{
	DrawBoxAA(100,100, 340, 280, 0xffffff,false);
}

void OptionScene::OptionText()
{
	for (int i = 0; i < 10; i++)
	{
		DrawFormatString(option_date->Option_posX, option_date->Option_posY, 0xffffff, option_date->OptionItemName);
	}
	
}




