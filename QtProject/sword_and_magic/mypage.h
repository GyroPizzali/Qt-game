#ifndef MYPAGE_H
#define MYPAGE_H

#include <QWidget>
#include "widget.h"
class MyPage : public QWidget
{
    Q_OBJECT
public:
    explicit MyPage(QWidget *parent = nullptr);
    int get_x(){
        return x;
    }
    int get_y(){
        return y;
    }
private:
    int dif = 1;//难度
    int x = 50;
    int y = 650;
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
signals:
public slots:
    void setDif(int d){
        dif = d;
    };
};

#endif // MYPAGE_H
