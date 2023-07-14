#ifndef PLANE_H
#define PLANE_H

#include "init.h"
#include<common/common.h>
#include "common/Object.h"
//#include <QtWidgets>
#include <cstring>
#include <vector>

class Plane: public Object
{
    friend class model;
public:
    Plane();
    Plane(double x, double y, int life, enum WarPart part, int type2);
    void setx(double x) { this->x = x; }
    void sety(double y) { this->y = y; }
    bool crash(); //飞机发生碰撞

protected:
    int life; //生命值
    WarPart part;
};

#endif // !PLANE_H
