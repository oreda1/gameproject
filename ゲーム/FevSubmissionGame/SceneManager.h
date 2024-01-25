#pragma once
class SceneManager
{
public:
	SceneManager();
	virtual~SceneManager();

	typedef enum Scene
	{
		Title,
		S_Option,
		Playing,
		End
	}sceneitem;

void DivideScene();
void ChangeScene();
void DecisionScene(sceneitem NextScene);



//static
 SceneManager::sceneitem NowScene = SceneManager::sceneitem::Title;



};

