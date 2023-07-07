#include "EnemyPlane.h"
#include <cstdlib>

EnemyPlane::EnemyPlane()
{
}

EnemyPlane::EnemyPlane(double x, double y, const string &imageFile, QGraphicsScene *scene, EnemyType type, int life):
    Plane(x, y, imageFile, scene, life, ENEMY)
{
    this->type = type;
}

pair<double,double> EnemyPlane::updatePosition()
{
    return make_pair(x(), y()+2);
}
