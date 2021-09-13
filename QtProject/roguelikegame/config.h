#ifndef CONFIG_H
#define CONFIG_H
//怪物资源设置
//怪物一(每个怪物分左右）
#define MONSTER_PATH1  "://image/sll%1.png" //怪物图片路径，百分号内容可替换
#define MONSTER_MAX1   2//怪物图片帧数
#define MONSTER_PATH2  "://image/slr0.png"
#define MONSTER_MAX2   2
//怪物二
#define MONSTER_PATH1 "://../image/alienl.png"
#define MONSTER_MAX1   1
#define MONSTER_PATH2  "://../image/alienr.png"
#define MONSTER_MAX2   1
//怪物三
#define MONSTER_PATH1 "://../image/gol%1.png"
#define MONSTER_MAX1   3
#define MONSTER_PATH2  "://../image/gor%1.png"
#define MONSTER_MAX2   3



//主角攻击技能
//火球
#define HERO_FIREBALL_PATH1 "://../image/fbl.png"
#define HERO_FIREBALL_PATH2 " ://../image/fbr.png"
//基础属性
#define HERO_HP 3 //初始生命值
#define HERO_SPEED 30 //初始速度


//地图资源设置
#define MAP_PATH "://../image/bg.png"
#define MAP_PATH1 "://../image/bg1.png"
#define MAP_PATH2 "://../image/bg2.png"
#define MAP_PATH3 "://../image/bg3.png"
#define MAP_PATH4 "://../image/bg4.png"
#define MAP_BOSS_PATH "://../image/bossbg.gif"

#endif // CONFIG_H
