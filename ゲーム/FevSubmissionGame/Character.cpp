#include "Character.h"
#include "DxLib.h"
#include "BaseNumber.h"
#include "Map.h"
#include <memory>
#include "Enemy.h"



Character::Character()
    {
    //m_Enemy = new Enemy;
    //m_Enemy = nullptr;

    // m_map = new Map;
    // m_map = nullptr;
    }

    Character::~Character()
    {
      /*  delete m_Enemy;
        m_Enemy = nullptr;

        delete m_map;
        m_map = nullptr;*/
    }

    void Character::Init()
    {
       

    }

    void Character::Draw()
    {
       

        for (int x = 0; x < PlayerPerChipX; x++)
        {
            for (int y = 0; y < PlayerPerChipY; y++)
            {
                //�L�����N�^�[�`�b�v
                int PlayerX = PlayerPerChipX * x;
                int PlayerY = PlayerPerChipY * y;
                if (MakePlayer[y][x] == 1)
                {                    
                    DrawRectGraph(Player_posX,Player_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
                }



            }
        }

        DrawFormatString(0, 0, 0xff00ff, "x=%d,y=%d", Player_posX, Player_posY);

    }
    

    void Character::Move(Map& gamescene)
    {
        
        gpUpdateKey();
        if (titleP.Key[KEY_INPUT_UP])
        {
           
            Player_posY -=5;
            if (Player_posY<0)
            {
                Player_posY = 0;
            }

            
        }
        
        
        //�d��
        Player_posY +=Jumpgravity;  
        JumpFlag == true;
        if (titleP.Key[KEY_INPUT_SPACE]==1&&JumpFlag==true)
        {   
             JumpFlag = false;  
            Player_posY -= JumpSpeed+JumpInitialVelocity;
            JumpInitialVelocity -= 1;
                
             
           
            if (Player_posY==368)
            {
                JumpFlag == true;
               
            }

         
        }
        //��ʂ̔䗦320*240
        //�摜�̔䗦384*256
        if (titleP.Key[KEY_INPUT_DOWN])
        {
            Player_posY = CharaMoveSpeed + Player_posY;
            FallCollision();

        }

        if (titleP.Key[KEY_INPUT_RIGHT])
        {
            Player_posX= CharaMoveSpeed + Player_posX;

           PlayerChipSizeX = 0;
           PlayerChipSizeY = 64;
          

        }

        if (titleP.Key[KEY_INPUT_LEFT])
        {
            Player_posX = Player_posX - CharaMoveSpeed;
            if (Player_posX < 0)
            {
                Player_posX = 0;
                Player_posY = Player_posY;
            }
            PlayerChipSizeX = 32;
            PlayerChipSizeY = 32;
        }

        FallCollision();

    }

    
    void Character::Update()
    {

        
    }

    void Character::Collision(Enemy&cEnemy)
    {
        //���Ɓ��̓����蔻��,������̂̓����蔻��,
        if (cEnemy.enemyX>Player_posX&&cEnemy.enemyX-Player_posX<16&&cEnemy.enemyY-Player_posY<16||Player_posX>cEnemy.enemyX&&Player_posX-cEnemy.enemyX<16&& cEnemy.enemyY - Player_posY < 16)
        {
            SetDrawBlendMode(DX_BLENDMODE_INVSRC, 50);
           
        }
        else
        {
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        }

    }
   

    void Character::FallCollision()
    {
        if (Player_posY >= 496)
        {
            Player_posX = 160;
            Player_posY = 120;
        }
        if (Player_posY > 368 && Player_posX <= 256)
        {
            Player_posY = 368;
        }

    }

    int Character::gpUpdateKey() {
        char tmpkey[256]; //���݂̃L�[���͏�Ԃ��i�[����
        GetHitKeyStateAll(tmpkey); //���ׂẴL�[���͏�Ԃ𓾂�
        for (int i = 0; i < 256; i++) {	//i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            if (tmpkey[i] != 0) {
                titleP.Key[i]++;				//���Z
            }
            else {						//������Ă��Ȃ����
                titleP.Key[i] = 0;
            }

        }
        return 0;
    }

    
  




    //Artificial Providence �l
    //�҂ۂ�q�ɗl
