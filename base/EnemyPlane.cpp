#include "EnemyPlane.h"
#include <cstdlib>
#include <iostream>

EnemyPlane::EnemyPlane()
{
}

EnemyPlane::EnemyPlane(double x, double y, EnemyType type, int life):
    Plane(x, y, life, ENEMY, type)
{
    this->type = type;
}

pair<double,double> EnemyPlane::updatePosition()
{
    return make_pair(x, y+2);
}
