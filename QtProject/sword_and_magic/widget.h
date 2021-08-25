#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mypage.h"
#include "ui_widget.h"
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);



    ~Widget();
protected:
private slots:
    void on_difBut_released();

    void on_exiBut_released();

    void on_staBut_released();
signals:


private:
    int difSelector = 1;//难度选择器
    Ui::Widget *ui;
};

#endif // WIDGET_H
