#pragma once
#include "Scene.h"
class PauseScene :
	public Scene
{
private:
	using UpdateFunc_T = void(PauseScene::*)(Input& input);
	UpdateFunc_T updateFunc_;

	using DrawFunc_t = void(PauseScene::*)();
	DrawFunc_t drawFunc_;

	void AppearUpdate(Input&);
		void NoramlUpdate(Input&);
		void DisappearUpdate(Input&);





	//�X�V�֐�
	void Update(Input& input);
	void Draw();



};

