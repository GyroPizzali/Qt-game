#ifndef HERO_H
#define HERO_H
#include "fireball.h"
#include "item.h"
#include <QRect>
#include <QVector>
class Hero
{
public:
    int hp;//人物血量,实际血量为hp - difficulty
    int x;//人物坐标
    int y;//人物坐标
    int w = 100;//宽
    int h = 150;//高
    int pos;//当前所在层数至上而下0 1 2
    QRect hero_rect;//人物碰撞模型
    void updataRect();//更新碰撞模型
    int dir;//人物朝向， 右0左1
    int isUp;//是否处于向上移动状态
    int isDown;//是否处于向下移动状态
    int speed;//人物速度

    QVector<Item> itemBag;//技能背包

    int skillRelease[5];//五个技能是否处于释放状态

    int left_forward = 0;//左走动作帧
    int right_forward = 0;//右走动作帧

    fireball firebag[30];
    bool attack = 0;//是否火球攻击
    int fireballCount = 0;//火球计数器

    bool isSwordShown = 0;//是否近战攻击



    Hero();
};

#endif // HERO_H
