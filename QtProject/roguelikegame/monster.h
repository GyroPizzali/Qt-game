#ifndef MONSTER_H
#define MONSTER_H
#include <QPixmap>
#include<QRect>
class Monster
{
private:
    bool active = 0;//是否处于显示状态
    int x;//坐标
    int y;//坐标
    int w;//宽度
    int h;//高度
    int dir;//朝向，右0左1
    int posRand;//怪物位置随机初始化，0~5分别对应左上、左中、左下、右上、右中、右下；
    int hp = 5;//当前血量
    int hp_max = 5;//最大血量
    int picFrame;//动画帧数计数变量
    QRect monster_rect;//怪物碰撞体积
    QPixmap picMonster;//当前帧图片

    int frameSize;//动画帧数，不同怪物不同
    QPixmap pictureLeft[10];//朝左帧数组，不同怪物不同
    QPixmap pictureRight[10];//朝右帧数组，不同怪物不同
public:
    //根据类别改变帧数
    virtual void resetSize(){}
    //根据类改变图片集
    virtual void resetPicture(){}
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

    int getFrameSize(){return frameSize;}
    void setFrameSize(int a){frameSize = a;}

    QPixmap getPicMonster(){return picMonster;}
    void setPicMonster(QPixmap a){picMonster = a;}

    int  getPicFrame(){return picFrame;}
    void setPicFrame(int a){picFrame = a;}

    QPixmap getLeftpic(int i){return pictureLeft[i];}
    void setLeftpic(int i,QPixmap p){pictureLeft[i] =p;}

    QPixmap getRightpic(int i){return pictureRight[i];}
    void setRightpic(int i,QPixmap p){pictureRight[i] =p;}

    Monster();
};

#endif // MONSTER_H
