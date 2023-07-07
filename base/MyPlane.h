#ifndef MYPLANE_H
#define MYPLANE_H

#include "Plane.h"

class MyPlane:protected Plane
{
	friend class Control;
public:
	MyPlane();
    MyPlane(double x, double y, const string &imageFile, QGraphicsScene *scene, int life, int skill);
    double getx() { return this->x(); }
    double gety() { return this->y(); }
    int getskill() { return this->skill; }
    int getlife() { return this->life; }

private:
    int skill; //技能值
	
};

#endif // !MYPLANE_H

