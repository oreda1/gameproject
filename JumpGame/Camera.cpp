#include "Camera.h"
Player player;
Enemy enemy;

Camera::Camera()
{
	SetCameraNearFar(0.1f, 1000.0f);
	Camera_Pos = VGet(1, 50, 1);
	
}
Camera::~Camera()
{

}

void Camera::Watch()
{
	SetCameraPositionAndAngle(VGet(0, 0, 0), 0, 0, 0);
	SetCameraPositionAndTargetAndUpVec(Camera_Pos,Camera_Pos, Camera_Pos);


}

void Camera::Update()
{
	if (PAD_INPUT_UP||KEY_INPUT_L)
	{
		Camera_Pos.x += 2;
	}
	if (PAD_INPUT_DOWN||KEY_INPUT_R)
	{
		Camera_Pos.x -= 2;
	}


}




