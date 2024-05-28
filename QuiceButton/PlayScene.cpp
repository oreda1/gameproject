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
	
	if (SceneFlag==true)
	{
		switch (push)
		{
		case one:
			if (CheckHitKey(KEY_INPUT_1))
			{
				score_count+=1;
			}
			break;
		case two:
			if (CheckHitKey(KEY_INPUT_2))
			{
				score_count += 1;
			}
			break;
		case a:
			if (CheckHitKey(KEY_INPUT_A))
			{
				score_count += 1;
			}
			break;
		case b:
			if (CheckHitKey(KEY_INPUT_B))
			{
				score_count += 1;
			}
			break;
		case tab:
			if (CheckHitKey(KEY_INPUT_TAB))
			{
				score_count += 1;
			}
			break;
		case click:
			if (CheckHitKey(DX_CHECKINPUT_MOUSE))
			{
				score_count += 1;
			}
			break;
		default:
			break;
		}
	}
	if (score_count>score_count+1)
	{
		
	}
	
	DrawFormatString(0, 100,0xffffff,"count=%d",score_count);


	
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
	int number = GetRand(5);
	if (number == 0)
	{
		push = one;
	}
	else if (number == 1)
	{
		push = two;
	}
	else if (number == 2)
	{
		push = a;
	}
	else if (number == 3)
	{
		push = b;
	}
	else if (number == 4)
	{
		push = tab;
	}
	else if (number == 5)
	{
		push = click;
	}
	return false;
}
