#pragma once
class BaseScene
{
public:
	BaseScene() {};
	virtual~BaseScene(){};
	virtual void Init()abstract;
	virtual void Update()abstract;
	virtual void Draw()abstract;


private:

};



