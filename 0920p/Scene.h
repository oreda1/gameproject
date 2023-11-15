#pragma once
#include "Scene.h"
#include "SceneManeger.h"

class Input;
/// <summary>
/// �V�[�����N���X
/// �����ȃV�[���̊�ɂȂ�N���X
/// </summary>
class Scene
{
protected:
	SceneManeger& maneger_;
	

public:
	/// <summary>
	/// ��������SceneManeger
	/// </summary>
	/// <param name="input"></param>
	virtual void Update(Input&input) = 0;
	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw() = 0;

	
	virtual void Scene(SceneManeger& manager);

};

