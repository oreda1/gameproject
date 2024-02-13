#include "Dxlib.h"
#include "BaseNumber.h"
#include "TitleScene.h"
#include "Map.h"
#include "Character.h"
#include "Enemy.h"
#include "OptionScene.h"
#include "SceneManager.h"
#include "GameClearScene.h"
#include <memory>


/*���C��*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*Dxlib����������(�ݒ荞��)*/
	//SetGraphMode(GameWidth, GameHeight, 32);
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
	title.TitleMusic();
	bool sceneFlag = true;//true:�^�C�g���V�[��,false:�Q�[���V�[��
	while (TRUE)
	{
		/*��ʂ̏�����*/
		ClearDrawScreen();
		/*�Q�[������*/
		if(sceneFlag)
		{
			sceneFlag = title.Update();
		    scene.ExplanationScene();
			scene.DecisionScene();
			
		}
		else if (scene.NowScene==scene.Playing)
		{	
			map.BackGround();
			map.Draw();
			map.TimeLimit();
			character.Effect();
			character.Draw();
			character.Move(map);
			enemy.Draw();
			enemy.InitEnemy();	
			enemy.EnemyVerticalMove();
			enemy.EnemyMove();	
			enemy.Drawcircle();
			enemy.KillerRabbit(character);
			enemy.EnemyAirCollision();
			enemy.UpdateEnemy();
			enemy.AdditionMove();
			clear.Draw();

		
		}
		else if(scene.NowScene==scene.S_Option)
		{
			
			option.DrawFrame();
			option.OptionText(title);
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

