#pragma once
#include "BaseNumber.h"
class TitleScene
{
public:
	bool Update();
	
	enum TitleMenu
	{
		Player1,
		Player2,
		Option

	};
	


	struct Triangle
	{
		//�R�}���h�O�p�`�������W

		int x2 = 200;//2�̒��_x���W(��)
		int y2 = 290;//2�̒��_y���W(��)
		int x3 = 200;//2�̒��_x���W(��)
		int y3 = y2 + 40;//2�̒��_y���W(��)330
		int x1 = 240;//1�̒��_x���W
		int y1 = (y2 + y3) / 2;//1�̒��_y���W305
	}triangle;


private:
	int gpUpdateKey();
	void MakeSelectTriangle();
};