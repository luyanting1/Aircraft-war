#ifndef OBJECT_H
#define OBJECT_H

#include <QtWidgets>
#include <string>
#include<common/precomp.h>
using namespace std;

class Object : public QGraphicsPixmapItem
{
    friend class model;
public:
    Object();
    Object(WarPart part, const string &imageFile);
    ~Object();
   // void synScreen(QGraphicsScene *scene);
    //void delScreen(QGraphicsScene *scene);

protected:
    enum WarPart part;
};

#endif // OBJECT_H
