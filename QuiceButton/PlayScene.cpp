#include "PlayScene.h"

PlayScene::PlayScene()
{
	
	
}

void PlayScene::BarkGround()
{
	
	
}

void PlayScene::Text()
{



}

void PlayScene::Button()
{
	
	for (int i = 0; i < 256; i++)
	{
		if (button[i] != 0) {
			button[i]++;				//‰ÁŽZ
		}
		else {						//‰Ÿ‚³‚ê‚Ä‚¢‚È‚¯‚ê‚Î
			button[i] = 0;

		}
	}

	if (button[KEY_INPUT_0])
	{
		++score_count;
      
	}
	
	DrawFormatString(0, 100,0xffffff,"count=%d",score_count);

	

	



	
}

void PlayScene::Clear()
{
	if (score_count>=15)
	{
		DrawString(300, 300, "Clear", 0xffffff);

	}
}
