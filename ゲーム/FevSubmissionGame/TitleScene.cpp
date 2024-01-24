#include "TitleScene.h"
#include "BaseNumber.h"
#include "Dxlib.h"
#include "SceneManager.h"
bool TitleScene::Update()
{
	/*�^�C�g���V�[���̏���*/
	//���̕`��
	MakeSelectTriangle();
	//Key����
	gpUpdateKey();
    

	if (MenuElement->y == 340 && titleP.Key[KEY_INPUT_SPACE])
	{
		SceneManager::Scene::S_Option;
	

	}
	
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
	if ((titleP.Key[KEY_INPUT_Z] == 1) || (titleP.Key[KEY_INPUT_RETURN] == 1)) {

		return false;//�V�[���؂�ւ�
	}
	//���j���[�̕`��
	for (int i = 0; i < 50; i++) {		//���j���[���ڂ�`��
	
		
		ChangeFont("Super Mario 256");
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, 0xffffff, MenuElement[i].name);
	}

	//����I��
	return true;//�V�[����؂�ւ��Ȃ�
}

int TitleScene::gpUpdateKey() {
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