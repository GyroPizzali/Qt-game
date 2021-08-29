#ifndef FIREBALL_H
#define FIREBALL_H


class fireball
{
public:
    fireball();
    int getX(){
        return fb_x;
    }
    int getV(){
        return fb_v;
    }
    bool getDir(){
        return fb_dir;
    }
    void setX(int a){
        fb_x = a;
    }
    void setV(int a){
        fb_v = a;
    }
    void setDir(int a){
        fb_dir = a;
    }
    void setActive(){
        active = 1;
    }
    void unsetActive(){
        active = 0;
    }
    bool getActive(){
        return active;
    }
private:
    int fb_x;
    int fb_v;
    bool fb_dir;
    bool active = 0;
};

#endif // FIREBALL_H
