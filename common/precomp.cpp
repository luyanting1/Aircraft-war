#include "precomp.h"
std::string  myBulletImageFile = ":/images/mybullet.png";
std::string enemyPlaneImageFile = ":/images/enemyplane.png";
std::string myPlaneImageFile = ":/images/myplane.png";
std::string bossImageFile = ":/images/boss2.gif";//boss图片

QPixmap pixmap1(QPixmap(QString::fromStdString(bossImageFile)));
const double bosswidth= pixmap1.width();
const double bossheight= pixmap1.height();

QPixmap pixmap2(QPixmap(QString::fromStdString(enemyPlaneImageFile)));
const double enemyplanewidth= pixmap2.width();
const double enemyplaneheight= pixmap2.height();

QPixmap pixmap3(QPixmap(QString::fromStdString(myPlaneImageFile)));
const double myplanewidth= pixmap3.width();
const double myplaneheight= pixmap3.height();
