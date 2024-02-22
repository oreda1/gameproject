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
	while (true)
	{
		scene.GameClear = false;
		/*��ʂ̏�����*/
		ClearDrawScreen();
		scene.DecisionScene();
		/*�Q�[������*/
<<<<<<< HEAD
=======
		if(sceneFlag)
		{
			sceneFlag =title.Update();
		    scene.ExplanationScene();
			
			
		}
		else if (scene.NowScene==scene.Playing)
		{	
			map.BackGround();
			map.Draw();
			map.TimeUpdate();
			character.Effect();
			character.Draw();
			character.Move(map);
			enemy.Draw();
			enemy.InitEnemy();	
			enemy.EnemyVerticalMove();
			enemy.EnemyMove();	
			enemy.Drawcircle();
			enemy.KillerRabbit(character);
			enemy.UpdateEnemy();
			enemy.AdditionMove();
			clear.Draw();
			map.TimeLimit();
			enemy.EnemyAirCollision();
<<<<<<< HEAD
=======
			
			
			
		
		}
		else if(scene.NowScene==scene.S_Option)
		{
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
			
			
			
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
		

		
		/*�`��̊m��*/
		ScreenFlip();

		/*�Q�[�����[�v�I������*/
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0) { return true; }
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
<<<<<<< HEAD
<<<<<<< HEAD
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) {}
=======
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { return title.Update(); }
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
=======
		else if (CheckHitKey(KEY_INPUT_ESCAPE)) { return title.Update(); }
>>>>>>> 2ad6b3a2c1808028c85419110a479e8cbe503a90
		
	}

	/*Dxlib�I������*/
	DxLib::DxLib_End();
	return 0;
}

