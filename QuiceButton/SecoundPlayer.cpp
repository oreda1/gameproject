#include "SecoundPlayer.h"


void SecoundPlayer::Init()
{
	s_score = 0;
	s_number = GetRand(3);
	
}

void SecoundPlayer::Key()
{
	GetHitKeyStateAll(_button);
	for (int i = 0; i < 256; i++)
	{
		if (_button[i] != 0) {

			_key[i]++;			//‰ÁŽZ

		}
		else {						//‰Ÿ‚³‚ê‚Ä‚¢‚È‚¯‚ê‚Î
			_key[i] = 0;

		}
	}
	
}

void SecoundPlayer::Button()
{
	
	if (_number == A && _button[KEY_INPUT_A] || _button[PAD_INPUT_1])
	{
		
		s_score += 1;
		//PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		s_number = GetRand(3);
		time_count = 0;
	}
	if (_number == B && _button[KEY_INPUT_B] || _button[PAD_INPUT_2])
	{
		
		s_score += 1;
		//PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		s_number = GetRand(3);
		time_count = 0;
	}
	if (_number == X && _button[KEY_INPUT_X] || _button[PAD_INPUT_3])
	{
		
		s_score += 1;
		//PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		s_number = GetRand(3);
		time_count = 0;

	}
	if (_number == Y && _button[KEY_INPUT_Y] || _button[PAD_INPUT_4])
	{
		
		s_score += 1;
		//PlayMusic(music_path, DX_PLAYTYPE_NORMAL);
		number = GetRand(3);
		time_count = 0;
	}
}

int SecoundPlayer::CheckKey()
{
	
	PlayScene::CheckKey();
	TextPos.x = 600;
	return s_number;
}

void SecoundPlayer::Clear()
{
	DrawExtendFormatString(620, 0, 2, 2, 0xff0000, "%d", s_score);
}

