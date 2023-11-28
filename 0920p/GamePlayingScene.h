#pragma once
#include "Scene.h"
class GamePlayingScene :public Scene
{
private:
	int handle_;
	int flame_;
	using UpdateFunk_t = void(GamePlayingScene::*)(Input&);
	using DrawFunc_t = void(GamePlayingScene::*)();

	

	public
      GamePlayingScene(SceneManeger& mgr);

	void Update(Input& input);
	void Draw();
};

