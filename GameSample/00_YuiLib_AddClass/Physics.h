// 2024 Takeru Yui All Rights Reserved.
#pragma once

namespace YuiLib{

class Collidable;

/// <summary>
/// �����������ǂ�
/// </summary>
class Physics final
{
public:
	// �Փ˕��̓o�^�E�o�^����
	void Entry(const Collidable* collidable);
	void Exit(const Collidable* collidable);

	void Update();	// �X�V
};

}
