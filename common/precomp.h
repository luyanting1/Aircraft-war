#ifndef PRECOMP_H
#define PRECOMP_H
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <QPixmap>
#include <QString>
//#include <QPair>


typedef double POS;
typedef std::vector<POS*> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<int*> BULLETTYPES;
//int -> Whether Boss
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;

#endif // PRECOMP_H
