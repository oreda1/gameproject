#include "Camera.h"

Camera::Camera()
{
  
}
Camera::~Camera()
{
}

void Camera::Watch()
{
	pos = VGet(10, 10, 10);
	SetCameraPositionAndAngle(VGet(0.0, 0.0, 0.0), pos.x, pos.y, pos.z);
}
