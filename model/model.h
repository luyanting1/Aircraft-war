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
#include <windows.h>
#include <QGraphicsItem>
#include <QDebug>
#include <QUrl>
//#include <QMediaPlaylist>
//#include <QMediaPlayer>

#include "./base/Bullet.h"
#include "./base/Plane.h"
#include "./base/MyPlane.h"
#include "./base/EnemyPlane.h"
#include "./common/etlbase.h"
#include "./common/precomp.h"

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

#define mybulletwidth 128
#define mybulletheight 128

#define enemybulletwidth 90
#define enemybulletheight 44

class model: public Proxy_PropertyNotification<model>
{
private:
     std::shared_ptr<vector<EnemyPlane *>> enemyplanes;
     std::shared_ptr<vector<Bullet*>> enemybullets;
     MyPlane *myplane;
     std::shared_ptr<vector<Bullet*>> mybullets;
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

    POS*  GetPlayerPosX();
    POS*  GetPlayerPosY();
    std::shared_ptr<SCORE> GetPlayerScore();
    std::shared_ptr<POSES>    GetBulletsPosX();
    std::shared_ptr<POSES>    GetBulletsPosY();
    std::shared_ptr<BULLETTYPES>    GetBulletsType();
    std::shared_ptr<POSES>    GetEnemiesPosX();
    std::shared_ptr<POSES>    GetEnemiesPosY();
    std::shared_ptr<ENEMYTYPES>    GetEnemiesType();
    std::shared_ptr<POSES> GetLifeSuppliesPosX();
    std::shared_ptr<POSES> GetLifeSuppliesPosY();
    std::shared_ptr<int> GetPlayerLife();
    std::shared_ptr<int> GetPlayerSkill();

};

#endif
