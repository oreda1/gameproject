#include "Dxlib.h"
#include "GameScene.h"
#include "BaseNuber.h"
#include "Character.h"


int gpUpdateKey() {
	char tmpkey[256]; //���݂̃L�[���͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpkey); //���ׂẴL�[���͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {	//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (tmpkey[i] != 0) {
			title.Key[i]++;				//���Z
		}
		else {						//������Ă��Ȃ����
			title.Key[i] = 0;
		}

	}
	return 0;
}

void MakeSelectTriangle()
{
	
	DrawTriangle(triangle.x1, 
		triangle.y1,
		triangle.x2,
		triangle.y2,
		triangle.x3,
		triangle.y3,
		GetColor(255, 255, 255), true);

};
 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetGraphMode(GameWidth,GameHeight, 32);
	ChangeWindowMode(true);
	
   GameScene*ga_scene=new GameScene;
   //Character* mv_chara = new Character;
  
   CharaMove charamove;
   Character characrer;
    
    


	if (DxLib_Init() == -1) { return -1; }
	
	

	int SelectNum = 0;


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0)
	{
		MakeSelectTriangle();
		if (title.Key[KEY_INPUT_DOWN])
		{
			
			triangle.y1 =triangle.y1 + 25;
			triangle.y2 =triangle.y2 + 25;
			triangle.y3 =triangle.y3 + 25;
		}
		if (title.Key[KEY_INPUT_UP])
		{
			triangle.y1 = triangle.y1 -25;
			triangle.y2 = triangle.y2 - 25;
			triangle.y3 = triangle.y3 - 25;
		}
		
		

		if ((title.Key[KEY_INPUT_Z] == 1) || (title.Key[KEY_INPUT_RETURN] == 1)) {

			break;

		}
		for (int i = 0; i < 50; i++) {		//���j���[���ڂ�`��

			DrawFormatString(MenuElement[i].x,MenuElement[i].y, GetColor(255, 255, 255),MenuElement[i].name);
		}
	}
	if (SelectNum == 1) {
		DxLib_End();
	}
	//�����ɃQ�[���{�҂������B
	
    ga_scene->DrawPicture();
	characrer.Draw();
	
	ClearDrawScreen();
	
	WaitKey();
	DxLib_End();
	return 0;


}
