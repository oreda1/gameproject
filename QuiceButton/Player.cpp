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
	Anim::Index[1] = MV1AttachAnim(ModelHandle[1], 1);
	Anim::Index[2] = MV1AttachAnim(ModelHandle[2], 2);
	Anim::TotalTime = MV1GetAttachAnimTotalTime(ModelHandle[0], Anim::Index[0]);

}

void Player::Load()
{
	ModelHandle[0] = MV1LoadModel("Asset/Player.mv1");
	ModelHandle[1] = MV1LoadModel("Asset/Player_PoseT.mv1");
	ModelHandle[2] = MV1LoadModel("Asset/Player_Prone_t.mv1");




}

void Player::Draw()
{

	for (int i = 0; i < 3; i++)
	{
		MV1DrawModel(ModelHandle[i]);

	}
	
	
	

}

void Player::Update()
{
	
      MV1SetPosition(ModelHandle[0], pos);
	
	
	
	DrawFormatString(0, 20, 0xffffff, "X=%.0f,Y=%.0f,Z=%.0f,", pos.x, pos.y, pos.z);



}


