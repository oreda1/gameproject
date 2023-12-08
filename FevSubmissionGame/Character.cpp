#include "Character.h"
#include "DxLib.h"
#include "BaseNuber.h"


Character::Character():
  start_posX(GameWidth/2),
  start_posY(GameHeight/2)
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
    DrawGraph(start_posX,start_posY,CharHandle, true);
}


void Character::Move(CharaMove& cara_move)
{
    


    if (KEY_INPUT_UP==1)
    {
        if (GameHeight>480)
        {
            
        }

    }
    if (KEY_INPUT_RIGHT==1)
    {
        
    }
    if (KEY_INPUT_LEFT==1)
    {
       
    }

    
    
}

void Character::Update()
{
}






    

