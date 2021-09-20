#include "gamepage.h"
#include "ui_gamepage.h"
#include "fireball.h"
#include "monster.h"
#include "slime.h"
#include "goblin.h"
#include "alien.h"
#include "config.h"
#include "time.h"
#include <math.h>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QKeyEvent>
#include <QDebug>
#include <QRect>
#include <QTimer>
#include <QVector>

void GamePage::generateMonster()
{
    //游戏是否已经开始
    if(startGenerate){
        //根据关卡数目逐渐减少刷怪的时间间隔
        //分数未达要求前不断刷新怪物
        if (killNum < passLine){
            monsterCount %= pointerSize;

            //随机决定怪物类型
            int type = rand() % 3;
            if (type == 0)
                mon[monsterCount] = new Slime;
            if (type == 1)
                mon[monsterCount] = new Goblin;
            if (type == 2)
                mon[monsterCount] = new Alien;
            mon[monsterCount]->setActive(1);//激活
            //根据类型改变属性
            mon[monsterCount]->resetSize();
            mon[monsterCount]->resetHp();
            mon[monsterCount]->resetSpeed();
            //根据关卡数增加血量,每过一关血量加一
            int temphp = mon[monsterCount]->getHp();
            int temphpmax = mon[monsterCount]->getHp();
            mon[monsterCount]->setHp_max(temphpmax + presentMap);
            mon[monsterCount]->setHp(temphp + presentMap);
            //随机决定起始位置与方向
            mon[monsterCount]->setPosRand(rand() % 6);
            mon[monsterCount]->setW(150);
            mon[monsterCount]->setH(150);
            //03、14、25分别对应的底线为800、850、900，对应的y为 底线 - h
            int pos;
            if (mon[monsterCount]->getPosRand() % 3 == 0)
                pos = 800 - mon[monsterCount]->getH();
            if (mon[monsterCount]->getPosRand() % 3 == 1)
                pos = 850 - mon[monsterCount]->getH();
            if (mon[monsterCount]->getPosRand() % 3 == 2)
                pos = 900 - mon[monsterCount]->getH();
            mon[monsterCount]->setY(pos);
            //x根据左右朝向来确定
            if (mon[monsterCount]->getPosRand() <= 2){
                mon[monsterCount]->setX(0);
                mon[monsterCount]->setDir(0);//左侧朝右
            }
            else{
               mon[monsterCount]->setX(1600 - mon[monsterCount]->getW());
               mon[monsterCount]->setDir(1);//右侧朝左
            }

            monsterCount++;//累计产生的怪物数量加一
        }
    }

}

void GamePage::setRandAward()
{
    int r;
    for (int i = 0;i < 3;){
        srand( (unsigned)time( NULL ) );
        r = rand() % 5;
        if (itemAward.contains(r))
            continue;
        else {
            itemAward.push_back(r);
            i++;
        }
    }
}

GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);

    ui->lcdNumber->setDigitCount(2);
    ui->lcdNumber->setMode(QLCDNumber::Dec);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->setStyleSheet("QLCDNumber{"
                                 "color : white;"
                                 "}");
    this->setWindowTitle("Sword and Magic");

    //技能图标矩形初始化
    skillU.setX(0);
    skillU.setY(60);
    skillU.setWidth(80);
    skillU.setHeight(80);

    skillI.setX(90);
    skillI.setY(60);
    skillI.setWidth(80);
    skillI.setHeight(80);

    skillO.setX(180);
    skillO.setY(60);
    skillO.setWidth(80);
    skillO.setHeight(80);

    //设置随机奖励
    setRandAward();
    //初始化第一关奖励
    itemp.setPicItem(QString(SKILL_PATH).arg(itemAward[presentMap]));
    itemp.setN(itemAward[presentMap]);
    itemp.updateRect();


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
        ui->lcdNumber->display(killNum);
        //定时重绘
        update();
    });

    //怪物定时生成
    mon_timer = new QTimer(this);
    mon_timer->start(monInterval);
    connect(mon_timer,&QTimer::timeout,
    [=](){
        generateMonster();
    });

    //定时更新碰撞模型
    rect_timer = new QTimer(this);
    rect_timer->start(50);
    connect(rect_timer,&QTimer::timeout,
    [=](){
        //更新人物模型
        hero.updataRect();

        //更新怪物位置变化并更新怪物模型
        for (int i = 0;i < monsterCount;i++){
            //判定技能0
            if (hero.skillRelease[0] == 0){
                if (mon[i]->getActive()){
                    int temp = mon[i]->getX();
                    if (mon[i]->getDir() == 0)
                        mon[i]->setX(temp + mon[i]->getSpeed());
                    else
                        mon[i]->setX(temp - mon[i]->getSpeed());
                    //越界
                    if (mon[i]->getX() < 0 - mon[i]->getW() || mon[i]->getX() > 1600)
                        mon[i]->setActive(0);
                }
                mon[i]->updataRect();
                mon[i]->updataRect();
                mon[i]->updataRect();
                mon[i]->updataRect();
            }

        }

        //更新火球位置变化
        //技能3判断
        if (hero.skillRelease[3] == 1){
            for (int i = 0;i < 30;i++)
                hero.firebag[i].setV(80);
        }
        for (int i = 0;i < 30;i++){
            if (hero.firebag[i].getActive()){
                int temp = hero.firebag[i].getX();
                if (hero.firebag[i].getDir() == 0)
                    temp += hero.firebag[i].getV();
                else
                    temp -= hero.firebag[i].getV();
                //越界重置
                if (temp > 1700 || temp < -100){
                    hero.firebag[i].unsetActive();
                }
                hero.firebag[i].setX(temp);
            }
        }

        //更新火球模型并判断火球攻击
        for (int i = 0;i < 30;i++){
            if (hero.firebag[i].getActive()){
                 hero.firebag[i].updateRect();
                 hero.firebag[i].updateRect();
                 hero.firebag[i].updateRect();
                 hero.firebag[i].updateRect();
                 for (int j = 0;j < monsterCount;j++){
                     if (mon[j] != nullptr && mon[j]->getActive() && hero.firebag[i].getPos() == (mon[j]->getPosRand() % 3) && hero.firebag[i].getFireballRect().intersects(mon[j]->getMonsterRect())){
                         //判断穿透技能的效果
                         if (hero.skillRelease[4] == 0)
                            hero.firebag[i].unsetActive();
                         int temp = mon[j]->getHp();
                         if (temp == 1){
                             mon[j]->setActive(0);
                             killNum++;
                         }
                         else
                             mon[j]->setHp(temp - 1);
                     }
                 }
            }
        }

        //判定近战攻击
        if (hero.isSwordShown){
            int swordx;
            if (hero.dir == 0)
                swordx = hero.x + 50;
            else
                swordx = hero.x - 100;

            //构造打击模型
            QRect swordRect(swordx,hero.y,150,150);
            for (int i = 0;i < monsterCount;i++){
                if (mon[i] != nullptr && mon[i]->getActive() && mon[i]->getMonsterRect().intersects(swordRect) && hero.pos == mon[i]->getPosRand() % 3){
                    int temp = mon[i]->getHp();
                    if (mon[i]->getHp() <= 3){
                        mon[i]->setActive(0);
                        killNum += 3;
                    }
                    else
                        mon[i]->setHp(temp - 3);
                }
            }
        }


        //判定技能1
        for (int i = 0;i < monsterCount;i++){
            if (mon[i] != nullptr && mon[i]->getActive() && hero.skillRelease[1]){
                int temp = mon[i]->getHp();
                if (temp == 1){
                    mon[i]->setActive(0);
                    killNum++;
                }
                else {
                    mon[i]->setHp(temp - 1);
                }
            }
        }


        //判断怪物与人物的碰撞
        for (int i = 0;i < monsterCount;i++){
            if (mon[i]->getActive()){
                if(mon[i]->getMonsterRect().intersects(hero.hero_rect) && hero.pos == mon[i]->getPosRand() % 3){
                    //技能2的无敌判定
                    if (hero.skillRelease[2] == 0){
                        hero.hp--;
                        mon[i]->setActive(0);
                    }
                }
            }
        }

        //判断角色捡起奖励
        if (hero.itemBag.size() < (presentMap + 1) && killNum >= passLine && (hero.hero_rect.intersects(itemp.getItemRect()))){
            itemp.hide();
            hero.itemBag.push_back(itemp);
        }
    });
}

GamePage::~GamePage()
{
    delete ui;
}

