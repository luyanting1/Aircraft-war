#include "MyPlane.h"
#include <iostream>
using namespace std;

MyPlane::MyPlane():Plane()
{
}

MyPlane::MyPlane(double x, double y,const string &imageFile, int life, int skill):
    Plane(x, y, imageFile, life, ME)
{
    this->skill = skill;
}
