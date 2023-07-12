#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <string>
#include<common/common.h>
using namespace std;

class Object
{
    friend class model;
public:
    Object();
    Object(double x,double y,WarPart part);
    ~Object();
    double& getx() { return this->x; }
    double& gety() { return this->y; }
   // void synScreen(QGraphicsScene *scene);
    //void delScreen(QGraphicsScene *scene);

protected:
    double x,y;
    int type2;
};

#endif // OBJECT_H