void GamePage::onKeytimer(){
    if (pressed_key.contains(Qt::Key_D)){
        hero.dir = 0;
        hero.right_forward++;
        hero.right_forward = hero.right_forward % 4;
        if (hero.x <= 1600 - hero.w)
            hero.x += hero.speed;
        if (hero.x > 1600 - hero.w){
            //求出场上剩余怪物数量
            for (int i = 0;i < monsterCount;i++){
                if (mon[i]->getActive())
                    presenMonster++;
            }
            //积分足够且没有剩余怪物时
            if(killNum >= passLine && presenMonster == 0){
                //人物位置重置
                hero.x = 0;
                //怪物刷新间隔减短
                if (monInterval > 200)
                    monInterval -= 100;
                //背景地图重置
                int temp = mapCounter;
                while(mapCounter == temp)//防止下一站地图与本张相同
                    mapCounter = rand() % 4;
                //关卡计数加一
                presentMap++;
                //得分置零
                killNum = 0;
                //当前关卡奖励重置
                if (presentMap <= 2){
                    itemp.setPicItem(QString(SKILL_PATH).arg(itemAward[presentMap]));
                    itemp.setN(itemAward[presentMap]);
                    itemp.show();
                    itemp.updateRect();
                }
            }
            presenMonster = 0;
        }
    }
    if (pressed_key.contains(Qt::Key_A)){
        hero.dir = 1;
        hero.left_forward++;
        hero.left_forward = hero.left_forward % 4;
        if (0 <= hero.x)
            hero.x -= hero.speed;
    }

    hero.isUp = pressed_key.contains(Qt::Key_W);
    if (hero.isUp){
        if (hero.y > 650)
            hero.y -= 50;
        //设置人物所在层数
        if (hero.y == 650)
            hero.pos = 0;
        if (hero.y == 700)
            hero.pos = 1;
        if (hero.y == 750)
            hero.pos = 2;
    }
    hero.isDown = pressed_key.contains(Qt::Key_S);
    if (hero.isDown){
        if (hero.y < 750)
            hero.y += 50;
        //设置人物所在层数
        if (hero.y == 650)
            hero.pos = 0;
        if (hero.y == 700)
            hero.pos = 1;
        if (hero.y == 750)
            hero.pos = 2;
    }

    if (pressed_key.contains(Qt::Key_K)){
        hero.isSwordShown = 1;
    }

    //U技能判定
    if (pressed_key.contains(Qt::Key_U)){
        if (hero.itemBag.size() >= 1){
            hero.skillRelease[hero.itemBag[0].getN()]++;
            if (hero.itemBag[0].getN() == 2){
                if (hero.dir == 0)
                    hero.x += 200;
                else
                    hero.x -= 200;
                if (hero.x > 1600 - hero.w)
                    hero.x = 1600 - hero.w;
                if (hero.x < 0)
                    hero.x = 0;
            }
        }
    }
    if (pressed_key.contains(Qt::Key_U) == 0){
        if (hero.itemBag.size() >= 1){
            if (hero.itemBag[0].getN() <= 2)
                hero.skillRelease[hero.itemBag[0].getN()] = 0;
        }
    }

    //I技能判定
    if (pressed_key.contains(Qt::Key_I)){
        if (hero.itemBag.size() >= 2){
            hero.skillRelease[hero.itemBag[1].getN()]++;
            if (hero.itemBag[1].getN() == 2){
                if (hero.dir == 0)
                    hero.x += 200;
                else
                    hero.x -= 200;
                if (hero.x > 1600 - hero.w)
                    hero.x = 1600 - hero.w;
                if (hero.x < 0)
                    hero.x = 0;
            }
        }
    }
    if (pressed_key.contains(Qt::Key_I) == 0){
        if (hero.itemBag.size() >= 2){
            if (hero.itemBag[1].getN() <= 2)
                hero.skillRelease[hero.itemBag[1].getN()] = 0;
        }
    }

    //O技能判定
    if (pressed_key.contains(Qt::Key_O)){
        if (hero.itemBag.size() >= 3){
            hero.skillRelease[hero.itemBag[2].getN()]++;
            if (hero.itemBag[2].getN() == 2){
                if (hero.dir == 0)
                    hero.x += 200;
                else
                    hero.x -= 200;
                if (hero.x > 1600 - hero.w)
                    hero.x = 1600 - hero.w;
                if (hero.x < 0)
                    hero.x = 0;
            }
        }
    }
    if (pressed_key.contains(Qt::Key_O) == 0){
        if (hero.itemBag.size() >= 3){
            if (hero.itemBag[2].getN() <= 2)
                hero.skillRelease[hero.itemBag[2].getN()] = 0;
        }
    }


//以下为演示外挂模式！
//    //U技能判定
//    if (pressed_key.contains(Qt::Key_U)){
//        hero.skillRelease[0]++;
//    }
//    else{
//        hero.skillRelease[0] = 0;
//    }

//    //I技能判定
//    if(pressed_key.contains(Qt::Key_I)){
//        hero.skillRelease[1]++;
//    }
//    else {
//        hero.skillRelease[1] = 0;
//    }

//    //O技能判定
//    if (pressed_key.contains(Qt::Key_O)){
//        hero.skillRelease[2] = 1;
//        if (hero.dir == 0)
//            hero.x += 200;
//        else
//            hero.x -= 200;
//        if (hero.x > 1600 - hero.w)
//            hero.x = 1600 - hero.w;
//        if (hero.x < 0)
//            hero.x = 0;
//    }
//    else{
//        hero.skillRelease[2] = 0;
//    }
//    //P技能判定
//    if (pressed_key.contains(Qt::Key_P)){
//        hero.skillRelease[3] = 1;
//        for (int i = 0;i < 30;i++)
//            hero.firebag[i].setV(80);
//    }
//    else {
//        hero.skillRelease[3] = 0;
//        for (int i = 0;i < 30;i++)
//            hero.firebag[i].setV(20);
//    }
//    //L技能判定
//    if (pressed_key.contains(Qt::Key_L)){
//        hero.skillRelease[4] = 1;
//    }
//    else {
//        hero.skillRelease[4] = 0;
//    }


}

