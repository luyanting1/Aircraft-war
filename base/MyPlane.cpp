#include "MyPlane.h"
#include <iostream>
MyPlane::MyPlane():Plane()
{
}

MyPlane::MyPlane(double x, double y, int life, int skill):
    Plane(x, y, life, ME, 0)
{
    this->skill = skill;
}
