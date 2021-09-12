#include "gamepage.h"
#include "ui_gamepage.h"
#include "fireball.h"
#include "monster.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QVector>

void GamePage::generateMonster()
{
    mon[monsterCount].setActive(1);
    //0~5分别对应左上、左中、左下、右上、右中、右下；
    mon[monsterCount].setPosRand(rand() % 6);
    mon[monsterCount].setW(150);
    mon[monsterCount].setH(150);
    //03、14、25分别对应的底线为800、850、900，对应的y为 底线 - h
    int pos = 800 + mon[monsterCount].getPosRand() % 3 * 50  - mon[monsterCount].getH();
    mon[monsterCount].setY(pos);
    //x根据左右朝向来确定
    if (mon[monsterCount].getPosRand() <= 2){
        mon[monsterCount].setX(0);
        mon[monsterCount].setDir(0);//左侧朝右
        mon[monsterCount].setPicMonster(QPixmap(":image/slr0"));
    }
    else{
        mon[monsterCount].setX(1600 - mon[monsterCount].getW());
        mon[monsterCount].setDir(1);//右侧朝左
        mon[monsterCount].setPicMonster(QPixmap(":image/sll0"));
    }

    monsterCount++;
    monsterCount %= 50;
}

GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);

    /*按钮被按下时记录并启动定时器，没有按钮被按下是清楚容器并停止计时器，timeout对应函数中重复检查
    某按键是否处于被按下状态并修改对应参数，与直接在keyPressEvent中检查按钮事件相比，这样的方法
    还支持多个按键同时处于pressed状态下同时进行相应的操作，从而实现移动、攻击、跳跃能同时实现，极
    大提升了游戏的操作手感*/
    //按键判断定时器
    key_timer = new QTimer(this);
    connect(key_timer,&QTimer::timeout,this,&GamePage::onKeytimer);

    //定时调用update重新绘图
    paint_timer = new QTimer(this);
    paint_timer->start(50);
    connect(paint_timer,&QTimer::timeout,
            [=](){
            //重绘计时器中实现火球位置变化
            for (int i = 0;i < 20;i++){
                if (fb[i].getActive()){
                    int temp = fb[i].getX();
                    if (fb[i].getDir() == 0)
                        temp += 20;
                    else
                        temp -= 20;
                    //越界重置
                    if (temp > 1700 || temp < -100){
                        fb[i].unsetActive();
                    }
                    fb[i].setX(temp);
                }
            }
            //重绘计时器中实现怪物位置变化
            for (int i = 0;i < 50;i++){
                if (mon[i].getActive()){
                    int temp = mon[i].getX();
                    if (mon[i].getDir() == 0)
                        mon[i].setX(temp + 5);
                    else
                        mon[i].setX(temp - 5);
                    //越界
                    if (mon[i].getX() < 0 - mon[i].getW() || mon[i].getX() > 1600 )
                        mon[i].setActive(0);
                }
            }


            //定时重绘
            update();
        }
    );

    mon_timer = new QTimer(this);
    mon_timer->start(monInterval);
    connect(mon_timer,&QTimer::timeout,
        [=](){
            generateMonster();
        }
    );
    ui->skill1->setText("<center><h1>Empty Skill</h1></center>");
    ui->skill2->setText("<center><h1>Empty Skill</h1></center>");
    ui->skill3->setText("<center><h1>Empty Skill</h1></center>");
    ui->skill1->setStyleSheet("QLabel{"
                              " color : black;"
                              "text-decoration : underline;"
                              "}");
    ui->skill2->setStyleSheet("QLabel{"
                              " color : black;"
                              "text-decoration : underline;"
                              "}");
    ui->skill3->setStyleSheet("QLabel{"
                              " color : black;"
                              "text-decoration : underline;"
                              "}");
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::onKeytimer(){
    if(pressed_key.contains(Qt::Key_D)){
        dir = 0;
        right_forward++;
        right_forward = right_forward % 4;
        if (x <= 1600)
            x += pace;
        if (x > 1600){
            x = 0;
            int temp = mapCounter;
            while(mapCounter == temp)//防止下一站地图与本张相同
                mapCounter = rand() % 4;
            }
    }
    if(pressed_key.contains(Qt::Key_A)){
        dir = 1;
        left_forward++;
        left_forward = left_forward % 4;
        if (0 <= x)
            x -= pace;
    }

    if(pressed_key.contains(Qt::Key_W)){
        if (y > 650)
            y -= 50;
    }
    if(pressed_key.contains(Qt::Key_S)){
        if (y < 750)
            y += 50;
    }

    if(pressed_key.contains(Qt::Key_K)){
        isSwordShown = 1;
    }

}

