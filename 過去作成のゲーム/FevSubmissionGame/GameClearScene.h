#pragma once
class GameClearScene
{
public:
	GameClearScene();
	~GameClearScene();

	void Init();
	void Draw();
	void Update();
	void End();

	bool GameClear = false;
	

};



