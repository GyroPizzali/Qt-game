#include "fireball.h"

fireball::fireball()
{

}

int fireball::getX(){return fb_x;}

void fireball::setX(int a){fb_x = a;}

int fireball::getY(){return fb_y;}

void fireball::setY(int a){fb_y = a;}

int fireball::getW(){return fb_w;}

void fireball::setW(int a){fb_w = a;}

int fireball::getH(){return fb_h;}

void fireball::setH(int a){fb_h = a;}

int fireball::getV(){return fb_v;}

void fireball::setV(int a){fb_v = a;}

int fireball::getPos(){return pos;}

void fireball::setPos(int a){pos = a;}

int fireball::getInterval(){return interval;}

void fireball::setInterval(int a){interval = a;}

bool fireball::getDir(){return fb_dir;}

void fireball::setDir(int a){fb_dir = a;}

bool fireball::getActive(){return active;}

void fireball::setActive(){active = 1;}

void fireball::unsetActive(){active = 0;}

QRect fireball::getFireballRect(){return fireball_rect;}

void fireball::updateRect()
{
    if (fb_dir == 1){
        fireball_rect.setWidth(fb_w - 60);
        fireball_rect.setHeight(fb_h);
        fireball_rect.setX(fb_x + 20);
        fireball_rect.setY(fb_y);
    }

    else{
        fireball_rect.setWidth(fb_w - 60);
        fireball_rect.setHeight(fb_h);
        fireball_rect.setX(fb_x + 40);
        fireball_rect.setY(fb_y);
    }

}
