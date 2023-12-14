#include "Character.h"
#include "DxLib.h"
#include "BaseNuber.h"




    Character::Character() :
        start_posX(384),
        start_posY(240)
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
        for (int x = 0; x < PlayerChipX; x++)
        {
            for (int y = 0; y < PlayerChipY; y++)
            {
                if (MakePlayer[y][x] == 1)
                {
                    DrawGraph(start_posX, start_posY, PlayerHandle, false);
                }


            }

        }


    }


    void Character::Move()
    {



        if (KEY_INPUT_UP == 1)
        {
            start_posY = start_posY + 10;
            if (GameHeight > 480)
            {
                start_posX = start_posX;
                start_posY = start_posY;
            }

        }
        if (KEY_INPUT_RIGHT == 1)
        {
            ++start_posX;
        }
        if (KEY_INPUT_LEFT == 1)
        {
            --start_posX;
        }



    }

    void Character::Update()
    {
    }








