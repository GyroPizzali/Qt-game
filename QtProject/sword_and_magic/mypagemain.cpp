#include "mypagemain.h"
#include <QPainter>
MyPageMain::MyPageMain(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("QLabel {"
                        "color : white;"//游戏标题颜色
                        "background-image : url();"//待定标题背景
                        "}"
                        "QPushButton {"
                        "border-radius : 35px;"//边框圆角
                        "background-color: rgba(255, 255, 255, 188);"//边框颜色及透明度
                        "}"
                        "QPushButton::hover{"
                        "background-color: rgba(255, 255, 255, 255);"//边框颜色及透明度
                        "}");
}

void MyPageMain::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    p.setPen(pen);
    //绘制主页面背景
    p.drawPixmap(rect(),QPixmap("../image/bg.png"));
}
