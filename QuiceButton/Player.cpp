#include "Player.h"

namespace Anim
{

	float TotalTime;
	//アニメーション現在の時間
	float Nowtime;
	int Index[5];

	//アニメーションハンドル
	int frame=0,time_frame=0;

}


Player::Player():
	ModelHandle(),
	pos(VGet(0.0f, 200.0f, 150.0f))
{
	
}
Player::~Player()
{
	MV1DeleteModel(ModelHandle[0]);
	MV1DeleteModel(ModelHandle[1]);
	MV1DeleteModel(ModelHandle[2]);
	
}
void Player::Init()
{
	
	Anim::Index[0] = MV1AttachAnim(ModelHandle[0], 0);
	Anim::Index[1] = MV1AttachAnim(ModelHandle[1], 1);
	Anim::Index[2] = MV1AttachAnim(ModelHandle[2], 2);
	Anim::TotalTime = MV1GetAttachAnimTotalTime(ModelHandle[0], Anim::Index[0]);
	Anim::Nowtime = 0.0f;
	MV1SetAttachAnimTime(ModelHandle[0], Anim::Index[0], Anim::Nowtime);

}

void Player::Load()
{
	ModelHandle[0] = MV1LoadModel("Asset/Player.mv1");
	ModelHandle[1] = MV1LoadModel("Asset/Player_PoseT.mv1");
	ModelHandle[2] = MV1LoadModel("Asset/Player_Prone_t.mv1");




}

void Player::Draw()
{

	
	Anim::Nowtime += 50;
	if (Anim::Nowtime>=Anim::TotalTime)
	{
		Anim::Nowtime -= Anim::TotalTime;
		
	}
	MV1SetAttachAnimTime(ModelHandle[0], Anim::Index[0], Anim::Nowtime);

	

	MV1DrawModel(ModelHandle[Anim::frame]);
	
	


	

		
		


	
	
	
	

}

void Player::Update()
{
	
	MV1SetPosition(ModelHandle[Anim::frame], pos);
	MV1SetPosition(ModelHandle[Anim::frame+1], pos);
	MV1SetPosition(ModelHandle[Anim::frame+2], pos);


	DrawFormatString(0, 20, 0xffffff, "X=%.0f,Y=%.0f,Z=%.0f,", pos.x, pos.y, pos.z);



}


