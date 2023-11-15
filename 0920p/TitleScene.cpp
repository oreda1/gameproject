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


TitleScene::TitleScene(SceneManeger& maneger):Scene(maneger)
{

	handle_t = LoadGraph(_T(""));
	

	std::ostringstream oss;
	oss << "TitleScene handle=" << std::hex << "frame=" << std::dec << ",FPS=" << std::fixed << std:: << GetFPS();
	OutputDebugStringA(oss.str().c_str());

}

TitleScene::~TitleScene()
{
	
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
