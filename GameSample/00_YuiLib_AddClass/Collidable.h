// 2024 Takeru Yui All Rights Reserved.
#pragma once

namespace YuiLib {

class Rigidbody;

/// <summary>
/// �Փ˂ł������
/// </summary>
class Collidable
{
public:
	void OnCollide();	// �Փ˂����Ƃ�

private:
	Rigidbody rigidbody;
};

}

