#include "TitleScene.h"
#include "Input.h"
#include "SceneManeger.h"
#include "GamePlayingScene.h"
#include<DxLib.h>
#include <cassert>
#include<sstream>
#include <iomanip>

void TitleScene::Update(Input& input)
{
	
	if (Input.IsTriggered("OK")) {
	
	}







}

void TitleScene::Draw()
{
	DrawString(100, 100, L"TitleList Scene");
}


void TitleScene::NomalDraw()
{
	DrawString(100, 100, _T("Title Scene"), 0xffffff);
	DrawGraph(100, 100, titleImg_->GetHandle(), true);
	int x = abs((frame_ + 640) % (640 * 2) - 640);
	DrawCircle(x, 240, 10, 0xffaaaa, true);

}

TitleScene::TitleScene(SceneManeger& maneger):Scene(maneger)
{
	

	handle_t = LoadGraph(_T(""));
	

	std::ostringstream oss;
	oss << "TitleScene handle=" << std::hex << "frame=" << std::dec << ",FPS=" << std::fixed << std:: << GetFPS();
	OutputDebugStringA(oss.str().c_str());


}

TitleScene::~TitleScene()
{

	if (frame_%5==0)
	{
		Position2 pos = { (float)x,320.0f };
	}
	
  //bombs_.remove_if([](const))
}

void TitleScene::FadeInuUpdate(Input&)
{
	
}

void TitleScene::NormalUpdate(Input&)
{
	if (Input.Istriggerd("OK"))
	{
		
	}
	
	
}

void TitleScene::FadeOutUpdate(Input&)
{
	frame_++;
	if (frame_>=60)
	{
	        
	}

}

void TitleScene::FadeDraw()
{
	
	DrawString(100, 100, L"Title Scene", );
	DrawGraph(100, 100, handle_,true );
}

void TitleScene::NormalDraw()
{
}

void TitleScene::BombSetter::CheckWall()
{
}

void
TitleScene::BombSetter::Rotate()
{

}