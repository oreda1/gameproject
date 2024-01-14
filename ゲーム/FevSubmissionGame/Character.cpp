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


    }

    void Character::Draw()
    {
        PlayerHandle = LoadGraph("Cockroach.png");

        for (int x = 0; x < PlayerPerChipX; x++)
        {
            for (int y = 0; y < PlayerPerChipY; y++)
            {
                //�L�����N�^�[�`�b�v
                int PlayerX = PlayerPerChipX * x;
                int PlayerY = PlayerPerChipY * y;
                if (MakePlayer[y][x] == 1)
                {
                    
                    DrawRectGraph(start_posX, start_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
                }



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

        JumpInitialVelocity = -10;
        if (titleP.Key[KEY_INPUT_SPACE])  
        {
            
            JumpInitialVelocity += JumpSpeed;
            Jumpgravity = -1;
            start_posY += JumpInitialVelocity;
            
            
            
                  
        }
       

        
        
        //��ʂ̔䗦320*240
        //�摜�̔䗦384*256
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



    }

    void Character::Update()
    {
        
    }

    void Character::Collision()
    {
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







