#include "Character.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "Map.h"
#include <memory>
#include "Enemy.h"


Character::Character():
JumpFlag(false),
exceedY(370),
not_exceedY(0)
    {
  
    }

    Character::~Character()
    {
     
    }

    //キャラクターを描画する処理
    void Character::Draw()
    {
     
        DrawRectGraph(Player_posX,Player_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
        DrawFormatString(550, 20, 0xff00ff, "x=%d,y=%d", Player_posX, Player_posY);


        
         //キャラクターチップ        
                                  
           DrawRectGraph(Player_posX,Player_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
     
        //DrawFormatString(550, 20, 0xff00ff, "x=%d,y=%d", Player_posX, Player_posY);


    }
    

    //キャラクターを描画する処理
    void Character::Move(Map& gamescene)
    {
        
        gpUpdateKey();
        Player_posY += Jumpgravity;
        JumpFlag = true;
        if (titleP.Key[KEY_INPUT_SPACE]==1&&JumpFlag==true)
        {
            Player_posY -= JumpSpeed + JumpInitialVelocity - Jumpgravity;
           
        }
        

        //画面の比率320*240
        //画像の比率384*256
        if (titleP.Key[KEY_INPUT_DOWN])
        {
            Player_posY = CharaMoveSpeed + Player_posY;
            FallCollision();

        }

        FallCollision();

    }

    //キャラクター
    void Character::FallCollision()
    {
        if (Player_posY>exceedY)
        {
            Player_posY = exceedY;
        }
        if (Player_posY<not_exceedY)
        {
            Player_posY = not_exceedY;
        }

    }

    void Character::Effect()
    {
    }

    int Character::gpUpdateKey() {
        char tmpkey[256]; //現在のキー入力状態を格納する
        GetHitKeyStateAll(tmpkey); //すべてのキー入力状態を得る
        for (int i = 0; i < 256; i++) {	//i番のキーコードに対応するキーが押されていたら
            if (tmpkey[i] != 0) {
                titleP.Key[i]++;				//加算
            }
            else {						//押されていなければ
                titleP.Key[i] = 0;
            }

        }
        return 0;
    }

    //Artificial Providence 様
    //ぴぽや倉庫様
