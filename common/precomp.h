#ifndef PRECOMP_H
#define PRECOMP_H

#include <vector>
#include <cmath>
#include <iostream>
#include "base/Object.h"
// define part has not been modified
#define WIDTH 1266
#define HEIGHT 766
#define ROLE_WIDTH 140
#define ROLE_HEIGHT 120
#define HOOK_BIAS 40
#define PI 3.1415926
#define MAX_ANGLE 80
#define MINE_NUM 10
#define IMAGE_MAX 21
#define DeadAngleRange 10
#define LEN 50
#define MAPUPPERBOUND 120
#define VIGOSPEED 2
#define DEFAULT_PLAYER_NUM 3
#define DEFAULT_MINE_NUM 15
#define DEFAULT_HOOK_SPEED 2.5
#define LEVELTIME 60
#define DEBUGTIME 0
#define DIS(A) \
sqrt(pow(A.getx() - x, 2) + pow(A.gety() - y, 2))

typedef double* POS;
typedef std::vector<POS> POSES;
//Warpart == Me, int -> shoot mode; Warpart == ENEMY, int -> Whether Boss; Warpart == LIFESUPPLY, int any
typedef std::vector<pair<Warpart, int>*> BULLETTYPES;
typedef std::vector<int*> ENEMYTYPES;
typedef int BAR;
typedef int SCORE;


#endif // PRECOMP_H
