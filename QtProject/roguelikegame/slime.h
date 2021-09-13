#ifndef SLIME_H
#define SLIME_H

#include "monster.h"
#include <QPixmap>

class Slime : public Monster
{
public:
    Slime();
    //根据类别进行属性的调整
    void resetSize(){setFrameSize(2);}
private:

};

#endif // SLIME_H
