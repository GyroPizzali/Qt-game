#include "monster.h"

void Monster::resetSize(){}

void Monster::resetPicture(){}

void Monster::updataRect()
{
    monster_rect.setWidth(w - 100);
    monster_rect.setHeight(h);
    monster_rect.setX(x + 50);
    monster_rect.setY(y);
}

void Monster::death(){
    active = 0;
}

bool Monster::getActive(){return active;}

void Monster::setActive(bool a){active = a;}

int Monster::getX(){return x;}

void Monster::setX(int a){x = a;}

int Monster::getY(){return y;}

void Monster::setY(int a){y = a;}

int Monster::getW(){return w;}

void Monster::setW(int a){w = a;}

int Monster::getH(){return h;}

void Monster::setH(int a){h = a;}

int Monster::getSpeed(){return speed;}

int Monster::getDir(){return dir;}

void Monster::setDir(int a){dir = a;}

int Monster::getPosRand(){return posRand;}

void Monster::setPosRand(int a){posRand = a;}

int Monster::getHp(){return hp;}

void Monster::setHp(int a){hp = a;}

int Monster::getHp_max(){return hp_max;}

void Monster::setHp_max(int a){hp_max = a;}

int Monster::getFrameSize(){return frameSize;}

void Monster::setFrameSize(int a){frameSize = a;}

QRect Monster::getMonsterRect(){return monster_rect;}

QPixmap Monster::getPicMonster(){return picMonster;}

void Monster::setPicMonster(QPixmap a){picMonster = a;}

int Monster::getPicFrame(){return picFrame;}

void Monster::setPicFrame(int a){picFrame = a;}

QPixmap Monster::getLeftpic(int i){return pictureLeft[i];}

void Monster::setLeftpic(int i, QPixmap p){pictureLeft[i] =p;}

QPixmap Monster::getRightpic(int i){return pictureRight[i];}

void Monster::setRightpic(int i, QPixmap p){pictureRight[i] =p;}

Monster::Monster(){

}

void Monster::setqrect()
{

}
