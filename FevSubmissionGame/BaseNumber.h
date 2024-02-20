#pragma once
#include "DxLib.h"
namespace{

	constexpr int GameWidth = 640;
	constexpr int GameHeight = 480;
	//マップ1マス分の大きさ
	constexpr int  MapChipSize = 10;

	 



	struct TitleP
	{
		int Key[256];
		int fsize, fwidh;

	}titleP;

	struct MenuElement_t {
		int x, y;			//座標格納用変数
		char name[256];//項目名格納用変数


	};

	int menuX = 250;
	int menuY = 300;
	MenuElement_t MenuElement[50]{


	 {menuX,menuY,"GAME START"}


	};




	

	
}