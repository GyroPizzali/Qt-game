#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamepage.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    int getDif(){return dif;}
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    GamePage g;
    int dif = 1;//难度选择
    Ui::Widget *ui;
};

#endif // WIDGET_H
