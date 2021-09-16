#ifndef ITEM_H
#define ITEM_H

#include <QRect>
#include <QPixmap>

class Item
{
public:
    Item();

    void updateRect();//更新碰撞模型

    int getX(){return x;}
    void setX(int a){x = a;}

    int getY(){return y;}
    void setY(int a){y= a;}

    int getW(){return w;}
    void setW(int a){w = a;}

    int getH(){return h;}
    void setH(int a){h = a;}

    int getN(){return n;}
    void setN(int a){n = a;}

    int getIsShow(){return isShown;}
    void show(){isShown = 1;}
    void hide(){isShown = 0;}

    QPixmap getPicItem(){return picItem;}
    void setPicItem(QPixmap a){picItem = a;}

    QRect getItemRect(){return item_rect;}

private:
    int x = 720;
    int y = 760;
    int w = 80;
    int h = 80;
    int n;//技能编号
    int isShown = 1;//显示
    QPixmap picItem;//图片
    QRect item_rect;//碰撞体积
};

#endif // ITEM_H
