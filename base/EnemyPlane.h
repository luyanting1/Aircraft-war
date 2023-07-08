#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "Plane.h"
#include "model/model.h"

enum EnemyType {ORD, BOSS};

class EnemyPlane :public Plane
{
    friend class model;
public:
	EnemyPlane();
    EnemyPlane(double x, double y, EnemyType type, int life);
    pair<double,double> updatePosition();
    double getx() { return this->x(); }
    double gety() { return this->y(); }
    int gett() { return this->type; }
    int getl() { return this->life; }
    bool crash1() { return this->crash(); }

protected:
    EnemyType type;
	
};

#endif // !ENEMYPLANE_H

