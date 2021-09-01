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
    void setDif(int x){difficulty = x;};
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
protected:
    void onKeytimer();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QTimer *paint_timer;//重绘计时器
    QTimer *key_timer;//遍历键盘计时器
    QVector<Qt::Key> pressed_key;
    int mapCounter = 0;//用于决定下一关卡地图
    int difficulty = 0;//难度
    int hp = 3;//人物血量
    int x = 0;//人物坐标
    int y = 700;//人物坐标
    int pace = 30;//人物速度
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
