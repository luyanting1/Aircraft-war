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
extern std::string myBulletImageFile;
extern std::string enemyPlaneImageFile;
extern std::string myPlaneImageFile;
extern std::string bossImageFile;

extern QPixmap pixmap1;
extern const double bosswidth;
extern const double bossheight;

extern QPixmap pixmap2;
extern const double enemyplanewidth;
extern const double enemyplaneheight;

extern QPixmap pixmap3;
extern const double myplanewidth;
extern const double myplaneheight;

typedef double POS;
typedef std::vector<POS*> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<std::pair<WarPart, int>*> BULLETTYPES;
//int -> Whether Boss
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;

#endif // PRECOMP_H
