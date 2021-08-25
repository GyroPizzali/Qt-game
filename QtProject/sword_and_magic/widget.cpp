#include "widget.h"
#include "mypage.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Sword & Magic");

    ui->stackedWidget->setCurrentWidget(ui->pageMain);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_difBut_released()
{
    int dif = difSelector % 3;
    if (dif == 1)
        ui->difBut->setText("Difficulty : normal");
    if (dif == 2)
        ui->difBut->setText("Difficulty : hard");
    if (dif == 0)
        ui->difBut->setText("Difficulty : easy");
    difSelector++;
}

void Widget::on_exiBut_released()
{
    close();
}

void Widget::on_staBut_released()
{
    ui->stackedWidget->setCurrentWidget(ui->pageGame);
}
