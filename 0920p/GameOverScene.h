#pragma once
#include "Scene.h"
class GameOverScene :
    public Scene
{
private:
    int handle_ = 0;
    int flame_ = 0;

    using UpdateFunc_t = void(GameOverScene::*)(Input&);
    using DrawFunc_t = void(GameOverScene::*)();
    UpdateFunc_t updateFunc_ = nullptr;
    DrawFunc_t drawFunc_ = nullptr;

    //çXêVèÛë‘
    void FadeDraw();
    void NormalDraw();

};

