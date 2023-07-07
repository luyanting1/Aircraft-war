#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "Plane.h"

enum EnemyType {ORD, BOSS};

class EnemyPlane :protected Plane
{
	friend class Control;
public:
	EnemyPlane();
    EnemyPlane(double x, double y, const string &imageFile, QGraphicsScene *scene, EnemyType type, int life);
    pair<double,double> updatePosition();
    double getx() { return this->x(); }
    double gety() { return this->y(); }
    int gett() { return this->type; }

protected:
    EnemyType type;
	
};

#endif // !ENEMYPLANE_H

