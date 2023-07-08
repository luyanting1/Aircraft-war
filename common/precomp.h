#ifndef PRECOMP_H
#define PRECOMP_H
#include "vector"
#include <cmath>
#include <iostream>
#include "view/view.h"
#define WIDTH 600
#define HEIGHT 800
QPixmap pixmap1(QPixmap(QString::fromStdString(bossImageFile)));
const int bosswidth= pixmap1.width();
const int bossheight= pixmap1.height();
 QPixmap pixmap2(QPixmap(QString::fromStdString(enemyPlaneImageFile)));
const int enemyplanewidth= pixmap2.width();
const int enemyplaneheight= pixmap2.height();
QPixmap pixmap3(QPixmap(QString::fromStdString(myPlaneImageFile)));
const int myplanewidth= pixmap3.width();
const int myplaneheight= pixmap3.height();
#endif // PRECOMP_H
