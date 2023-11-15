#pragma once
#include "Scene.h"
#include <unordered_map>
#include "Input.h"
class KeyConfigScene :public Scene
{


private:

	int frame_=0;
	 
	int currentLineindex;
	
	std::unordered_map<int, std::string>keynameTable_;
	std::unordered_map<int, std::string>padnameTable_;
	using UpdateFunc_T = void(KeyConfigScene::*)(Input& input);
	UpdateFunc_T updateFunc_;


	Input& input;
	using DrawFunc_t = void(KeyConfigScene::*)();
	DrawFunc_t drawFunc_;

	void AppearUpdate(Input&);
	void NoramlUpdate(Input&);
	void DisappearUpdate(Input&);

	void ExpandDraw();
	void NomalDraw();

	void DrawCommandList();
	void CommitCurrentKeySetting();
public:
	KeyConfigScene(SceneManeger& managerm, Input& input) :Scene(maneger_),input_(input)
	{

	}
	void Update(Input& input);
	void Draw();

	void EditUpdate(Input& input);

};

