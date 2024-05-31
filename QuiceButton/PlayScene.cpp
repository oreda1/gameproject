#include "PlayScene.h"


PlayScene::PlayScene() :	
	number(0),
	frameCount(0),
	pushPoint(0)
{
	
	GetHitKeyStateAll(button);
	score_count = 0;
	number_check = false;
	_or = true;

	
}

void PlayScene::Init()
{
	number = GetRand(3);
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
	
	DrawFormatString(0, 100, 0xffffff, "count=%d", score_count);



} 

void PlayScene::Clear()
{
	
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
	
	/*if (number == 0)_number = A;
	if (number == 1)_number = B;
	if (number == 2)_number = X;
	if (number == 3)_number = Y;*/

	if (score_count < 30)
	{
		if (frameCount % 60 == 0)
		{
			CheckKey();
		}
	}
	if (_number == A)
	{
		if (CheckHitKey(KEY_INPUT_A) != 0)
		{
			score_count += 1;
			pushPoint += 1;
			return number;
			
		}
	}
	if (_number == B)
	{
		if (CheckHitKey(KEY_INPUT_B) != 0)
		{
			score_count += 1;
			pushPoint += 1;
			return number;
			
		}
	}
	if (_number == X)
	{
		if (CheckHitKey(KEY_INPUT_X) != 0)
		{
			score_count += 1;
			pushPoint += 1;
			return number;
			
		}
		
	}
	if (_number == Y)
	{
		if (CheckHitKey(KEY_INPUT_Y) != 0)
		{
			score_count += 1;
			pushPoint += 1;
			return number;
		}
	}

	frameCount++;
	
	DrawFormatString(300, 300, 0xffffff, "push=%d", _number);
	DrawFormatString(300, 350, 0xffffff, "number=%d", number);
	DrawFormatString(450, 350, 0xffffff, "pushPoint=%d", pushPoint);


	if (pushPoint == score_count)
	{
		ClearDrawScreen();
		DrawString(400, 400, "Clear", 0xffffff);
		SetBackgroundColor(0, 0, 0);

	}
	if (score_count == 30)
	{
		ClearDrawScreen();
		DrawString(400, 400, "CGameOver", 0xffffff);
		SetBackgroundColor(0, 0, 0);
	}

	return _number;
}

void PlayScene::Floor()
{
	
}

void PlayScene::CheckKey()
{
	number = GetRand(3);

	switch (number)
	{
	case 0:
		DrawString(200, 200, "A", 0xffffff);
		_number = A;
		break;
	case 1:
		DrawString(200, 200, "B", 0xffffff);
		_number = B;
		break;
	case 2:
		DrawString(200, 200, "X", 0xffffff);
		_number = X;
		break;
	case 3:
		DrawString(200, 200, "Y", 0xffffff);
		_number = Y;
		break;

	}


	

}
