#include "SceneManeger.h"
#include "DxLib.h"

void SceneManeger::Draw()
{
	
	
}
void SceneManeger::ChangeScene(std::shared_ptr<Scene> nextScene)
{

}
void SceneManeger::PushScene(std::shared_ptr<Scene> scene)
{
}
void SceneManeger::PopScene()
{
	
}
void SceneManeger::Update()
{
	scene_->Update();
} 