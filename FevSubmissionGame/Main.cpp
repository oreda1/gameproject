#include "Dxlib.h"

struct Box
{
	int x = 20;
	int y = 250;
	int x1 = 100;
	int y1 = 450;

}box;

struct Title
	{
		int Key[256];
		int fsize, fwidh;

	}title;

//int CreateFontToHandle()

int gpUpdateKey() {
	char tmpKey[1280]; //���݂̃L�[���͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); //���ׂẴL�[���͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {	//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (tmpKey[i] != 0) {
			title.Key[i]++;				//���Z
		}
		else {						//������Ă��Ȃ����
			title.Key[i] = 0;
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
		    {150,200,"�E�o�Q�[��"},
			{300, 260, "Game Start"},		//�^�O�̒��g�̏��ԂŊi�[
			{290, 300, "Option"},
		
		
	};
	int SelectNum = 0;
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

		switch (title.Key[KEY_INPUT_UP]==1)
		{
		case 1:
			title.Key[1];
		default:
			
			break;
		}

		if ((title.Key[KEY_INPUT_Z] == 1) || (title.Key[KEY_INPUT_RETURN] == 1)) {
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
	
     
	DrawBox(box.x, box.y, box.x1, box.y1, GetColor(255, 255, 255), false);

	DrawFormatString(200, 200, GetColor(255, 255, 255), "�Q�[���{�҂ł�");

	WaitKey();
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_End();
	return 0;
	
}
