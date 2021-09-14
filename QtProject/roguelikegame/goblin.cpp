#include "goblin.h"
#include "monster.h"
void Goblin::resetSize(){setFrameSize(3);}

Goblin::Goblin()
{
    setLeftpic(0,QPixmap(p_l_path.arg(0)));
    setLeftpic(1,QPixmap(p_l_path.arg(1)));
    setLeftpic(2,QPixmap(p_l_path.arg(2)));
    setRightpic(0,QPixmap(p_r_path.arg(0)));
    setRightpic(1,QPixmap(p_r_path.arg(1)));
    setRightpic(2,QPixmap(p_r_path.arg(2)));
}
