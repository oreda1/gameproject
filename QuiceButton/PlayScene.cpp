#include "PlayScene.h"


PlayScene::PlayScene() :
	number(0),
	frame_count(0),
	pushPoint(0),
	miss_count(0),
	score()
{

	GetHitKeyStateAll(button);
	time_count = 0;
	number_check = false;
	_or = true;


}

void PlayScene::Init()
{
	number = GetRand(3);
}

void PlayScene::BarkGround()
{
	SetBackgroundColor(0, 0, 0);
	
}

void PlayScene::Text()
{

	
	DrawFormatString(0, 120, 0xffffff, "miss %d", miss_count);
	DrawFormatString(0, 100, 0xffffff, "count=%d", time_count);
}

void PlayScene::Button()
{
	
	




} 

void PlayScene::Clear()
{
	DrawExtendFormatString(600, 0, 2, 2, 0x00ffff, "%d", score);
	if (score == 30)
	{
		ClearDrawScreen();
		DrawExtendFormatString(200, 100, 2, 2, 0xffffff, "GAMECLEAR");
		miss_count = 0;
		time_count = 0;
		


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
	VECTOR Over = VGet(0, 10, 0);

	frame_count++;
	if (time_count < 30 && frame_count % 60 == 0)
	{
		time_count += 1;

	}
	if (time_count > 5)
	{
		miss_count += 1;
		time_count = 0;
	}

	if (miss_count == 5)
	{
		ClearDrawScreen();
		DrawExtendFormatString(200, 100, 2, 2, 0xff0000, "GAMEOVER");

		return frame_count = 0;

	}






}

void PlayScene::Floor()
{
	
}

int PlayScene::CheckKey()
{
	

	switch (number)
	{
	case 0:
		_number = A;
		break;
	case 1:
		_number = B;
		break;
	case 2:
		_number = X;
		break;
	case 3:
		_number = Y;
		break;
	default:
		break;

	}


	if (_number == A && CheckHitKey(KEY_INPUT_A) != 0)
	{
		score += 1;
		number_check = true;
		number = GetRand(3);
		time_count = 0;
	}
	if (_number == B && CheckHitKey(KEY_INPUT_B) != 0) 
	{
		score += 1;
		number_check = true;
		number = GetRand(3);
		time_count = 0;
	}
	if (_number == X && CheckHitKey(KEY_INPUT_X) != 0)
	{
		score += 1;
		number_check = true;
		number = GetRand(3);
		time_count = 0;

	}
	if (_number == Y && CheckHitKey(KEY_INPUT_Y) != 0)
	{
		score += 1;
		number_check = true;
		number = GetRand(3);
		time_count = 0;
	}




	DrawFormatString(300, 400, 0xffffff, "%c‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢", _number);
	return number;





}
