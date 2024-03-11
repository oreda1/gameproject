#pragma once
class BaseScene
{
public:
	BaseScene() {};
	virtual~BaseScene(){};
	virtual void Init();
	virtual void Update();
	virtual void Draw();


private:

};



