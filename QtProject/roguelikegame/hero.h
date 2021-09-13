#ifndef HERO_H
#define HERO_H
#include"fireball.h"
#include"item.h"
class hero
{
    int hp;//人物血量,实际血量为hp - difficulty
    int x;//人物坐标
    int y;//人物坐标
    int dir;//人物朝向， 右0左1
    int speed;//人物速度
    fireball firebag[30];
    Item  itembag[3];
public:
    hero();
};

#endif // HERO_H
