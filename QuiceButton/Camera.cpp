#include "Camera.h"

Camera::Camera()
{
	SetCameraNearFar(1.0f, 1000.0f);
	pos = VGet(0.0f,300.0f,-150.0f);
}

void Camera::Init()
{
	
	
	
}

void Camera::Look(Player& player)
{
	SetCameraPositionAndTarget_UpVecY(pos,player.GetPlayerPos());
	DrawFormatString(0,0,0xffffff,"ÉJÉÅÉâà íuÅ@X=%.0f,Y=%.0f,Z=%.0f",pos.x,pos.y,pos.z);

}

void Camera::ViewpointShift()
{

	if (KEY_INPUT_RIGHT)
	{
		pos.x+=10;
	}
	if (KEY_INPUT_LEFT)
	{
		pos.x -= 10;
	}

	
}
