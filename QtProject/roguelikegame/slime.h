#ifndef SLIME_H
#define SLIME_H

#include "monster.h"
#include <QPixmap>
#include"config.h"
#include<QString>
class Slime : public Monster
{
    QString  p_l_path=QString(SLIME_PATH1);//左图片路径；
    QString  p_r_path=QString(SLIME_PATH2);//右图片路径；
public:
    Slime();
    //根据类别进行属性的调整
    void resetSize(){setFrameSize(2);}
private:

};

#endif // SLIME_H
