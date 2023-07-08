#include "MyPlane.h"
#include <iostream>
using namespace std;

MyPlane::MyPlane():Plane()
{
}

MyPlane::MyPlane(double x, double y,int life, int skill):
    Plane(x, y,  life, ME)
{
    this->skill = skill;
}
