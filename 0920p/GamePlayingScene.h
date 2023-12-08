#pragma once
#include "Scene.h"
class File;

class GamePlayingScene :public Scene
{
private:
	float fps_ = 0.0f;
	int handle_;
	int flame_;
	using UpdateFunk_t = void(GamePlayingScene::*)(Input&);
	using DrawFunc_t = void(GamePlayingScene::*)();



	

public:
	GamePlayingScene(SceneManeger& mgr);
      ~GamePlayingScene();

	void Update(Input& input);
	void Draw();
};

