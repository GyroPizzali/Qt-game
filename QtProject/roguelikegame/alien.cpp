#include "alien.h"
#include "monster.h"
void Alien::resetSize(){setFrameSize(1);}

void Alien::resetHp()
{
    setHp(4);
    setHp_max(4);
}

void Alien::resetSpeed()
{
    setSpeed(6);
}

Alien::Alien()
{
    setLeftpic(0,QPixmap(p_l_path));
    setRightpic(0,QPixmap(p_r_path));
}
