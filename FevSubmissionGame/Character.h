#pragma once
#include "GameScene.h"
#include "BaseNuber.h"
class  Character
{
public:
	 Character();
	~Character();

	void Init();
	void Draw();
	void Move(CharaMove& cara_move);
    void Update();

	//キャラの最初のポジション
	int start_posX;
	int start_posY;

	
	
private:



	bool sceneX =GameWidth;
	
	

	
	
	
	
	
};



