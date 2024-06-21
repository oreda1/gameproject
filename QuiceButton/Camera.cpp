#include "Camera.h"

Camera::Camera()
{
	SetCameraNearFar(1.0f, 1000.0f);
	pos = VGet(0.0f, 0.0f, 0.0f);
	lookpos= VGet(0.0f, 1.0f, 0.0f);



}

void Camera::Init()
{
	
	
	
}

void Camera::Look(Player& player)
{
	auto playerpos=static_cast<Player*>(_player);
	auto _lookpos = VSub(player.GetPlayerPos(), VGet(0, 0, 10));

	//SetCameraPositionAndTargetAndUpVec(player.GetPlayerPos(),_lookpos,pos);
	DrawFormatString(0, 0, 0xffffff, "ÉJÉÅÉâà íuÅ@X=%.0f,Y=%.0f,Z=%.0f", pos.x, pos.y, pos.z);

}

void Camera::ViewpointShift()
{

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x += 1;

	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x -= 1;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.z += 10;

	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.z -= 10;

	}



}
