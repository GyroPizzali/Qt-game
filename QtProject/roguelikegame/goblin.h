#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"
#include"config.h"
#include<QPixmap>
#include<QString>
class Goblin : public Monster
{
    QString  p_l_path=QString(GOBLIN_PATH1);//左图片路径；
    QString  p_r_path=QString(GOBLIN_PATH2);//右图片路径；
public:
    //根据类别进行属性的调整
    void resetSize();
    void resetHp();
    void resetSpeed();
    Goblin();
};

#endif // GOBLIN_H
