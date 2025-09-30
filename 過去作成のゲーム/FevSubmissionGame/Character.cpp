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

    //�L�����N�^�[��`�悷�鏈��
    void Character::Draw()
    {
     
        DrawRectGraph(Player_posX,Player_posY, PlayerChipSizeX, PlayerChipSizeY, PlayerWidthX, PlayerHeightY, PlayerHandle, true);
      


        
         //�L�����N�^�[�`�b�v        
        // Debug position display (uncomment if needed)
        // DrawFormatString(550, 20, 0xff00ff, "x=%d,y=%d", Player_posX, Player_posY);
    }
    

    //�L�����N�^�[��`�悷�鏈��
    void Character::Move(Map& gamescene)
    {
        
        gpUpdateKey();
        // Apply gravity
        Player_posY += Jumpgravity;
        
        // Jump logic - only jump when on ground and space key is pressed
        if (titleP.Key[KEY_INPUT_SPACE] == 1 && JumpFlag == false)
        {
            Player_posY -= JumpSpeed + JumpInitialVelocity;
            JumpFlag = true; // Set flag to prevent continuous jumping
        }
        

        //��ʂ̔䗦320*240
        //�摜�̔䗦384*256
        // Horizontal movement
        if (titleP.Key[KEY_INPUT_LEFT])
        {
            Player_posX -= CharaMoveSpeed;
        }
        if (titleP.Key[KEY_INPUT_RIGHT])
        {
            Player_posX += CharaMoveSpeed;
        }
        
        // Down movement (crouch)
        if (titleP.Key[KEY_INPUT_DOWN])
        {
            Player_posY += CharaMoveSpeed;
        }
        
        // Ground collision check
        FallCollision();
        
        // Reset jump flag when on ground
        if (Player_posY >= exceedY)
        {
            JumpFlag = false;
        }

    }

    //�L�����N�^�[
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
