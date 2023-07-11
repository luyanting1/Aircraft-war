#include "Plane.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

Plane::Plane()
{
}

Plane::Plane(double x, double y, int life, enum WarPart part):Object(x, y, part)
{
    this->life = life;
}

bool Plane::crash()
{
	if (life <= 0) //若已经耗尽生命值
		return false;
	else if (--life <= 0) //若生命值此次crash后耗尽
		return false;
	else
		return true;
}
