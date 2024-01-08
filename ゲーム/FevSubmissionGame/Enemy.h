#pragma once
class Enemy
{
public:
	void Draw();
	void enemymove();
	
	

	//エネミー初期位置
	int enemyX=100;
	int	enemyY=100;
	//エネミーの移動処理
	int enemy_moveX;
	int enemy_moveY;
};

