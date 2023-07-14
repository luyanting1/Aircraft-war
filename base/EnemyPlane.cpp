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

std::pair<double,double> EnemyPlane::updatePosition()
{
    return std::make_pair(x, y+2);
}
