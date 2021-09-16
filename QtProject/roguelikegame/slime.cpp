#include "slime.h"
#include "monster.h"
Slime::Slime()
{
    setLeftpic(0,QPixmap(p_l_path.arg(0)));
    setLeftpic(1,QPixmap(p_l_path.arg(1)));
    setRightpic(0,QPixmap(p_r_path.arg(0)));
    setRightpic(1,QPixmap(p_r_path.arg(1)));
}

void Slime::resetSize()
{
    setFrameSize(2);
}

void Slime::resetHp()
{
    setHp(8);
    setHp_max(8);
}

void Slime::resetSpeed()
{
    setSpeed(4);
}
