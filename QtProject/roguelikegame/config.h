#ifndef CONFIG_H
#define CONFIG_H
//怪物资源设置
//怪物一(每个怪物分左右）
#define SLIME_PATH1  ":image/sll%1.png" //怪物图片路径，百分号内容可替换
#define SLIME_MAX1   2//怪物图片帧数
#define SLIME_PATH2  ":image/slr%1.png"
#define SLIME_MAX2   2
//怪物二
#define ALIEN_PATH1  ":image/alienl.png"
#define ALIEN_MAX1   1
#define ALIEN_PATH2  ":image/alienr.png"
#define ALIEN_MAX2   1
//怪物三
#define GOBLIN_PATH1 ":image/gol%1.png"
#define GOBLIN_MAX1   3
#define GOBLIN_PATH2  ":image/gor%1.png"
#define GOBLIN_MAX2   3

//主角图片
#define HERO_PATH1  ":image/l%1.png"
#define HERO_PATH2  ":image/r%1.png"
#define HERO_PATH3  ":image/front0.png"
#define HERO_PATH4  ":image/back.png"

//主角攻击技能
//火球
#define HERO_FIREBALL_PATH1 ":image/fbl.png"
#define HERO_FIREBALL_PATH2 ":image/fbr.png"
//基础属性
#define HERO_HP 3 //初始生命值
#define HERO_SPEED 30 //初始速度

//主界面背景图
#define MAP_PATH  ":image/bg.png"

//地图资源设置
#define MAP_PATH1 ":image/bg1.png"
#define MAP_PATH2 ":image/bg2.png"
#define MAP_PATH3 ":image/bg3.png"
#define MAP_PATH4 ":image/bg4.png"
#define MAP_BOSS_PATH ":image/bossbg.gif"

#endif // CONFIG_H
