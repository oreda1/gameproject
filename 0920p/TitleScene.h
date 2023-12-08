#pragma once
#include "Scene.h"
#include "TitleScene.h"
#include "Geometry.h"
#include <list>
class File;
/// <summary>
/// タイトルシーンクラス
/// </summary>
class TitleScene : public Scene
{

private:
	struct Bomb
	{
		int handle;
		int frame=0;
		bool isDead = false;
		Position2 pos;
		Bomb(int h, const Position2& p) :handle(h), pos(p) {}

	};


	std::list<Bomb>bombs_;
	enum class RotatoDir
	{
		clock_wise,
		counter_cu
	};
	struct BombSetter
	{
		Position2 pos;
		Vector2 vel;


		void CheckWall();
		void Rotate();

		
	};


	std::shared_ptr<File>titleImg_;
	std::shared_ptr<File>buttonsImg_;
	std::shared_ptr<File>explosionImg_;
	std::shared_ptr<File>coinSE_;

	int frame_ = 0;

	int faseFrame_ = 0;

	int button;

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

