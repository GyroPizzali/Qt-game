#ifndef FIREBALL_H
#define FIREBALL_H
#include <QRect>

class fireball
{
public:
    fireball();
    int  getX();
    void setX(int a);

    int  getY();
    void setY(int a);

    int getW();
    void setW(int a);

    int getH();
    void setH(int a);

    int  getV();
    void setV(int a);

    int getPos();
    void setPos(int a);

    int getInterval();
    void setInterval(int a);

    bool getDir();
    void setDir(int a);

    bool getActive();
    void setActive();
    void unsetActive();

    QRect getFireballRect();

    void updateRect();

private:
    int fb_x;
    int fb_y;
    int fb_w = 150;
    int fb_h = 150;
    int fb_v = 20;
    int pos;//火球所在层数
    int interval = 500;//火球攻击间隔
    bool fb_dir;
    bool active = 0;
    QRect fireball_rect;
};

#endif // FIREBALL_H
