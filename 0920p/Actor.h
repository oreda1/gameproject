#pragma once
class Actor
{

public:

	
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void SetPosition();
};

