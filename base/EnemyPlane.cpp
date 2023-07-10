#include "EnemyPlane.h"
#include <cstdlib>
#include <iostream>

EnemyPlane::EnemyPlane()
{
}

EnemyPlane::EnemyPlane(double x, double y,const string &imageFile, EnemyType type, int life):
    Plane(x, y, imageFile, life, ENEMY)
{
    this->type = type;
}

pair<double,double> EnemyPlane::updatePosition()
{
    return make_pair(x(), y()+2);
}
