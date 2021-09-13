#include "goblin.h"
#include "monster.h"
Goblin::Goblin()
{
    setLeftpic(0,QPixmap(":image/gol0.png"));
    setLeftpic(1,QPixmap(":image/gol1.png"));
    setLeftpic(2,QPixmap(":image/gol2.png"));
    setRightpic(0,QPixmap(":image/gor0.png"));
    setRightpic(1,QPixmap(":image/gor1.png"));
    setRightpic(2,QPixmap(":image/gor2.png"));
}
