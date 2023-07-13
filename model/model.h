#ifndef MODEL_H
#define MODEL_H
#include <memory>
#include <ctime>
#include <vector>
#include <cassert>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QDebug>
#include <QUrl>
//#include <QMediaPlaylist>
//#include <QMediaPlayer>
#include "./base/Bullet.h"
#include "./base/Plane.h"
#include "./base/MyPlane.h"
#include "./base/EnemyPlane.h"
#include "./common/etlbase.h"
#include "./common/common.h"

#define WIDTH 600
#define HEIGHT 800

#define bosswidth 240
#define bossheight 240

#define enemyplanewidth 90
#define enemyplaneheight 69

#define lifesupplywidth 26
#define lifesupplyheight 24

#define myplanewidth 120
#define myplaneheight 79

#define mybulletwidth 18
#define mybulletheight 35

#define enemybulletwidth 18
#define enemybulletheight 18

class model: public Proxy_PropertyNotification<model>
{
private:
     std::shared_ptr<vector<EnemyPlane *>> enemyplanes;
     std::shared_ptr<OBJECTS> enemyplanes1;
     std::shared_ptr<vector<Bullet*>> enemybullets;
     std::shared_ptr<OBJECTS> enemybullets1;
     std::shared_ptr<MyPlane> myplane;
     std::shared_ptr<Object> myplane1;
     std::shared_ptr<vector<Bullet*>> mybullets;
     std::shared_ptr<OBJECTS> mybullets1;
     std::shared_ptr<vector<Object*>> lifesupplys;
     QPointF myPlaneMove;

     std::shared_ptr<int> score; //得分
     std::shared_ptr<int> myBulletType;//是否使用技能
     int width1 = 800;
     int height1 = 600;
     int myBulletPower;
     int enemyBulletPower;
     int enemyLife;
     int bossLife;
     int bossBulletPower;
     int myLife;
     int mySkill;

public:
    model();

    bool framerun();
    bool allbulletmove();
    bool bossgenerate(); //boss生成
    bool enemybulletshoot();
    bool enemygenerate();
    bool changePlanePosition(Plane *plane, int newX, int newY);
    bool enemymove();
    bool playergenerate();
    bool playermove(char dir);
    bool playerbulletshoot();
    bool gamereset();
   // bool gamepause();
   // bool gamequit();
    bool skilluse(int sk_index);
    bool changeBulletPosition(Bullet * bullet, int newX, int newY);

   // POS*  GetPlayerPosX();
   // POS*  GetPlayerPosY();
    std::shared_ptr<SCORE> GetPlayerScore();
    std::shared_ptr<Object> GetMyPlane();
    std::shared_ptr<OBJECTS> GetEnemiesPlane();
    std::shared_ptr<OBJECTS> GetBullets();
    std::shared_ptr<OBJECTS> GetLifeSupplies();
    std::shared_ptr<int> GetPlayerLife();
    std::shared_ptr<int> GetPlayerSkill();

};

#endif
