#include "OptionScene.h"
#include "DxLib.h"
 
void OptionScene::DrawFrame()
{
	DrawBox(10,0, 630, 480, 0xffffff,false);
}

void OptionScene::OptionText()
{
	for (int i = 0; i < 30; i++)
	{
		DrawFormatString(option_date->Option_posX,option_date->Option_posY,0xffffff,option_date->OptionItemName);
	}
	
}




