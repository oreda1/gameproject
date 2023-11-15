#pragma once
#include "Scene.h"
#include "SceneManeger.h"

class Input;
/// <summary>
/// シーン基底クラス
/// いろんなシーンの基になるクラス
/// </summary>
class Scene
{
protected:
	SceneManeger& maneger_;
	

public:
	/// <summary>
	/// 生成時にSceneManeger
	/// </summary>
	/// <param name="input"></param>
	virtual void Update(Input&input) = 0;
	/// <summary>
	/// シーンの描画
	/// </summary>
	virtual void Draw() = 0;

	
	virtual void Scene(SceneManeger& manager);

};

