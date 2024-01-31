#include "OptionScene.h"
#include "DxLib.h"
#include "TitleScene.h"
 
void OptionScene::DrawFrame()
{
	DrawBox(10,0, 630, 480, 0xffffff,false);
}

void OptionScene::OptionText(TitleScene opt_title)
{
	
	opt_title.MakeSelectTriangle();
	for (int i = 0; i < 30; i++)
	{
		DrawFormatString(option_date->Option_posX,option_date->Option_posY,0xffffff,option_date->OptionItemName);
	}
	if (titleP.Key[KEY_INPUT_RETURN])
	{
		
	}
	
	
}




