#include "widget.h"
#include "gamepage.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Sword and Magic");
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
    connect(g,&GamePage::quitToMain,this,&Widget::returnToMain);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(rect(),QPixmap(":image/bg.png"));
    p.drawPixmap(200,0,1200,600,QPixmap(":image/title.png"));
}


void Widget::on_difButton_released()
{
    //难度选择
    int d = dif % 3;
    if (d == 1)
        ui->difButton->setText("Difficulty : normal");
    if (d == 2)
        ui->difButton->setText("Difficulty : hard");
    if (d == 0)
        ui->difButton->setText("Difficulty : easy");
    dif++;
}

void Widget::on_exiButton_released()
{
    close();
}

void Widget::on_staButton_released()
{
    g->show();
    emit sendInf();
    this->hide();
}

void Widget::returnToMain()
{
    this->show();
    g->hide();
    //将实例化的对象删除后在申请空间实现游戏界面的刷新，就是不知道会不会有其他后果，
    //目前只发现conne的信号会中断
    delete g;
    g = new GamePage;
    connect(g,&GamePage::quitToMain,this,&Widget::returnToMain);
}

