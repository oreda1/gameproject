#include "Camera.h"
#include "PlayScene.h"



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Player* player = new Player;
	Camera* camera = new Camera;
	PlayScene* play = new PlayScene;

	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);



	player->Load();
	player->Init();


	
	// �Q�[�����[�v
	
	while (play->SceneFlag)
	{
		// ���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();
	// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();
		// �Q�[���̏���
		play->BarkGround();
	    camera->Look(*player);
		camera->ViewpointShift();
		play->Button();
		player->Update();
		player->Draw();
		play->Text();
		play->Clear();
		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();
		
		
		// esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60�ɌŒ肷��
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			// 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}