#ifndef FIREBALL_H
#define FIREBALL_H


class fireball
{
public:
    fireball();
    int  getX(){return fb_x;}
    void setX(int a){fb_x = a;}

    int  getY(){return fb_y;}
    void setY(int a){fb_y = a;}

    int  getV(){return fb_v;}
    void setV(int a){fb_v = a;}

    int getInterval(){return interval;}
    void setInterval(int a){interval = a;}

    bool getDir(){return fb_dir;}
    void setDir(int a){fb_dir = a;}

    bool getActive(){return active;}
    void setActive(){active = 1;}
    void unsetActive(){active = 0;}

private:
    int fb_x;
    int fb_y;
    int fb_v;
    int interval = 500;//火球攻击间隔
    bool fb_dir;
    bool active = 0;
};

#endif // FIREBALL_H
