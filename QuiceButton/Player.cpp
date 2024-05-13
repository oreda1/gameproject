#include "Player.h"
void Player::Init()
{
  ModelHandle=MV1LoadModel("ƒ‚ƒfƒ‹/rp_eric_rigged_001_zup_a.mv1");
}

void Player::Draw()
{
	
	MV1DrawModel(ModelHandle);
}

void Player::Update()
{
}

void Player::Delete()
{
	MV1DeleteModel(ModelHandle);
	
}
