#include "Dxlib.h"
int Key[256];
int fsize, fwidh;
//int CreateFontToHandle()

int gpUpdateKey() {
	char tmpKey[1280]; //���݂̃L�[���͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); //���ׂẴL�[���͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {	//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (tmpKey[i] != 0) {
			Key[i]++;				//���Z
		}
		else {						//������Ă��Ȃ����
			Key[i] = 0;
		}

	}
	return 0;
}

struct MenuElement_t {
	int x, y;			//���W�i�[�p�ϐ�
	char name[256];//���ږ��i�[�p�ϐ�
	
	
} MenuElement;

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) return -1;
	
	MenuElement_t MenuElement[10] = {
		{150,100,"�E�o�Q�[��"},
			{400, 260, "Game Start"},		//�^�O�̒��g�̏��ԂŊi�[
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
		for (int i = 0; i < 10; i++) {		//���j���[���ڂ�`��
			
			DrawFormatString(MenuElement[i].x, MenuElement[i].y,GetColor(255, 255, 255), MenuElement[i].name);
		}
	}
	if (SelectNum == 1) {
		DxLib_End();
	}
	//�����ɃQ�[���{�҂������B
	ClearDrawScreen();
	DrawFormatString(200, 200, GetColor(255, 255, 255), "�Q�[���{�҂ł�");
	WaitKey();
	DxLib_End();
	return 0;
	
}
