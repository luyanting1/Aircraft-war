#include "Object.h"

Object::Object()
{

}

Object::Object(WarPart part)
{
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
