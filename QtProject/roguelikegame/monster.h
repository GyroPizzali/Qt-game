#ifndef MONSTER_H
#define MONSTER_H
#include <QPixmap>

class Monster
{
private:
    bool active = 0;
    int x;//坐标
    int y;//坐标
    int w;//宽度
    int h;//高度
    int dir;//朝向，右0左1
    int posRand;//怪物位置随机初始化，0~5分别对应左上、左中、左下、右上、右中、右下；
    int hp;//当前血量
    int hp_max;//最大血量
    int picFrame;//动画帧数计数变量
    QPixmap picMonster;//当前帧图片
public:
    //行为函数
    void death(){
        active = 0;
    }
    //属性访问与设置
    bool getActive(){return active;}
    void setActive(bool a){active = a;}

    int  getX(){return x;}
    void setX(int a){x = a;}

    int  getY(){return y;}
    void setY(int a){y = a;}

    int  getW(){return w;}
    void setW(int a){w = a;}

    int  getH(){return h;}
    void setH(int a){h = a;}

    int getDir(){return dir;}
    void setDir(int a){dir = a;}

    int getPosRand(){return posRand;}
    void setPosRand(int a){posRand = a;}

    int  getHp(){return hp;}
    void setHp(){hp = 1;}

    int  getHp_max(){return hp_max;}
    void setHp_max(int a){hp_max = a;}

    int  getPicFrame(){return picFrame;}
    void setPicFrame(int a){picFrame = a;}

    QPixmap getPicMonster(){return picMonster;}
    void setPicMonster(QPixmap a){picMonster = a;}

    Monster();
};

#endif // MONSTER_H
