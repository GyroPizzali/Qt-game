#include "slime.h"
#include "monster.h"
Slime::Slime()
{
    setLeftpic(0,QPixmap(":image/sll0.png"));
    setLeftpic(1,QPixmap(":image/sll1.png"));
    setRightpic(0,QPixmap(":image/slr0.png"));
    setRightpic(1,QPixmap(":image/slr1.png"));
}
