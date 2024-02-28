#pragma once
class SceneBase
{
public:
	SceneBase(){};
	virtual~SceneBase(){};

	virtual void Init()=0;
	virtual SceneBase* Update()=0;
	virtual void Draw()= 0;
	virtual void End()= 0;

};