void GamePage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //绘画背景地图
    QPixmap bg;
    if (mapCounter == 0)
        bg = QPixmap(":image/bg1.png");
    if (mapCounter == 1)
        bg = QPixmap(":image/bg2.png");
    if (mapCounter == 2)
        bg = QPixmap(":image/bg3.jpg");
    if (mapCounter == 3)
        bg = QPixmap(":image/bg4.jpg");
    p.drawPixmap(rect(),bg);

    //绘制技能栏背景
    p.drawPixmap(0,50,400,350,QPixmap(":image/bgskill.png"));
    //绘画血条背景
    p.drawPixmap(0,0,(hp - difficulty) * 60,70,QPixmap(":/image/bghp.png"));

    //绘画第一关的介绍
    if (mapCounter == 0){
        ui->introduce->setText(QString("<center><h1>"
                                       "press WASD to move <br><br>"
                                       "prese J/K to attack <br><br>"
                                       "press U/I/O to use existing skills <br><br>"
                                       "</h1></center>"));
    }
    else {
        ui->introduce->setText("");
    }

    //绘制上层的怪物
    for (int i = 0;i < 50;i++){
        //是否为上层
        if (mon[i].getPosRand() % 3 == 0){
            //根据当前帧设置对应图片
            int temp = mon[i].getPicFrame();
            temp = temp % 3;
            if (temp == 0){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor0"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol0"));
                }
            }
            if (temp == 1){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor1"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol1"));
                }
            }
            if (temp == 2){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor2"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol2"));
                }
            }
            mon[i].setPicFrame(temp + 1);//帧数加一
            //遍历绘图
            if (mon[i].getActive()){
                p.drawPixmap(mon[i].getX(),mon[i].getY(),mon[i].getW(),mon[i].getH(),mon[i].getPicMonster());
            }
        }
    }

    //绘制中层的怪物
    for (int i = 0;i < 50;i++){
        //是否为中层
        if (mon[i].getPosRand() % 3 == 1){
            //根据当前帧设置对应图片
            int temp = mon[i].getPicFrame();
            temp = temp % 3;
            if (temp == 0){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor0"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol0"));
                }
            }
            if (temp == 1){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor1"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol1"));
                }
            }
            if (temp == 2){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor2"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol2"));
                }
            }
            mon[i].setPicFrame(temp + 1);//帧数加一
            //遍历绘图
            if (mon[i].getActive()){
                p.drawPixmap(mon[i].getX(),mon[i].getY(),mon[i].getW(),mon[i].getH(),mon[i].getPicMonster());
            }
        }
    }

    //绘画角色
    QPixmap ch;
    if (dir == 0){
        if (right_forward == 0)
            ch = QPixmap(":image/r0.png");
        if (right_forward == 1)
            ch = QPixmap(":image/r1.png");
        if (right_forward == 2)
            ch = QPixmap(":image/r2.png");
        if (right_forward == 3)
            ch = QPixmap(":image/r3.png");
    }
    else{
        if (left_forward == 0)
            ch = QPixmap(":image/l0.png");
        if (left_forward == 1)
            ch = QPixmap(":image/l1.png");
        if (left_forward == 2)
            ch = QPixmap(":image/l2.png");
        if (left_forward == 3)
            ch = QPixmap(":image/l3.png");
    }
    p.drawPixmap(x,y,100,150,ch);

    //绘画底层怪物怪物
    for (int i = 0;i < 50;i++){
        //是否为底层
        if (mon[i].getPosRand() % 3 == 2){
            //根据当前帧设置对应图片
            int temp = mon[i].getPicFrame();
            temp = temp % 3;
            if (temp == 0){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor0"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol0"));
                }
            }
            if (temp == 1){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor1"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol1"));
                }
            }
            if (temp == 2){
                if (mon[i].getDir() == 0){
                    mon[i].setPicMonster(QPixmap(":image/gor2"));
                }
                else{
                    mon[i].setPicMonster(QPixmap(":image/gol2"));
                }
            }
            mon[i].setPicFrame(temp + 1);//帧数加一
            //遍历绘图
            if (mon[i].getActive()){
                p.drawPixmap(mon[i].getX(),mon[i].getY(),mon[i].getW(),mon[i].getH(),mon[i].getPicMonster());
            }
        }
    }

    //绘画血量：困难1血，普通2血，简单3血
    for (int i = 0,l = 0;i < hp - difficulty;i++,l += 60){
        p.drawPixmap(l,0,50,50,QPixmap(":image/hp.png"));
    }

    //绘画火球攻击
    QPixmap img_fb;
    if (attack){
        //便利火球数组输出当前场上的火球
        for (int i = 0;i < 20;i++){
            if (fb[i].getActive()){
                if (fb[i].getDir() == 0)
                    img_fb = QPixmap(":image/fbr.png");
                else
                    img_fb = QPixmap(":image/fbl.png");
                p.drawPixmap(fb[i].getX(),fb[i].getY(),150,150,img_fb);
            }
        }
    }

    //绘画近身攻击
    QPixmap near_attack;
    int swordx = x;
    if(isSwordShown){
        if (dir == 0){
            near_attack = QPixmap(":image/swordr.png");
            swordx += 50;
        }
        else{
            near_attack = QPixmap(":image/swordl.png");
            swordx -= 100;
        }
        p.drawPixmap(swordx,y,150,150,near_attack);
        isSwordShown = 0;
    }
}

void GamePage::keyPressEvent(QKeyEvent *event)
{
    //记录被按下的移动键
    pressed_key.append(static_cast<Qt::Key>(event->key()));
    if(!key_timer->isActive()) {
           key_timer->start(50);
    }

    //攻击键
    if(pressed_key.contains(Qt::Key_J)){
        if (dir == 0){
            fb[fireballCount % 20].setX(x+50);
            fb[fireballCount % 20].setY(y);
            fb[fireballCount % 20].setDir(0);
        }
        else{
            fb[fireballCount % 20].setX(x-100);
            fb[fireballCount % 20].setY(y);
            fb[fireballCount % 20].setDir(1);
        }
        fb[(fireballCount % 20)].setActive();
        fireballCount++;
        attack = 1;
    }

    //退回到主界面并重置所有gamepage元素
    if (event->key() == Qt::Key_Escape){
        key_timer->stop();
        quitAndReset();
    }
}

void GamePage::keyReleaseEvent(QKeyEvent *event)
{
    if(key_timer->isActive() && pressed_key.isEmpty()){
        key_timer->stop();
        onKeytimer();
    }
    pressed_key.removeAll(static_cast<Qt::Key>(event->key()));
}

void GamePage::quitAndReset()
{
    emit quitToMain();
}

//退出游戏界面并重置游戏要素
//注意及时更新需要重置的游戏要素

