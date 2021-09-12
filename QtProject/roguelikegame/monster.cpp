#include "monster.h"

Monster::Monster()
{
    monster_rect.setWidth(picMonster.width());
    monster_rect.setHeight(picMonster.height());
    monster_rect.setX(x);
    monster_rect.setY(y);
}
