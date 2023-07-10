#ifndef PRECOMP_H
#define PRECOMP_H
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <QPixmap>
#include <QString>
//#include <QPair>

#define WIDTH 600
#define HEIGHT 800

#define bosswidth 240
#define bossheight 240


#define enemyplanewidth 90
#define enemyplaneheight 69
#define myBulletImageFile  ":/images/mybullet.png"
#define enemyPlaneImageFile  ":/images/enemyplane.png"
#define myPlaneImageFile  ":/images/myplane.png"
#define bossImageFile  ":/images/boss2.gif"
//boss图片

#define enemyBulletImageFile  ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png"
//敌机子弹图片


#define bossBulletImageFile  ":/images/76446d7d2b8c45cb8ed30baf1f75397e.png"
//boss子弹图片

#define lifeSupplyImageFile  ":/images/lifesupply.png"
//补给图片

#define myplanewidth 120
#define myplaneheight 79
enum EnemyType {ORD, BOSS};
enum WarPart { ME, ENEMY, LIFESUPPLY };

typedef double POS;
typedef std::vector<POS*> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<int*> BULLETTYPES;
//int -> Whether Boss
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;

#endif // PRECOMP_H
