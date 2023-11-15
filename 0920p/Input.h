#pragma once
#include "Scene.h"
#include <map>
#include <string>
#include<unordered_map>
#include "KeyConfigScene.h" 
enum class InputType
{
	keybd,
	pad,
	mouse

};

using InputTable_t = std::map<std::string, std::map<InputType, int>>;
class KeyConfigScene;


class Input //:public Scene
{
	friend KeyConfigScene;
	
private:


	InputTable_t commandTable_;
	std::vector<std::string>
	


	//std::map <std::string, int>commandTable_;
	std::map<std::string, bool>inputDate_;
	std::map<std::string, bool>lastinputDate_;
	
		//std::array<char, 256>keyState_
		//std::array<char, 256>keyState_;

		


public:
	Input();



	void Update();


	bool IsTriggered(const char* command)const;
	bool IsPressing(const char* command)const;
	bool IsReleased(const char* command)const;
	

	/// <summary>
	/// 現在のキーコンフィグをファイルに保存する
	/// </summary>
	/// <param name="path"></param>
	void Save(const std::string& path);
		

		
	


};

