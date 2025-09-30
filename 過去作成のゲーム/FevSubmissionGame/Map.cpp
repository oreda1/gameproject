#include "Map.h"
#include "BaseNumber.h"
#include "Dxlib.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "GameClearScene.h"

SceneManager m_scene;
Enemy m_enemy;
GameClearScene map_clear;

Map::Map()
{
	
}

Map::~Map()
{
}

void Map::Draw()
{
	
	//�Q�[���V�[���̏���
	int MapHandle = LoadGraph("[A]Water3_Cave1_pipo.png");
	DrawRectGraph(GroundX, GroundY, CropX, CropY, MapIndicationX, MapIndicationY, MapHandle, false);


}


//�c�莞��
void Map::TimeUpdate()
{
	time_count += 0.02;
	DrawExtendFormatString(220, 0,3,3, 0x0000ff, "%f", time_count);

}



void Map::Init()
{

}

//�c�莞�ԂƎ��Ԍo�ߌ�̏���
bool Map::TimeLimit()
{
	m_scene.GameClear = false;
	
	
	time_count+=time;
    DrawFormatString(550, 0, 0x0000ff, "%f", time_count);
	if (time_count >= 60)
	{
		// Reset enemy positions and show game clear screen
	m_scene.GameClear = true;
	ClearDrawScreen();
	m_enemy.enemyX = 0;
	m_enemy.enemyY = 0;
	m_enemy.RabbitX = 0;
	m_enemy.RabbitY = 0;
	
	DrawExtendFormatString(100, 100, 5, 5, 0xffffff, "Game Clear");
	DrawFormatString(200, 200, 0xffffff, "Thank You For Playing\nPlease Press ESC");
	
		return true;
	}
	
	return false;
}


//�w�i�摜�̃��[�h
void Map::BackGround()
{
	DrawGraph(0,0,LoadGraph("pipo-battlebg009.jpg"),true);
}

void Map::End()
{
}

//�V�[���J�ڂ����\��
SceneBase* Map::Update()
{
	if (CheckHitKeyAll(KEY_INPUT_Z)==1)
	{

	}
	
	return nullptr;
}

void  MapBuild()
{
  

}