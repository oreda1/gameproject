#include "PlayScene.h"

namespace
{
	const char*music_path = "btn08.mp3";
   

}
 


PlayScene::PlayScene() :
	number(0),
	frame_count(0),
	pushPoint(0),
	miss_count(0),
	score(0),
	start(true)

{
	
	time_count = 0;
	number_check = false;
	_or = true;
	SceneFlag =false;
	start = true;
	


}

PlayScene::~PlayScene()
{



}

void PlayScene::Init()
{
	number = GetRand(3);
	score = 0;
	time_count = 0;

	
}

void PlayScene::BarkGround()
{
	SetBackgroundColor(256, 256, 256);
	
}

void PlayScene::Text()
{

	DrawFormatString(0, 120, 0x000000, "miss %d", miss_count);
	DrawFormatString(0, 100, 0x000000, "count=%d", time_count);
}

void PlayScene::Button()
{
	
	if (_number == A && button[KEY_INPUT_A] || button[PAD_INPUT_1])
	{
		_score = score;
		score += 1;
		PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		number = GetRand(3);
		time_count = 0;
	}
	if (_number == B && button[KEY_INPUT_B] || button[PAD_INPUT_2])
	{
		_score = score;
		score += 1;
		PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		number = GetRand(3);
		time_count = 0;
	}
	if (_number == X && button[KEY_INPUT_X] || button[PAD_INPUT_3])
	{
		_score = score;
		score += 1;
		PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		number = GetRand(3);
		time_count = 0;

	}
	if (_number == Y && button[KEY_INPUT_Y]|| button[PAD_INPUT_4])
	{
		_score = score;
		score += 1;
		PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		number = GetRand(3);
		time_count = 0;
	}
	




} 

void PlayScene::Clear()
{
	DrawExtendFormatString(600, 0, 2, 2, 0x00ffff, "%d", score);
	if (score >=30)
	{
		ClearDrawScreen();
		DrawExtendFormatString(200, 100, 2, 2, 0x000000, "GAMECLEAR");
		miss_count = 0;
		time_count = 0;

	}
	if (CheckHitKey(KEY_INPUT_0))
	{
		start = true;
		Start();	
		Init();
		SetDrawScreen(DX_SCREEN_BACK);


	}

	
	
}

int PlayScene::Key()
{
	GetHitKeyStateAll(button);
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
		time_count = 0;
		score = 0;
		return frame_count = 0;

	}
	//’Ç‰Á—v‘f
	if (score/10==1&&score%3==2)
	{
		
		
	  
	}



}

void PlayScene::Floor()
{
	
	
}

bool PlayScene::Start()
{ 
	int start_back = LoadGraph("BackText.png");

	while (start)
	{
		SetDrawScreen(DX_SCREEN_FRONT);
		DrawGraph(0, 0, start_back, false);
		if (CheckHitKey(KEY_INPUT_R))
		{
			SceneFlag = true;
			start = false;
		}
	}

	return start;
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

	
	DrawExtendFormatString(TextPos.x,TextPos.y,TextPos.z,TextPos.z, 0x000000, "%c‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢", _number);
	return number;





}

RECTDATA PlayScene::Disturbance()
{
	vect = VGet(0, 100, 100);
	DrawBox(rect.x1, rect.x2, rect.y2+vect.y, rect.y2+vect.y, 0xff0000, true);


	return RECTDATA();
}










//https://www.youtube.com/watch?v=REskPu4kVjI