void GamePage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen;


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
    QPen skillpen;
    skillpen.setStyle(Qt::DashDotDotLine);
    skillpen.setColor(Qt::white);
    skillpen.setWidth(5);

    if (hero.itemBag.size() >= 1 && hero.skillRelease[hero.itemBag[0].getN()])
        skillpen.setColor(Qt::red);
    p.setPen(skillpen);
    p.drawRect(skillU);

    skillpen.setColor(Qt::white);
    if (hero.itemBag.size() >= 2 && hero.skillRelease[hero.itemBag[1].getN()])
        skillpen.setColor(Qt::red);
    p.setPen(skillpen);
    p.drawRect(skillI);

    skillpen.setColor(Qt::white);
    if (hero.itemBag.size() >= 3 && hero.skillRelease[hero.itemBag[2].getN()])
        skillpen.setColor(Qt::red);
    p.setPen(skillpen);
    p.drawRect(skillO);

    if (hero.itemBag.size() >= 1)
        p.drawPixmap(skillU,hero.itemBag[0].getPicItem());
    if (hero.itemBag.size() >= 2)
        p.drawPixmap(skillI,hero.itemBag[1].getPicItem());
    if (hero.itemBag.size() >= 3)
        p.drawPixmap(skillO,hero.itemBag[2].getPicItem());
    p.drawText(skillU,QString("U"));
    p.drawText(skillI,QString("I"));
    p.drawText(skillO,QString("O"));

    //绘画过关奖励
    if (killNum >= passLine && itemp.getIsShow()){
        p.drawRect(itemp.getItemRect());
        p.drawPixmap(itemp.getItemRect(),itemp.getPicItem());
    }

    //绘画血条背景
    p.drawPixmap(0,0,(hero.hp - difficulty) * 60,70,QPixmap(":/image/bghp.png"));

    //绘画第一关的介绍
    if (mapCounter == 0 && presentMap == 0){
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
    for (int i = 0;i < monsterCount;i++){
        if (mon[i]->getActive() && mon[i]->getPosRand() % 3 == 0){
            int temp = mon[i]->getPicFrame() % mon[i]->getFrameSize();
            //未知bug导致picframe是负数
            if (temp < 0)
                temp = 0;
//            qDebug() << mon[i]->getPicFrame() <<" " << temp <<" " << mon[i]->getFrameSize();

            if (mon[i]->getDir() == 0){
                mon[i]->setPicMonster(mon[i]->getRightpic(temp));
            }
            else {
                mon[i]->setPicMonster(mon[i]->getLeftpic(temp));
            }

            //帧数计数加一，判定技能0
            if (hero.skillRelease[0] == 0)
                mon[i]->setPicFrame(temp + 1);

//            p.drawRect(mon[i]->getMonsterRect());

            p.drawPixmap(mon[i]->getX(),mon[i]->getY(),mon[i]->getW(),mon[i]->getH(),mon[i]->getPicMonster());
        } 
    }

    //绘制中层的怪物
    for (int i = 0;i < monsterCount;i++){
        if (mon[i]->getActive() && mon[i]->getPosRand() % 3 == 1){
            int temp = mon[i]->getPicFrame() % mon[i]->getFrameSize();
            //未知bug导致picframe是负数
            if (temp < 0)
                temp = 0;
//            qDebug() << mon[i]->getPicFrame() <<" " << temp <<" " << mon[i]->getFrameSize();

            if (mon[i]->getDir() == 0){
                mon[i]->setPicMonster(mon[i]->getRightpic(temp));
            }
            else {
                mon[i]->setPicMonster(mon[i]->getLeftpic(temp));
            }

            //帧数计数加一，判定技能0
            if (hero.skillRelease[0] == 0)
                mon[i]->setPicFrame(temp + 1);

//            p.drawRect(mon[i]->getMonsterRect());

            p.drawPixmap(mon[i]->getX(),mon[i]->getY(),mon[i]->getW(),mon[i]->getH(),mon[i]->getPicMonster());
        }
    }

    //绘画角色
    QPixmap ch;
        //优先绘画上下动作
    if (hero.isUp || hero.isDown){
        if (hero.isUp)
            ch = QPixmap(QString(HERO_PATH4));
        if (hero.isDown)
            ch = QPixmap(QString(HERO_PATH3));
    }
    else{
        if (hero.dir)
            ch = QPixmap(QString(HERO_PATH1).arg(hero.left_forward));
        else
            ch = QPixmap(QString(HERO_PATH2).arg(hero.right_forward));
    }
//    p.drawRect(hero.hero_rect);
    p.drawPixmap(hero.x,hero.y,hero.w,hero.h,ch);

    //绘画底层怪物怪物
    for (int i = 0;i < monsterCount;i++){
        if (mon[i]->getActive() && mon[i]->getPosRand() % 3 == 2){
            int temp = mon[i]->getPicFrame() % mon[i]->getFrameSize();
            //未知bug导致picframe是负数
            if (temp < 0)
                temp = 0;
//            qDebug() << mon[i]->getPicFrame() <<" " << temp <<" " << mon[i]->getFrameSize();

            if (mon[i]->getDir() == 0){
                mon[i]->setPicMonster(mon[i]->getRightpic(temp));
            }
            else {
                mon[i]->setPicMonster(mon[i]->getLeftpic(temp));
            }

            //帧数计数加一，判定技能0
            if (hero.skillRelease[0] == 0)
                mon[i]->setPicFrame(temp + 1);

//            p.drawRect(mon[i]->getMonsterRect());

            p.drawPixmap(mon[i]->getX(),mon[i]->getY(),mon[i]->getW(),mon[i]->getH(),mon[i]->getPicMonster());
        }
    }

    //绘画血量：困难1血，普通2血，简单3血
    for (int i = 0,l = 0;i < hero.hp - difficulty;i++,l += 60){
        p.drawPixmap(l,0,50,50,QPixmap(":image/hp.png"));
    }

    //绘画火球攻击
    QPixmap img_fb;
    if (hero.attack){
        //便利火球数组输出当前场上的火球
        for (int i = 0;i < 30;i++){
            if (hero.firebag[i].getActive()){
                if (hero.skillRelease[4] == 0){
                    if (hero.firebag[i].getDir() == 0)
                        img_fb = QPixmap(":image/fbr.png");
                    else
                        img_fb = QPixmap(":image/fbl.png");
                }
                //若技能4生效
                else {
                    if (hero.firebag[i].getDir() == 0)
                        img_fb = QPixmap(":image/s4r.png");
                    else
                        img_fb = QPixmap(":image/s4l.png");
                }


//                p.drawRect(hero.firebag[i].getFireballRect());

                p.drawPixmap(hero.firebag[i].getX(),hero.firebag[i].getY(),150,150,img_fb);
            }
        }
    }

    //绘画近身攻击
    QPixmap near_attack;
    int swordx = hero.x;
    if(hero.isSwordShown){
        if (hero.dir == 0){
            near_attack = QPixmap(":image/swordr.png");
            swordx += 50;
        }
        else{
            near_attack = QPixmap(":image/swordl.png");
            swordx -= 100;
        }
        p.drawPixmap(swordx,hero.y,150,150,near_attack);
        hero.isSwordShown = 0;
    }

    //绘画怪物血条
    for (int i = 0;i < monsterCount;i++){
        if (mon[i]->getActive()){
            //绘制边框
            float temp = mon[i]->getHp();
            temp = temp / mon[i]->getHp_max();
            temp *= 150;
            pen.setWidth(5);
            pen.setColor(Qt::black);
            p.setPen(pen);
            p.drawRect(mon[i]->getX(),mon[i]->getY() - 20,temp,20);
            QBrush bru1(Qt::green);
            QBrush bru2(Qt::blue);
            if (hero.skillRelease[0] == 0)
                p.setBrush(bru1);
            else {
                p.setBrush(bru2);
            }
            p.drawRect(mon[i]->getX(),mon[i]->getY() - 20,temp,20);

//            //绘制血条
//            pen.setWidth(10);
//            if (hero.skillRelease[0])
//                pen.setColor(Qt::blue);
//            else
//                pen.setColor(Qt::green);
//            p.setPen(pen);
//            int hp_len = (mon[i]->getW() - 10 ) / mon[i]->getHp_max() * mon[i]->getHp();
//            if(mon[i]->getHp())
//                p.drawRect(mon[i]->getX() + 5,mon[i]->getY() - 15,hp_len,10);
        }

    }

    //绘画技能特效
    if (hero.skillRelease[1]){
        p.drawPixmap(-250,-100,2200,1400,QPixmap(QString(SKILL_PATH1).arg(hero.skillRelease[1] % 6)));
    }

    //绘制死亡界面
    if (hero.hp - difficulty == 0)
        p.drawPixmap(rect(),QPixmap(":image/gameover.png"));

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
        if (hero.skillRelease[3] == 0){
            if (hero.dir == 0){
                hero.firebag[hero.fireballCount % 30].setX(hero.x+50);
                hero.firebag[hero.fireballCount % 30].setY(hero.y);
                hero.firebag[hero.fireballCount % 30].setDir(0);
            }
            else{
                hero.firebag[hero.fireballCount % 30].setX(hero.x-100);
                hero.firebag[hero.fireballCount % 30].setY(hero.y);
                hero.firebag[hero.fireballCount % 30].setDir(1);
            }
            hero.firebag[hero.fireballCount % 30].setPos(hero.pos);
            hero.firebag[(hero.fireballCount % 30)].setActive();
            hero.fireballCount++;
            hero.attack = 1;
        }
        //判定技能3
        else {
            if (hero.dir == 0){
                hero.firebag[hero.fireballCount % 30].setX(hero.x+50);
                hero.firebag[hero.fireballCount % 30].setY(650);
                hero.firebag[hero.fireballCount % 30].setDir(0);

                hero.firebag[(hero.fireballCount + 1) % 30].setX(hero.x+50);
                hero.firebag[(hero.fireballCount + 1) % 30].setY(700);
                hero.firebag[(hero.fireballCount + 1) % 30].setDir(0);

                hero.firebag[(hero.fireballCount + 2) % 30].setX(hero.x+50);
                hero.firebag[(hero.fireballCount + 2) % 30].setY(750);
                hero.firebag[(hero.fireballCount + 2) % 30].setDir(0);
            }
            else{
                hero.firebag[hero.fireballCount % 30].setX(hero.x-100);
                hero.firebag[hero.fireballCount % 30].setY(650);
                hero.firebag[hero.fireballCount % 30].setDir(1);

                hero.firebag[(hero.fireballCount + 1) % 30].setX(hero.x-100);
                hero.firebag[(hero.fireballCount + 1) % 30].setY(700);
                hero.firebag[(hero.fireballCount + 1) % 30].setDir(1);

                hero.firebag[(hero.fireballCount + 2) % 30].setX(hero.x-100);
                hero.firebag[(hero.fireballCount + 2) % 30].setY(750);
                hero.firebag[(hero.fireballCount + 2) % 30].setDir(1);
            }
            hero.firebag[hero.fireballCount % 30].setPos(0);
            hero.firebag[(hero.fireballCount + 1) % 30].setPos(1);
            hero.firebag[(hero.fireballCount + 2) % 30].setPos(2);

            hero.firebag[(hero.fireballCount % 30)].setActive();
            hero.firebag[(hero.fireballCount + 1) % 30].setActive();
            hero.firebag[(hero.fireballCount + 2) % 30].setActive();

            hero.fireballCount += 3;
            hero.attack = 1;
        }
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

