#ifndef OBJECT_H
#define OBJECT_H

#include "init.h"
#include <QtWidgets>
#include <string>
#include<common/precomp.h>
using namespace std;

class Object
{
    friend class model;
public:
    Object();
    Object(double x,double y,WarPart part);
    ~Object();
   // void synScreen(QGraphicsScene *scene);
    //void delScreen(QGraphicsScene *scene);

protected:
    double x,y;
    enum WarPart part;
};

#endif // OBJECT_H
