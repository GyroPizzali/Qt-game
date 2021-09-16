#ifndef MONSTER_H
#define MONSTER_H
#include <QPixmap>
#include <QRect>
#include <QVector>
#include "config.h"
class Monster
{
private:
    bool active = 0;//是否处于显示状态
    int x;//坐标
    int y;//坐标
    int w = 150;//宽度
    int h = 150;//高度
    int speed = 5;//速度
    int dir;//朝向，右0左1
    int posRand;//怪物位置随机初始化，0~5分别对应左上、左中、左下、右上、右中、右下；
    int hp = 5;//当前血量
    int hp_max = 5;//最大血量
    int picFrame;//动画帧数计数变量
    QRect monster_rect;//怪物碰撞体积
    QPixmap picMonster;//当前帧图片

    int frameSize = 0;//动画帧数，不同怪物不同
    QPixmap pictureLeft[10];//朝左帧数组，不同怪物不同
    QPixmap pictureRight[10];//朝右帧数组，不同怪物不同
public:
    //根据类别改变帧数
    virtual void resetSize();
    //根据类改变图片集
    virtual void resetPicture();

    //根据类别改变速度
    virtual void resetSpeed();
    //根据类别改变血量
    virtual void resetHp();
    //行为函数
    void updataRect();//更新碰撞体积，需定时调用
    void death();//死亡
    //属性访问与设置
    bool getActive();
    void setActive(bool a);

    int  getX();
    void setX(int a);

    int  getY();
    void setY(int a);

    int  getW();
    void setW(int a);

    int  getH();
    void setH(int a);

    int getSpeed();
    void setSpeed(int a){speed = a;}

    int getDir();
    void setDir(int a);

    int getPosRand();
    void setPosRand(int a);

    int  getHp();
    void setHp(int a);

    int  getHp_max();
    void setHp_max(int a);

    int getFrameSize();
    void setFrameSize(int a);

    QRect getMonsterRect();

    QPixmap getPicMonster();
    void setPicMonster(QPixmap a);

    int  getPicFrame();
    void setPicFrame(int a);

    QPixmap getLeftpic(int i);
    void setLeftpic(int i,QPixmap p);

    QPixmap getRightpic(int i);
    void setRightpic(int i,QPixmap p);

    Monster();
    void setqrect();
};

#endif // MONSTER_H
