#ifndef ALIEN_H
#define ALIEN_H

#include "monster.h"
class Alien : public Monster
{
public:
    //根据类别进行属性的调整
    void resetSize(){setFrameSize(1);}
    Alien();
};

#endif // ALIEN_H
