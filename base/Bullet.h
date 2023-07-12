#ifndef BULLET_H
#define BULLET_H

#include "common/Object.h"
#include<common/common.h>
#include "init.h"
#include <utility>
#include <fstream>
#include <iostream>
#include <QPointF>
using namespace std;

class Bullet: public Object
{
    friend class model;
public:
    Bullet();
    Bullet(WarPart part, double x, double y,EnemyType type1,const QPointF &dir, int power);
    pair<double,double> updatePosition();
    //bool hit(QGraphicsScene *scene);
    double& getx() { return this->x; }
    double& gety() { return this->y; }
    void setx(double x) { this->x = x; }
    void sety(double y) { this->y = y; }
    int gett() { return this->type1; }
    WarPart getp() { return this->part; }
    int getpower() { return this->power; }
    int& gett2() { return this->type2; }

private:
    QPointF dir; //子弹方向，同时也控制了子弹速度
    int power; //子弹杀伤力
    EnemyType type1;
};

#endif // !BULLET_H

