#include "OptionScene.h"
#include "DxLib.h"
#include "TitleScene.h"
 
void OptionScene::Init()
{
}

SceneBase* OptionScene::Update()
{
	return nullptr;
}



//オプション枠の表示
void OptionScene::DrawFrame()
{
	DrawBox(10,0, 630, 480, 0xffffff,false);
}

//オプションテキスト
void OptionScene::OptionText(TitleScene opt_title)
{
	
	opt_title.MakeSelectTriangle();
	for (int i = 0; i < 3; i++)
	{
		DrawFormatString(option_date->Option_posX, option_date->Option_posY, 0xffffff, option_date->OptionItemName);
	}
	
	
	
}




