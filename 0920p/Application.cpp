#include "Application.h"
#include <DxLib.h>
#include "SceneManeger.h"
#include <cassert>

namespace {
	constexpr int screen_width = 640;
	constexpr int screen_height = 480;

}
int MyLoadGraph(const TCHAR* path) {
	int handle = LoadGraph(path);
	assert(handle > 0);
	return handle;
}
Application::Application() {
	

}

void Application::Terminate()
{
}

bool
Application::Init()
{
	ChangeWindowMode(true);
	SetWindowText(L"�Q�[��");
	if (DxLib_Init()==-1)
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	return true;

}






void 
Application::Run()
{
	
	

}
