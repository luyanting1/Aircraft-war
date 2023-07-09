#ifndef PLANE_H
#define PLANE_H

#include "Bullet.h"
#include "Object.h"
#include <QtWidgets>
#include <cstring>
#include <vector>
using namespace std;

class Plane: public Object
{
    friend class model;
public:
	Plane();
    Plane(double x, double y, int life, enum WarPart part);
    bool crash(); //飞机发生碰撞
	
protected:
	int life; //生命值
};

#endif // !PLANE_H
