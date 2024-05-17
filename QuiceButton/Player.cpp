#include "Player.h"
Player::Player():
	ModelHandle(),
	pos(VGet(0.0f, 0.0f, 0.0f))
{
	
}
void Player::Init()
{
	

}

void Player::Load()
{
	ModelHandle[0] = MV1LoadModel("Asset/Player.mv1");
	ModelHandle[1] = MV1LoadModel("Asset/Player_PoseT.mv1");
	ModelHandle[2] = MV1LoadModel("Asset/Player_Prone_t.mv1");

	Index[0] = MV1AttachAnim(ModelHandle[0], 0, 0);
	Index[1] = MV1AttachAnim(ModelHandle[1], 1, 1);
	Index[2] = MV1AttachAnim(ModelHandle[2], 2, 2);


	




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
	

	

}

void Player::Delete()
{
	MV1DeleteModel(ModelHandle[0]);
	
}
