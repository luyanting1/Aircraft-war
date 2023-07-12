﻿#include "Bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet()
{
}

Bullet::Bullet(WarPart part, double x, double y,EnemyType type1, const QPointF &dir, int power)
{
    //setPos(x, y);
    if(part == ME) type2 = 0;
       else
        if(type1 == ORD)
           type2 =1;
       else type2 = 2;
	this->dir = dir;
	this->power = power;
    Object(x,y,type2);
}

pair<qreal, qreal> Bullet::updatePosition()
{
    return make_pair(x+dir.x(), y+dir.y());
}
/*
bool Bullet::hit(QGraphicsScene *scene)
{
	if (power <= 0)
		return false;
	else if (--power <= 0) //杀伤力在此次hit之后耗尽
	{
        delScreen(scene);
		return false;
	}
	else
        return true;
}*/
