#include "Camera.h"

Camera::Camera()
{
	
	SetCameraNearFar(0.1f, 100.0f);

	pos = VGet(0, 0, 0);
}
Camera::~Camera()
{
}

void Camera::Watch()
{

	pos = VGet(10, 10, 10);
	//SetCameraPositionAndAngle(VGet(0.0, 0.0, 0.0), pos.x, pos.y, pos.z);
	// �傫��0.5�̃}�b�v�`�b�v���A�ۑ蓖����StageData1ColNum��(16)�z�u����
	// �v���C���[�̒n�ʂ�Y�ʒu��0�Ƃ������̂ŁA�n�㕔�̃}�b�v�`�b�v�̐��͓���炵���ʒu�Œ���
	// ���̐^�񒆂ɕ\������̂Ŕ������v�Z�ŏo��
	// �v���C���[��X���W�ɂ͒Ǐ]�������̂�player��X���g��
	VECTOR PlayerPos = Camera::GetPos();
	VECTOR CameraPos = VGet(PlayerPos.x, ChipSize * (16 - 2) * 0.5f, PlayerPos.z - 10.0f);

	// �������鎋�_�́A�J�����ƕ��s�ɂ܂�����z=0�n�_
	VECTOR lookPos = VGet(CameraPos.x, CameraPos.y, 0.0f);

	pos = CameraPos;
	// �J�����Ɉʒu�𔽉f.
	//SetCameraPositionAndTarget_UpVecY(pos,lookPos);
}
