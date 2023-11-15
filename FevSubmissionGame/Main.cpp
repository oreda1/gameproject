#include "Dxlib.h"
int Key[256];
int fsize, fwidh;
//int CreateFontToHandle()

int gpUpdateKey() {
	char tmpKey[1280]; //現在のキー入力状態を格納する
	GetHitKeyStateAll(tmpKey); //すべてのキー入力状態を得る
	for (int i = 0; i < 256; i++) {	//i番のキーコードに対応するキーが押されていたら
		if (tmpKey[i] != 0) {
			Key[i]++;				//加算
		}
		else {						//押されていなければ
			Key[i] = 0;
		}

	}
	return 0;
}

struct MenuElement_t {
	int x, y;			//座標格納用変数
	char name[256];//項目名格納用変数
	
	
} MenuElement;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) return -1;
	
	MenuElement_t MenuElement[10] = {
		{150,100,"脱出ゲーム"},
			{400, 260, "Game Start"},		//タグの中身の順番で格納
			{290, 300, "Option"},
		
		
	};
	int SelectNum = 0;
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		if ((Key[KEY_INPUT_DOWN] == 1) || (Key[KEY_INPUT_UP] == 1)) {
			SelectNum = 1 - SelectNum;
			int dum = MenuElement[0].x;
			MenuElement[0].x = MenuElement[1].x;
			MenuElement[1].x = dum;
		}
		if ((Key[KEY_INPUT_Z] == 1) || (Key[KEY_INPUT_RETURN] == 1)) {
			break;
		}		
		for (int i = 0; i < 10; i++) {		//メニュー項目を描画
			
			DrawFormatString(MenuElement[i].x, MenuElement[i].y,GetColor(255, 255, 255), MenuElement[i].name);
		}
	}
	if (SelectNum == 1) {
		DxLib_End();
	}
	//ここにゲーム本編を書く。
	ClearDrawScreen();
	DrawFormatString(200, 200, GetColor(255, 255, 255), "ゲーム本編です");
	WaitKey();
	DxLib_End();
	return 0;
	
}
