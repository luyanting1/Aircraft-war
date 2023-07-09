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

enum EnemyType {ORD, BOSS};
enum WarPart { ME, ENEMY, LIFESUPPLY };
std::string  myBulletImageFile = ":/images/mybullet.png";
std::string enemyPlaneImageFile = ":/images/enemyplane.png";
std::string myPlaneImageFile = ":/images/myplane.png";
std::string bossImageFile = ":/images/boss2.gif";//boss图片

QPixmap pixmap1(QPixmap(QString::fromStdString(bossImageFile)));
const int bosswidth= pixmap1.width();
const int bossheight= pixmap1.height();

QPixmap pixmap2(QPixmap(QString::fromStdString(enemyPlaneImageFile)));
const int enemyplanewidth= pixmap2.width();
const int enemyplaneheight= pixmap2.height();

QPixmap pixmap3(QPixmap(QString::fromStdString(myPlaneImageFile)));
const int myplanewidth= pixmap3.width();
const int myplaneheight= pixmap3.height();

typedef double POS;
typedef std::vector<POS*> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<std::pair<WarPart, int>*> BULLETTYPES;
//int -> Whether Boss
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;

#endif // PRECOMP_H
