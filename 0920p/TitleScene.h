#pragma once
#include "Scene.h"
#include "TitleScene.h"
/// <summary>
/// タイトルシーンクラス
/// </summary>
class TitleScene : public Scene
{

private:
	std::shared_ptr<File>titleImg_;
	std::shared_ptr<File>buttonsImg_;

	void NomalDraw();

	
   using DrawFunc_t =void(TitleScene::*)();
   DrawFunc_t updateFunc_;

	//描画メンバ巻子ポインタ
	using DrawFnuc_t = void(TitleScene::*)();
	DrawFunc_t drawFunc_;

public:
	TitleScene(SceneManeger&maneger);
	~TitleScene();
    
	  void FadeInuUpdate(Input&);
	  void NormalUpdate(Input&);
	  void FadeOutUpdate(Input&);

	  void FadeDraw();
	  void NormalDraw();


	void Update(Input& input);
	void Draw();
};

