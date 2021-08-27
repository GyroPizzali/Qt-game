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
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_difButton_released();

    void on_exiButton_released();

    void on_staButton_released();

private:
    int dif = 1;//难度选择
    GamePage g;//游戏窗口实例化
    Ui::Widget *ui;
};

#endif // WIDGET_H
