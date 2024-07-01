#include "Camera.h"



void Camera::Done()
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
