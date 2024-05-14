#include "Camera.h"


Camera::Camera()
{
	SetCameraNearFar(1.0f, 1000.0f);

}

void Camera::Look()
{
	SetCameraPositionAndTargetAndUpVec(pos,pos, lookpos);
}
