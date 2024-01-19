#pragma once
class SceneManager
{
	SceneManager();
	~SceneManager();

	enum Scene
	{
		Title,
		Playing,
		SecondScene,
		End
	};


void ChangeScene(Scene scene);
void SceneUpdate();
void SceneDraw();






};

