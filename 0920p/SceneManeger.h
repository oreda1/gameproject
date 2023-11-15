#pragma once
#include "Scene.h"
#include <memory>
class SceneManeger : public Scene
{
private:

	//Scene* scene=nullptr;
public:
	 ~SceneManeger();


	void Update();

	void Draw();

	void ChangeScene(std::shared_ptr<Scene>nextScene);

	void PushScene(std::shared_ptr<Scene>scene);

	void PopScene();
};

