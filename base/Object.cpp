#include "Object.h"

Object::Object()
{

}

Object::Object(double x,double y,WarPart part):
{
    this->x = x;
    this->y = y;
    this->part = part;
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
