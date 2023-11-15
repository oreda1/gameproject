#include "PauseScene.h"
#include "Input.h"
#include "DxLib.h"
#include "Application.h"

constexpr int appear_interval = 60;

void PauseScene::Update(Input&input)
{
	
	

}

void PauseScene::Draw()
{
	Application& app = Application::GetInstance();
	const auto& size() = app.GetWindowSize();

	int halfHeight(size.h - 100) / 2;
	int centerY = size.h / 2;

	float weightt = static_cast<float>(flame_) / 60.0fl;

	SetDrawBlendMode(DX_BLENDMODE_MUL, 255);

	
}
