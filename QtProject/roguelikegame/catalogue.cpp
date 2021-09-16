#include "catalogue.h"
#include <QPainter>
Catalogue::Catalogue(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Game Preview");
    this->setMaximumHeight(900);
    this->setMaximumWidth(500);
    this->setMinimumHeight(900);
    this->setMinimumWidth(500);
    this->move(2328,412);


}

void Catalogue::paintEvent(QPaintEvent *event)
{
    QPainter pc(this);
    pc.drawPixmap(rect(),QPixmap(":image/preview.png"));
}
