#include "Input.h"
#include <DxLib.h>
#include <string>
#include <algorithm> 


using namespace std;

namespace {
	struct KeyConfHeader
	{
		char id[4] = "kyc";
		float version = 1.0f;
		size_t dataCount=0;
	};
}

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
	lastKeyState_ = keyState_;//前のフレームの
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
	FILE* fp=nullptr;
	//fopen_s(&fp, path.c_str(), "wb");
	auto err = fopen_s(&fp, path.c_str(), "wb");

	KeyConfHeader header;
	header.dataCount = commandTable_.size();
	fwrite(&header, sizeof(header), 1, fp);

	//データ本体を書き込んでいく
	for (const auto&cmd:commandTable_)
	{
		const auto& commandStr = cmd.first;
		uint8_t size = cmd.first.size();
		fwrite(&size, sizeof(size), 1, fp);//コマンド文字列のバイト数を書き込む
		fwrite(commandStr.data(), commandStr.size(), 1, fp);//文字列の書き込み
		uint8_t ioTypeSize = cmd.second.size();//対応する入力
		uint8_t ioTypeSize = inputDate.size();//対応する入力の数(基本はキーボードとパッドの2)
		for (const auto&input:inputdate)//2を書き込み
		{
			const auto& type = input.first;
			const auto& state = input.second;
			fwrite(&type, sizeof(type), 1, fp);
			fwrite(&state, sizeof(state), 1, fp);


		}

	}
	
	fclose(fp);
}

void Input::Load(const std::wstring& path)
{
	auto handle = FileRead_open(path.c_str());
	KeyConfHeader header;
	FileRead_read(&header,sizeof(header),handle);

	//データの読み込み
	for (int i = 0; i < header.dataCount; i++)
	{
		uint8_t cmdStrSize = 0;
		FileRead_read(&cmdStrSize, sizeof(cmdStrSize), handle);
		std::string cmdstr;
		cmdstr.resize(cmdStrSize);
		FileRead_read(cmdstr.data(), cmdstr.size() * sizeof(char), handle);
		auto& command = commandTable_[cmdstr];

		uint8_t inputTypeSize;
		FileRead_read(&inputTypeSize, sizeof(inputTypeSize), handle);
			for (int j = 0; j < inputTypeSize; j++)
			{
				InputType type;
				int state;
				FileRead_read(&type, sizeof(type),handle);//種別を読み込み
				FileRead_read(&state, sizeof(state),handle);//実際の入力ステート情報を読み込む
				command[type] = state;//コマンドに反映させる
			}

	}

	FileRead_close(handle);
}

