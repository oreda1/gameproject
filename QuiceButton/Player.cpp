#include "Player.h"
Player::Player():
	ModelHandle(),
	pos(VGet(100.0f, 100.0f, 100.0f))
{
	
}
void Player::Init()
{
	pos;
	ModelHandle;
}

void Player::Load()
{
	ModelHandle = MV1LoadModel("Asset/PlayerModel.mv1");
}

void Player::Draw()
{
	
	MV1DrawModel(ModelHandle);

}

void Player::Update()
{
	
	MV1SetPosition(ModelHandle, pos);
	

}

void Player::Delete()
{
	MV1DeleteModel(ModelHandle);
	
}
