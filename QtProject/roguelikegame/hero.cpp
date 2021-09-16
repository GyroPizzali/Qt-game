#include "hero.h"
#include "config.h"
void Hero::updataRect()
{
    hero_rect.setWidth(w);
    hero_rect.setHeight(h);
    hero_rect.setX(x);
    hero_rect.setY(y);
}

Hero::Hero()
{
    hp=HERO_HP;
    speed=HERO_SPEED;
    x=0;
    y=700;
    dir=0;
    for (int i = 0;i < 5;i++){
        skillRelease[i] = 0;
    }
}
