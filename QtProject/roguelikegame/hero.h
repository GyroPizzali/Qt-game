#ifndef HERO_H
#define HERO_H
#include "fireball.h"
#include "item.h"
class Hero
{
public:
    int hp;//人物血量,实际血量为hp - difficulty
    int x;//人物坐标
    int y;//人物坐标
    int dir;//人物朝向， 右0左1
    int speed;//人物速度
    Item  itembag[3];

    int left_forward = 0;//左走动作帧
    int right_forward = 0;//右走动作帧

    fireball firebag[30];
    bool attack = 0;//是否火球攻击
    int fireballCount = 0;//火球计数器

    bool isSwordShown = 0;//是否近战攻击


    Hero();
};

#endif // HERO_H
