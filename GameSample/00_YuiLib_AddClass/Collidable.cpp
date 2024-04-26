// 2024 Takeru Yui All Rights Reserved.
#include "DxLib.h"
#include "Rigidbody.h"
#include "Collidable.h"

using namespace YuiLib;

/// <summary>
/// 衝突したとき
/// </summary>
void Collidable::OnCollide()
{
	printfDx("OnCollide！");
}
