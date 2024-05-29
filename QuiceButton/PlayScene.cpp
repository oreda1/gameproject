#include "PlayScene.h"

PlayScene::PlayScene()
{
	
	GetHitKeyStateAll(button);
	score_count = 0;
 
	
}

void PlayScene::BarkGround()
{
	SetBackgroundColor(50, 0, 100);
	
}

void PlayScene::Text()
{



}

void PlayScene::Button()
{
	Check();
	if (SceneFlag == true)
	{

	}
	if (score_count > score_count + 1)
	{

	}

	DrawFormatString(0, 100, 0xffffff, "count=%d", score_count);



}

void PlayScene::Clear()
{
	if (score_count>=30)
	{
		
		DrawString(300, 300, "Clear", 0xffffff);
		SetBackgroundColor(0, 0, 0);
        ClearDrawScreen();
	}
}

int PlayScene::Key()
{
	for (int i = 0; i < 256; i++)
	{
		if (button[i] != 0) {
			
			key[i]++;			//‰ÁŽZ
		}
		else {						//‰Ÿ‚³‚ê‚Ä‚¢‚È‚¯‚ê‚Î
			key[i] = 0;

		}
	}
	return 0;
}

bool PlayScene::Check()
{
	number = GetRand(4);

	if (number == 0)
	{
		push = A;
	}
	if (number == 1)
	{
		push = B;
	}
	if (number == 2)
	{
		push = X;
	}
	if (number == 3)
	{
		push = Y;
	}
	_number =&number;
	
	
	DrawFormatString(300, 300, 0xffffff, "push=%d", _number);


	return push;
}

void PlayScene::Floor()
{
	
}
