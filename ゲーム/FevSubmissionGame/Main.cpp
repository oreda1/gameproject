#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"

/*���C��*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib����������(�ݒ荞��)*/
	//SetGraphMode(GameWidth, GameHeight, 32);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);//����ʏ�������

	/*�Q�[���I�u�W�F�N�g�̍쐬*/
	TitleScene title;
	Map map;
	Character character;
	Enemy enemy;

	/*�Q�[�����[�v*/
	bool sceneFlag = true;//true:�^�C�g���V�[��,false:�Q�[���V�[��
	while (TRUE)
	{
		/*��ʂ̏�����*/
		ClearDrawScreen();

		/*�Q�[������*/
		if (sceneFlag)
		{
			
			sceneFlag = title.Update();
		}
		else
		{
			map.BackGround();
			map.Update();
			character.Draw();
			character.Move(map);
			map.Draw();
			enemy.Draw();
			enemy.EnemyMove();
		}

		/*�`��̊m��*/
		ScreenFlip();

		/*�Q�[�����[�v�I������*/
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) { break; }
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
	}

	/*Dxlib�I������*/
	DxLib::DxLib_End();
	return 0;
}

