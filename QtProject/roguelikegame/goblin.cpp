#include "goblin.h"
#include "monster.h"
void Goblin::resetSize(){setFrameSize(3);}

void Goblin::resetHp()
{
    setHp(5);
    setHp_max(5);
}

void Goblin::resetSpeed()
{
    setSpeed(5);
}

Goblin::Goblin()
{
    setLeftpic(0,QPixmap(p_l_path.arg(0)));
    setLeftpic(1,QPixmap(p_l_path.arg(1)));
    setLeftpic(2,QPixmap(p_l_path.arg(2)));
    setRightpic(0,QPixmap(p_r_path.arg(0)));
    setRightpic(1,QPixmap(p_r_path.arg(1)));
    setRightpic(2,QPixmap(p_r_path.arg(2)));
}
