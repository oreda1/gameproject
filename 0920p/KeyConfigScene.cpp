#include "KeyConfigScene.h"
#include "Input.h"
#include <DxLib.h>
#include "Application.h"
#include "KeyConfigScene.h"

constexpr int appear_interval = 30;
constexpr int menu_margin = 60;

void KeyConfigScene::AppearUpdate(Input&)
{
}

void KeyConfigScene::NoramlUpdate(Input&input)
{
	if (input.IsTriggered("OK"))
	{
		

	}

	
}

void KeyConfigScene::DisappearUpdate(Input&)
{
}

void KeyConfigScene::ExpandDraw()
{
}

void KeyConfigScene::NomalDraw()
{

}

void KeyConfigScene::DrawCommandList()
{ 
	constexpr auto& cmdTable = input.GetCommandTable();
	int x = menu_margin + 50;
	int y = menu_margin + 50+10;
	int idx = 0;
	constexpr unsigned int defalut_color = 0xffff;

	
	for (const auto&cmd:)
	{
		std::wstring
		 
	}

	
}

void KeyConfigScene::CommitCurrentKeySetting()
{
}

void KeyConfigScene::Update(Input& input)
{
}
void KeyConfigScene::Draw()
{
}

void KeyConfigScene::EditUpdate(Input& input)
{
	if (input.IsTriggered("OK"))
	{
		isEditingNow

	}


	char keystate[256];
	GetHitKeyStateAll(keystate);
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);
	int lineNo = 0;
	for (auto& cmd:keyCommandTable_)
	{
		if (currentLineindex==lineNo)
		{
			bool isPressKey = false;
			for (int i = 0;  i< 256; ++i)
			{
				if (keystate[i])
				{
					cmd.second[InputType::keybd] = i;
					isPressKey = true;
					break;
				}
				

			}
			if (padstate)
			{
				cmd.second[InputType::pad] = padstate;
			}
			break;
		}
		++lineNo;
	}
}

