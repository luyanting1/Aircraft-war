#include "Object.h"

Object::Object()
{

}

Object::Object(double x,double y,int type2)
{
    this->x = x;
    this->y = y;
    this->type2 = type2;
}

Object::~Object()
{

}
/*
void Object::synScreen(QGraphicsScene *scene)
{
    if(!scene->items().contains(this))
    {
        scene->addItem(this);
        update();
    }
}

void Object::delScreen(QGraphicsScene *scene)
{
    scene->removeItem(this);
    update();
}

*/
