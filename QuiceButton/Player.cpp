#include "Player.h"
Player::Player():
	ModelHandle(),
	pos(VGet(0.0f, 0.0f, 0.0f))
{
	
}
Player::~Player()
{
	MV1DeleteModel(ModelHandle[0]);
}
void Player::Init()
{

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


