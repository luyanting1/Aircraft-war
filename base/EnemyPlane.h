#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "init.h"
#include "Plane.h"
#include<common/precomp.h>



class EnemyPlane :public Plane
{
    friend class model;
public:
    EnemyPlane();
    EnemyPlane(double x, double y,EnemyType type, int life);
    pair<double,double> updatePosition();
    double& getx() { return this->x; }
    double& gety() { return this->y; }
    EnemyType& gett() { return this->type; }
    int& getl() { return this->life; }
    bool crash1() { return this->crash(); }

protected:
    EnemyType type;

};

#endif // !ENEMYPLANE_H

