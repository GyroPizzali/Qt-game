#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QTimer>
#include <QVector>
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
    void generateMonster();

    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
protected:
    void onKeytimer();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void quitToMain();//返回主界面的信号
private:
    QTimer *paint_timer;//重绘计时器
    QTimer *key_timer;//遍历键盘计时器
    QTimer *mon_timer;//定时刷新怪物
    QVector<Qt::Key> pressed_key;
    int mapCounter = 0;//用于决定下一关卡地图
    int difficulty = 0;//难度

    //直接把角色属性放到游戏界面类来
    int hp = 3;//人物血量
    int x = 0;//人物坐标
    int y = 700;//人物坐标
    int dir = 0;//人物朝向， 右0左1
    int pace = 30;//人物速度

    bool attack = 0;//是否火球攻击
    fireball fb[20];//火球攻击
    int fireballCount = 0;//火球计数器
    int left_forward = 0;//左走动作帧
    int right_forward = 0;//右走动作帧

    bool isSwordShown = 0;//是否近战攻击
    QTimer *sword_timer;//刀光计时器

    Monster mon[50];//怪物
    int monsterCount = 0;//怪物计数器
    int monInterval = 3000;//怪物刷新的时间间隔
    int monRemain = 10;


    Item item[50];//道具

    void quitAndReset();//退回主界面并且重置游戏要素
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
