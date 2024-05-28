#include "Player.h"

namespace Anim
{

	float TotalTime;
	//アニメーション現在の時間
	float Nowtime;
	int Index[5];




}


Player::Player():
	ModelHandle(),
	pos(VGet(0.0f, 200.0f, 150.0f))
{
	
}
Player::~Player()
{
	MV1DeleteModel(ModelHandle[0]);
}
void Player::Init()
{
	Anim::Nowtime = 0.0f;
	Anim::Index[0] = MV1AttachAnim(ModelHandle[0], 0);

}

void Player::Load()
{
	ModelHandle[0] = MV1LoadModel("Asset/Player.mv1");
	ModelHandle[1] = MV1LoadModel("Asset/Player_PoseT.mv1");
	ModelHandle[2] = MV1LoadModel("Asset/Player_Prone_t.mv1");



	

}

void Player::Draw()
{
	MV1DrawModel(ModelHandle[0]);
	MV1DrawModel(ModelHandle[1]);
	MV1DrawModel(ModelHandle[2]);
	
	

}

void Player::Update()
{
	MV1SetPosition(ModelHandle[0], pos);
	if (KEY_INPUT_SPACE)
	{

	}
	DrawFormatString(0, 20, 0xffffff, "X=%.0f,Y=%.0f,Z=%.0f,", pos.x, pos.y, pos.z);



}


