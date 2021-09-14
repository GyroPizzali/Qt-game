#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include "hero.h"
#include "fireball.h"
#include "monster.h"
#include "item.h"
namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT
public:
    void setDif(int x){difficulty = x;};//在widget中作为友元函数来修改本类中的难度
    void generateMonster();//怪物生成函数

    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
protected:
    void onKeytimer();
    //事件
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void quitToMain();//返回主界面的信号
private:
    QTimer *paint_timer;//重绘计时器
    QTimer *key_timer;//遍历键盘计时器
    QTimer *mon_timer;//定时刷新怪物计时器
    QTimer *rect_timer;//定时更新rect模型
    QVector<Qt::Key> pressed_key;//存储正在被按下的键
    int mapCounter = 0;//用于决定下一关卡地图
    int difficulty = 0;//难度

    Hero hero;//主角

    Monster *mon[2000];//怪物基类指针
    int monsterCount = 0;//怪物计数器
    int monInterval = 3000;//怪物刷新的时间间隔

    Item item[50];//道具

    void quitAndReset();//退回主界面并且重置游戏要素
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
