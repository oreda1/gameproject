#include "DxLib.h"
#include <cassert>
/*#include"DxLib.h"
#include <cassert>

void sub(int& left, const int& right)
{
	left = right;
}
void Function() 
{
	int j = 0;
	for (int i = 0; i < 10000; i++)
	{
		sub(j, i);
	}
	

}
int LoadGraph(const wchar_t*path)
{
	int handle=LoadGraph(path);
	assert(handle);

}

int WINAPI  WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(true);

	if (DxLib_Init() == -1)
	{
		return -1;

	}
	//実は表示される描画先には2枚のスクリーンがあります
	//これを高速でフリップ(入れ替え)を行うことで
	//画面のちらつきをなくしています
	//SetDrawScreen等の関数はDXLib_Init()後じゃないと読み込めない
	
	int a[] = { 1,3,4,8,2,5,3,6,2 };
	auto result=SetDrawScreen(DX_SCREEN_BACK);
	for (int i = 0; i < 10000; i++)
	{
		int j;
		j = i;
	}
	while (ProcessMessage()!=-1)
	{
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
}
*/

