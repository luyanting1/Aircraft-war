﻿#ifndef MYPLANE_H
#define MYPLANE_H

#include "init.h"
#include "Plane.h"
#include<common/common.h>

class MyPlane:public Plane
{
    friend class model;
public:
    MyPlane();
    MyPlane(double x, double y, int life, int skill);
    double& getx() { return this->x; }
    double& gety() { return this->y; }
    int& getskill() { return this->skill; }
    int& getlife() { return this->life; }
    void setx(double x) { this->x = x; }
    void sety(double y) { this->y = y; }
    void setskill(int _skill) { this->skill = _skill; }
    void setlife(int life1) { this->life = life1; }
    //Plane getp() { return this; }

protected:
    int skill; //技能值

};

#endif // !MYPLANE_H

