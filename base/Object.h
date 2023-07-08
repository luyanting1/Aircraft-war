#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <string>
using namespace std;

enum WarPart { ME, ENEMY, LIFESUPPLY };

class Object : public QGraphicsPixmapItem
{
    friend class model;
public:
    Object();
    Object(WarPart part);
    ~Object();
   // void synScreen(QGraphicsScene *scene);
    //void delScreen(QGraphicsScene *scene);

protected:
    enum WarPart part;
};

#endif // OBJECT_H
