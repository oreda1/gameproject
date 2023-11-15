#include "Input.h"
#include <DxLib.h>
#include <string>
#include <algorithm> 


using namespace std;

const InputTable_t Input::GetCommandTable()const
{
	InputTable_t ret = commandtable_;
	for (const auto& ex : )
	{
		ret.erase(ex);
	}
		
}



Input::Input()
{

}
void Input::Update()
{
	
	
	
	
	char keystete[256];
	GetHitKeyStateAll(keystate);
	lastKeyState_ = keyState_;//‘O‚ÌƒtƒŒ[ƒ€‚Ì
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);
	for (const auto&cmd:commandTable_)
	{
		auto& input = inputDate_[cmd.first];

		input = false;
		if(const auto& hardI0.second)
		{
			if (keystete[hardI0.second])
			{
              input = true;
		     	break;
			}
			
		}
		else if (hardI0.first=InputType::pad)
		{
			if (padstate&hardI0.second)
			{
				input = true;
				break;
			}

		}



	}
	
}

bool Input::IsTriggered(const char* command)const
{
	auto it = lastinputDate_.find(command);




}

bool Input::IsPressing(const char* command) const
{
	return false;
}

bool Input::IsReleased(const char* command) const
{
	return false;
}

void Input::Save(const std::string& path)
{
	File* fp;
	fopen_s(&fp, path.c_str(), "wb");
}
