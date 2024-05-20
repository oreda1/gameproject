#include "PlayScene.h"

PlayScene::PlayScene()
{
	button[255] = -1;
	button_count = GetRand(5);
	count;
}

void PlayScene::BarkGround()
{
	
	
}

void PlayScene::Text()
{



}

void PlayScene::Button()
{
	GetHitKeyStateAll(button);
	for (int i = 0; i < 256; i++) {	//i番のキーコードに対応するキーが押されていたら
		if (button[i] != 0) {
			button[i]++;			//加算
		}
		else {						//押されていなければ
			button[i] = 0;

		}
	}
	if (button_count==1)
	{
		button[CheckHitKey(PAD_INPUT_1 || KEY_INPUT_1)];
	}
	if (button_count==2)
	{
		button[CheckHitKey(PAD_INPUT_2 || KEY_INPUT_1)];
	}
	if (button_count==3)
	{
		button[CheckHitKey(PAD_INPUT_3 || KEY_INPUT_1)];
	}
	if (button_count==4)
	{
		button[CheckHitKey(PAD_INPUT_4 || KEY_INPUT_1)];
	}
	if (button_count==5)
	{
	   button[CheckHitKey(PAD_INPUT_5 || KEY_INPUT_1)];
	}

	if (button[PAD_INPUT_1||KEY_INPUT_1])
	{
		count += 1;
	}	
	if (button[PAD_INPUT_2 || KEY_INPUT_1])
	{
		count += 1;
	}	
	if (button[PAD_INPUT_3 || KEY_INPUT_1])
	{
		count += 1;
	}	
	if (button[PAD_INPUT_4 || KEY_INPUT_1])
	{
		count += 1;
	}	
	if (button[PAD_INPUT_5 || KEY_INPUT_1])
	{
		count += 1;
	}
	DrawFormatString(0, 100,0xffffff,"count=%d",count);

	

	



	
}

void PlayScene::Clear()
{
	if (count==15)
	{

	}
}
