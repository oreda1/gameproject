#include "Player.h"
Player::Player():
	ModelHandle(),
	pos(VGet(0.0f, 0.0f, 0.0f))
{
	ModelHandle = MV1LoadModel("Asset/PlayerModel.mv1");
}
void Player::Init()
{
	pos;
	ModelHandle;
}

void Player::Draw()
{
	
	MV1DrawModel(ModelHandle);

}

void Player::Update()
{
	
	MV1SetPosition(ModelHandle, pos);
	//DrawPolygon3D(&ver[0], 6, ModelHandle,true);

}

void Player::Delete()
{
	MV1DeleteModel(ModelHandle);
	
}
