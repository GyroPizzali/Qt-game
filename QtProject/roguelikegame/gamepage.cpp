#include "gamepage.h"
#include "ui_gamepage.h"
#include <QPainter>
#include <QKeyEvent>
GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPixmap bg;
    QPixmap pl;
    //绘画背景地图
    if (mapCounter == 0)
        bg = QPixmap("../image/bg1.png");
    if (mapCounter == 1)
        bg = QPixmap("../image/bg2.png");
    if (mapCounter == 2)
        bg = QPixmap("../image/bg3.jpg");
    if (mapCounter == 3)
        bg = QPixmap("../image/bg4.jpg");
    p.drawPixmap(rect(),bg);
    //绘画角色
    if (dir == 0){
        if (right_forward == 0)
            bg = bg = QPixmap("../image/r0.png");
        if (right_forward == 1)
            bg = bg = QPixmap("../image/r1.png");
        if (right_forward == 2)
            bg = bg = QPixmap("../image/r2.png");
        if (right_forward == 3)
            bg = bg = QPixmap("../image/r3.png");
    }
    else{
        if (left_forward == 0)
            bg = bg = QPixmap("../image/l0.png");
        if (left_forward == 1)
            bg = bg = QPixmap("../image/l1.png");
        if (left_forward == 2)
            bg = bg = QPixmap("../image/l2.png");
        if (left_forward == 3)
            bg = bg = QPixmap("../image/l3.png");
    }
    p.drawPixmap(x,y,100,150,bg);
    //绘画血量
    for (int i = 0,l = 0;i < hp;i++,l += 60){
        p.drawPixmap(l,0,50,50,QPixmap("../image/hp.png"));
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
    update();
}
