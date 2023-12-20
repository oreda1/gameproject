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
        DrawGraph(start_posX, start_posY, PlayerHandle, false);
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

        if (titleP.Key[KEY_INPUT_SPACE])
        {
            start_posX = start_posX+(start_posY*1.0);
            start_posY = start_posY +(start_posX * 1.0);
                

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







