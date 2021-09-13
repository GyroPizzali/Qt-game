#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"

class Goblin : public Monster
{
public:
    //根据类别进行属性的调整
    void resetSize(){setFrameSize(3);}
    Goblin();
};

#endif // GOBLIN_H
