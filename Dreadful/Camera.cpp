#include "Camera.h"

void Camera::Done()
{
	SetCameraNearFar(1, 1000);

}

void Camera::Update()
{

	
}

void Camera::Title()
{

}

VECTOR Camera::Light()
{
	ChangeLightTypeDir(VGet(-1.0f,0.0f,0.0f));
	return VECTOR();
}
