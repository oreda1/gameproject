#pragma once
#include "Character.h"
class Text
{
public:
	Text();
	~Text();
 
	void GameSceneText(Text&text);

	Character t_chara;

//private:
	
	//�v���C���[�̍��W�\��
	int PlayerCoordinateX;
	int PlayerCoordinataY;

	int GameText[256];
	
	

};




