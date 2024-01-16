#include "Character.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "GameScene.h"
#include <math.h>


Character::Character()
    {
    m_gamescene = new GameScene;
    m_gamescene = nullptr;
    }

    Character::~Character()
    {
        delete m_gamescene;
        m_gamescene = nullptr;
    }

    void Character::Init()
    {
       

    }

    void Character::Draw()
    {
        PlayerHandle = LoadGraph("Cockroach.png");

       
        for (int x = 0; x < PlayerPerChipX; x++)
        {
            for (int y = 0; y < PlayerPerChipY; y++)
            {
                //キャラクターチップ
                int PlayerX = PlayerPerChipX * x;
                int PlayerY = PlayerPerChipY * y;
                if (MakePlayer[y][x] == 1)
                {
                    
                    DrawRectGraph(start_posX,start_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
                }



            }
        }



    }
    

    void Character::Move(GameScene& gamescene)
    {
        JumpFlag = true;
        gpUpdateKey();
        if (titleP.Key[KEY_INPUT_UP])
        {
            //--Character_pos.y;
            //Character_pos = VAdd(Character_pos,VGet(0,-10,0));
            start_posY =start_posY-CharaMoveSpeed;
            if (start_posY<0)
            {
                start_posY = 0;
            }

            
        }
        
         
        if (titleP.Key[KEY_INPUT_SPACE]==1)
        {
            start_posY -= JumpSpeed;
             
            if (JumpFlag==false)
            {
                JumpSpeed += 1;
            }
            if (start_posY==368)
            {
                JumpFlag == true;
            }
            
           

            
         
        }
        //画面の比率320*240
        //画像の比率384*256
        if (titleP.Key[KEY_INPUT_DOWN])
        {
            start_posY = CharaMoveSpeed + start_posY;
            FallCollision();

        }

        if (titleP.Key[KEY_INPUT_RIGHT])
        {
         
           start_posX = CharaMoveSpeed + start_posX;
           PlayerChipSizeX = 64;
           PlayerChipSizeY = 64;
           

        }

        if (titleP.Key[KEY_INPUT_LEFT])
        {
            start_posX = start_posX - CharaMoveSpeed;
            if (start_posX < 0)
            {
                start_posX = 0;
                start_posY = start_posY;
            }
            PlayerChipSizeX = 32;
            PlayerChipSizeY = 32;
        }

        FallCollision();

    }

    void Character::Update()
    {
        
    }

    void Character::Collision()
    {
    }

    void Character::FallCollision()
    {
        if (start_posY >= 496)
        {
            start_posX = 160;
            start_posY = 120;
        }
        if (start_posY > 368 && start_posX <= 256)
        {
            start_posY = 368;
        }

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







