#include "SceneManager.h"
#include "TitleScene.h"
#include "Map.h"
#include "OptionScene.h"
#include "Enemy.h"
#include "Character.h"



SceneManager::SceneManager():
base_manager(nullptr)
{
	

}

SceneManager::~SceneManager()
{
	if (base_manager)
	{
		delete base_manager;
		base_manager = nullptr;
	}

	
}

//�V�[�������ꂼ�ꔻ�ʂ���֐�
bool SceneManager::DivideScene()
{
	return 0;
}

//NowScene�𔻕ʂ��A���ꂼ��̃V�[���ɂ��킹���������s��
bool SceneManager::ChangeScene()
{ 
	return 0;
}
//�����܂Ƃ߂��֐�
void SceneManager::ExplanationScene()
{
	ChangeScene();
	DivideScene();
}

//�X�^�[�g�e�L�X�g
void SceneManager::ExplanationText()
{
	int x0 = 0;
	int x1 = 470;
	int x2 = 430;
	int y0 = 100;
	int y1 = 135;
	int y2 = 170;
	int y3 = 20;

	
	DrawString(x0, y0, "�X�y�[�X�L�[�ŃW�����v\nESC�L�[�ŏI��", 0xff0000);
	DrawString(x0, y1, "�G��60�b�����炸\n�����c��΃Q�[���N���A��!!",0xff0000);
	DrawString(x0, y2, "Z�L�[�ŃX�^�[�g",0xff0000);
	DrawString(x1, x0, "�f�ޒ񋟎җl", 0xfffff);
	DrawString(x2, y2, "    �҂ۂ�q�ɗl\nArtificial Providence�l\n       ���ꓯ",0xffffff);

	//ChangeFont("NomalFontHandle");
	DrawString(0, 100, "�X�y�[�X�L�[�ŃW�����v\nESC�L�[�ŏI��", 0xff0000);
	DrawString(0, 135, "�G��60�b�����炸\n�����c��΃Q�[���N���A��!!",0xff0000);
	DrawString(0, 170, "Z�L�[�ŃX�^�[�g\n����̃��C�t�������Ȃ�ƃQ�[���I�[�o�[�ɂȂ邼!!",0xff0000);
	DrawString(470, 0, "�f�ޒ񋟎җl", 0xfffff);
	DrawString(430, 20, "    �҂ۂ�q�ɗl\nArtificial Providence�l\n       ���ꓯ",0xffffff);

	base_manager->Draw();
}

void SceneManager::Init()
{
	base_manager->Init();
}

//�L�[����
void SceneManager::Scene_ChangeKey()
{
	GetHitKeyStateAll(scene_key);
	for (int i = 0; i < 256; i++)
	{
		if (scene_key[i] != 0) {
		   scene_key[i]++;				//���Z
		}
		else {						//������Ă��Ȃ����
			scene_key[i] = 0;

		}
	}
}


