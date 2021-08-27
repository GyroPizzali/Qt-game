#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>

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
    int mapCounter = 0;//用于决定下一关卡地图
    int hp = 3;//人物血量
    int x = 0;//人物坐标
    int y = 600;//人物坐标
    int pace = 40;//人物速度
    int left_forward = 0;//左走动作帧
    int right_forward = 0;//右走动作帧
    int dir = 0;//人物朝向， 右0左1
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
