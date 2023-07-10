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


#define myplanewidth 120
#define myplaneheight 79
enum EnemyType {ORD, BOSS};
enum WarPart { ME, ENEMY, LIFESUPPLY };

typedef double POS;
typedef std::vector<POS*> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<std::pair<WarPart, int>*> BULLETTYPES;
//int -> Whether Boss
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;

#endif // PRECOMP_H
