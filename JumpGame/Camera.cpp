#include "Camera.h"

Camera::Camera()
{
  
}
Camera::~Camera()
{
}

void Camera::Watch()
{
	//pos = VGet(10, 10, 10);
	//SetCameraPositionAndAngle(VGet(0.0, 0.0, 0.0), pos.x, pos.y, pos.z);
	// �傫��0.5�̃}�b�v�`�b�v���A�ۑ蓖����StageData1ColNum��(16)�z�u����
	// �v���C���[�̒n�ʂ�Y�ʒu��0�Ƃ������̂ŁA�n�㕔�̃}�b�v�`�b�v�̐��͓���炵���ʒu�Œ���
	// ���̐^�񒆂ɕ\������̂Ŕ������v�Z�ŏo��
	// �v���C���[��X���W�ɂ͒Ǐ]�������̂�player��X���g��
	VECTOR playerPos = player.GetPos();
	VECTOR cameraPos = VGet(playerPos.x, Map::ChipSize * (16 - 2) * 0.5f, playerPos.z - 10.0f);

	// �������鎋�_�́A�J�����ƕ��s�ɂ܂�����z=0�n�_
	VECTOR lookPos = VGet(cameraPos.x, cameraPos.y, 0.0f);
	// �J�����Ɉʒu�𔽉f.
	SetCameraPositionAndTarget_UpVecY(pos, lookPos);
}
