#include "alien.h"
#include "monster.h"
void Alien::resetSize(){setFrameSize(1);}

Alien::Alien()
{
    setLeftpic(0,QPixmap(p_l_path));
    setRightpic(0,QPixmap(p_r_path));
}
