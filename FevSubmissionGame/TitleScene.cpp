#include "TitleScene.h"
#include "BaseNumber.h"
#include "Dxlib.h"
#include "SceneManager.h"

SceneManager scene;
bool TitleScene::Update()
{

	/*�^�C�g���V�[���̏���*/
	//���̕`��
	MakeSelectTriangle();
	//Key����
	gpUpdateKey();

	//DrawRectGraph(50, 0, 70,30,350,100, TitleHandle, false);


	if (titleP.Key[KEY_INPUT_DOWN])
	{
		triangle.y1 = 345;
		triangle.y2 = 330;
		triangle.y3 = 370;
	}

	if (titleP.Key[KEY_INPUT_UP])
	{
		triangle.y1 = 305;
		triangle.y2 = 290;
		triangle.y3 = 330;
	}
	//���j���[�̕`��
	for (int i = 0; i < 10; i++) {		//���j���[���ڂ�`��

		ChangeFont("07�ӂ���Ƃ��͕|��������");
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, 0xffffff, MenuElement[i].name);
	}
	if (titleP.Key[KEY_INPUT_Z])
	{
		return scene.NowScene;
	}
	
	
	//����I��
	return true;//�V�[����؂�ւ��Ȃ�
}



int TitleScene::gpUpdateKey()
{
	char tmpkey[256]; //���݂̃L�[���͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpkey); //���ׂẴL�[���͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++) {	//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		if (tmpkey[i] != 0) {
			titleP.Key[i]++;				//���Z
		}
		else {						//������Ă��Ȃ����
		   titleP.Key[i] = 0;

		}
	}
	return 0;
}

void TitleScene::MakeSelectTriangle()
{

	DrawTriangle(triangle.x1,
		triangle.y1,
		triangle.x2,
		triangle.y2,
		triangle.x3,
		triangle.y3,
		0xffffff, true);

}

void TitleScene::TitleMusic()
{
	PlayMusic("MusMus-BGM-062.mp3",DX_PLAYTYPE_LOOP);
}
