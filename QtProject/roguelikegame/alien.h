#ifndef ALIEN_H
#define ALIEN_H

#include "monster.h"
#include"config.h"
#include<QString>
class Alien : public Monster
{
    QString  p_l_path=QString(ALIEN_PATH1);//左图片路径；
    QString  p_r_path=QString(ALIEN_PATH2);//右图片路径；
public:
    //根据类别进行属性的调整
    void resetSize();
    void resetHp(){setHp(4);
                   setHp_max(4);}
    void resetSpeed(){setSpeed(6);}
    Alien();
};

#endif // ALIEN_H
