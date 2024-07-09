#pragma once
#include "PlayScene.h"
class SecoundPlayer :public PlayScene
{
public:
	void Init();
	void Key();
	void Button();
	int CheckKey();
	void Clear();
  
private:
	int s_score,snumber,s_number;
	int s_frame_count, s_time_count, s_miss_count;
	char _button[256];
	int _key[256];
   

};

