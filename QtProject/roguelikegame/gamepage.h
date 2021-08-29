#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QTimer>
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
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QTimer *paint_timer;
    int difficulty = 0;//难度
    int mapCounter = 0;//用于决定下一关卡地图
    int hp = 3 - difficulty;//人物血量
    int x = 0;//人物坐标
    int y = 700;//人物坐标
    int pace = 40;//人物速度
    bool attack = 0;//是否攻击
    fireball fb[20];//火球攻击
    int fireballCount = 0;//火球计数器
    int left_forward = 0;//左走动作帧
    int right_forward = 0;//右走动作帧
    int dir = 0;//人物朝向， 右0左1
    Monster mon[50];//怪物
    Item item[50];//道具
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
