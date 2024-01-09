#include "Character.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include <math.h>



Character::Character()
    {
        
    }

    Character::~Character()
    {
    }

    void Character::Init()
    {


    };

    void Character::Draw()
    {
       PlayerHandle = LoadGraph("Cockroach.png"); 
        for (int y= 0; y < PlayerPerChipY; y++)
        {
            for (int x= 0; x < PlayerPerChipX; x++)
            {
                int PlayerChipDate = MakePlayer[y][x];

                //キャラクターチップ
                int PlayerX = PlayerPerChipX * x;
                int PlayerY = PlayerPerChipY * y;
               
                DrawGraph(PlayerX, PlayerY, PlayerHandle, false);

            }
        }
        
    }


    void Character::Move()
    {
        gpUpdateKey();
        if (titleP.Key[KEY_INPUT_UP])
        {
            start_posY =start_posY-CharaMoveSpeed;
            if (start_posY<0)
            {
                start_posY = 0;
            }

            
        }

        CharaY = start_posY;
        Jumpgravity = -1;
        if (titleP.Key[KEY_INPUT_SPACE])  
        {
            
            Jumpgravity = -10;
            start_posY += (CharaY - start_posY) + Jumpgravity;
                  
        }
       

        
        
        //画面の比率320*240
        //画像の比率384*256
        if (titleP.Key[KEY_INPUT_DOWN])
        {
            start_posY = CharaMoveSpeed + start_posY;
            if (start_posY>=496)
            {
                start_posX = 160;
                start_posY = 120;
            }

        }

        if (titleP.Key[KEY_INPUT_RIGHT])
        {
         
           start_posX = CharaMoveSpeed + start_posX;

        }

        if (titleP.Key[KEY_INPUT_LEFT])
        {
            start_posX = start_posX - CharaMoveSpeed;
            if (start_posX < 0)
            {
                start_posX = 0;
                start_posY = start_posY;
            }
        }



    }

    void Character::Update()
    {
        
    }

    void Character::Collision()
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







