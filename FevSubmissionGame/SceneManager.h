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

//���݂̃V�[���𔻕�
Scene NowScene;



bool DivideScene();
bool ChangeScene();
void DecisionScene();

void ExplanationScene();


//SceneManager::sceneitem NowScene;



};

