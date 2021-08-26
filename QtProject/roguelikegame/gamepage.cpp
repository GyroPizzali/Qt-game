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
    if (dir == 0)
        bg = QPixmap("../image/player0.png");
    else
        bg = QPixmap("../image/player1.png");
    p.drawPixmap(x,y,100,200,bg);
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D){
        dir = 0;
        if (0 <= x && x <= 1600)
            x += 70;
        if (x > 1600){
            x = 0;
            mapCounter = rand() % 4;
        }
    }
    if(event->key() == Qt::Key_A){
        dir = 1;
        if (0 <= x && x <= 1600)
            x -= 70;
    }
    update();
}
