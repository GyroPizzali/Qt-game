#include "mypage.h"
#include "widget.h"
#include <QKeyEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>

MyPage::MyPage(QWidget *parent) : QWidget(parent)
{

}

void MyPage::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_D){
        if (0 <= x && x <= 1600)
            x += 100;
        //右越界回到左侧
        if (x > 1600)
            x = 50;
    }
    if(event->key() == Qt::Key_A){
        if (0 <= x && x <= 1600)
            x -= 100;
        //左侧越界回到右侧
        if (x < 0)
            x = 1550;
    }
    update();
}

void MyPage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    p.setPen(pen);
    //绘制关卡背景
    p.drawPixmap(rect(),QPixmap("../image/bg1.png"));
    //绘制移动平台
    p.drawLine(0,700,1600,700);
    //绘制角色
    p.drawEllipse(QPoint(x,y),50,50);

}
