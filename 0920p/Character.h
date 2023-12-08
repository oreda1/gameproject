#pragma once
#include "Actor.h"
class Character :
	public Actor
{
private:
	bool isTurn_ = false;
	int currentframeAnime = 5;

public:


	virtual ~Character();
	void ChangeAnimetion();
    void Update();
	void Draw();


};

