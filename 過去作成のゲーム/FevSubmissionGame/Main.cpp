#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "OptionScene.h"
#include "SceneManager.h"
#include "GameClearScene.h"



/*���C��*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib����������(�ݒ荞��)*/
	ChangeWindowMode(true);
	SetWindowText("UNNAMED");
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);//����ʏ�������

	/*�Q�[���I�u�W�F�N�g�̍쐬*/
	TitleScene title;
	Map map;
	Character character;
	Enemy enemy;
	OptionScene option;
	SceneManager scene;
	GameClearScene clear;


	
	
	/*�Q�[�����[�v*/
	bool sceneFlag = true;//true:�^�C�g���V�[��,false:�Q�[���V�[��
	//�Q�[���V�[���J��Ԃ�����
	while (true)
	{
		
		/*��ʂ̏�����*/
		ClearDrawScreen();
		scene.DivideScene();
		/*�Q�[������*/
		if (sceneFlag)
		{
			sceneFlag=title.Update();
			title.TitleMusic(); 
			scene.ExplanationText(); 

		}
		//�Q�[�����s���
		else if (scene.NowScene==scene.Playing)
		{
			
			map.Draw();
			map.BackGround();
			map.TimeLimit();
			map.TimeUpdate();
			character.Draw();
			character.FallCollision();
			character.Move(map);
			enemy.Drawcircle();
			enemy.Draw();
			enemy.InitEnemy();
			enemy.UpdateEnemy();
			enemy.AdditionMove();
			enemy.EnemyMove();
			enemy.EnemyAirCollision(character, map, scene);
		}

	
		
		/*�`��̊m��*/
		ScreenFlip();

		/*�Q�[�����[�v�I������*/
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) { return true; }
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { return true; }

	 
	}
		
	/*Dxlib�I������*/
	DxLib::DxLib_End();
	return 0;
}
