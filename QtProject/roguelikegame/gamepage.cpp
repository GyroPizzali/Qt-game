#include "gamepage.h"
#include "ui_gamepage.h"
#include "fireball.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);
    paint_timer = new QTimer(this);
    paint_timer->start(50);
    connect(paint_timer,&QTimer::timeout,
            [=](){
                //重绘工程中顺便实现火球的随时间移动的特性
            for (int i = 0;i < 20;i++){
                if (fb[i].getActive()){
                    int temp = fb[i].getX();
                    if (fb[i].getDir() == 0)
                        temp += 20;
                    else
                        temp -= 20;
                    //越界重置
                    if (temp > 1700 || temp < -100){
                        fb[i].unsetActive();
                    }
                    fb[i].setX(temp);
                }
            }
                update();
            }
            );
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //绘画背景地图
    QPixmap bg;
    if (mapCounter == 0)
        bg = QPixmap("../image/bg1.png");
    if (mapCounter == 1)
        bg = QPixmap("../image/bg2.png");
    if (mapCounter == 2)
        bg = QPixmap("../image/bg3.jpg");
    if (mapCounter == 3)
        bg = QPixmap("../image/bg4.jpg");
    p.drawPixmap(rect(),bg);
    //绘画第一关的介绍
    if (mapCounter == 0){
        ui->introduce->setText(QString("<center><h1>"
                                       "press A/D to move <br><br>"
                                       "prese J/K to use firebal/sword to attack <br><br>"
                                       "press U/I/O to use existing skills <br><br>"
                                       "</h1></center>"));
    }
    else {
        ui->introduce->setText("");
    }
    //绘画角色
    QPixmap ch;
    if (dir == 0){
        if (right_forward == 0)
            ch = QPixmap("../image/r0.png");
        if (right_forward == 1)
            ch = QPixmap("../image/r1.png");
        if (right_forward == 2)
            ch = QPixmap("../image/r2.png");
        if (right_forward == 3)
            ch = QPixmap("../image/r3.png");
    }
    else{
        if (left_forward == 0)
            ch = QPixmap("../image/l0.png");
        if (left_forward == 1)
            ch = QPixmap("../image/l1.png");
        if (left_forward == 2)
            ch = QPixmap("../image/l2.png");
        if (left_forward == 3)
            ch = QPixmap("../image/l3.png");
    }
    p.drawPixmap(x,y,100,150,ch);
    //绘画血量
    for (int i = 0,l = 0;i < hp;i++,l += 60){
        p.drawPixmap(l,0,50,50,QPixmap("../image/hp.png"));
    }
    //绘画火球攻击
    QPixmap img_fb;
    if (attack){
        //便利火球数组输出当前场上的火球
        for (int i = 0;i < 20;i++){
            if (fb[i].getActive()){
                if (fb[i].getDir() == 0)
                    img_fb = QPixmap("../image/fbr.png");
                else
                    img_fb = QPixmap("../image/fbl.png");
                p.drawPixmap(fb[i].getX(),700,150,150,img_fb);
            }
        }
    }
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D){
        dir = 0;
        right_forward++;
        right_forward = right_forward % 4;
        if (x <= 1600)
            x += pace;
        if (x > 1600){
            x = 0;
            int temp = mapCounter;
            while(mapCounter == temp)//防止下一站地图与本张相同
                mapCounter = rand() % 4;
        }
    }
    if(event->key() == Qt::Key_A){
        dir = 1;
        left_forward++;
        left_forward = left_forward % 4;
        if (0 <= x)
            x -= pace;
    }
    if(event->key() == Qt::Key_J){
        if (dir == 0)
        {
            fb[fireballCount % 20].setX(x+50);
            fb[fireballCount % 20].setDir(0);
        }
        else{
            fb[fireballCount % 20].setX(x-100);
            fb[fireballCount % 20].setDir(1);
        }
        fb[(fireballCount % 20)].setActive();
        fireballCount++;
        attack = 1;
    }
}
