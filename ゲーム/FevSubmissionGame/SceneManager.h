#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	typedef enum Scene
	{
		Title,
		S_Option,
		Playing,
		Return_Title,
		End
	};

//現在のシーンを判別
Scene NowScene;



void DivideScene();
void ChangeScene();
void DecisionScene();

void ExplanationScene();




//SceneManager::sceneitem NowScene;



};

