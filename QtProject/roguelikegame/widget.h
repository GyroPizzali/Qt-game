#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamepage.h"
#include "catalogue.h"
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
    void paintEvent(QPaintEvent *event);
private slots:
    void on_difButton_released();
    void on_exiButton_released();
    void on_staButton_released();
    void on_skiButton_released();

private:
    int dif = 1;//难度选择
    GamePage *g = new GamePage;//游戏窗口实例化
    Catalogue c;//技能目录界面
    friend class GamePage;
    void returnToMain();//从游戏界面退回到主界面
    //传递主窗口的选择信息
    void sendInf(){
        g->setDif(dif % 3 - 1);//将难度传递给游戏界面
    }
    Ui::Widget *ui;
};

#endif // WIDGET_H
