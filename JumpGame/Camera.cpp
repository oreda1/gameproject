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
	// 大きさ0.5のマップチップを、課題当初のStageData1ColNum個(16)配置する
	// プレイヤーの地面のY位置を0としたいので、地上部のマップチップの数は二つ減らした位置で調整
	// その真ん中に表示するので半分を計算で出す
	// プレイヤーのX座標には追従したいのでplayerのXを使う
	VECTOR playerPos = player.GetPos();
	VECTOR cameraPos = VGet(playerPos.x, Map::ChipSize * (16 - 2) * 0.5f, playerPos.z - 10.0f);

	// 注視する視点は、カメラと平行にまっすぐz=0地点
	VECTOR lookPos = VGet(cameraPos.x, cameraPos.y, 0.0f);
	// カメラに位置を反映.
	SetCameraPositionAndTarget_UpVecY(pos, lookPos);
}
