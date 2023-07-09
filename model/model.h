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

#include <QUrl>
//#include <QMediaPlaylist>
//#include <QMediaPlayer>

#include "./base/Plane.h"
#include "./base/MyPlane.h"
#include "./base/EnemyPlane.h"
#include "./common/precomp.h"


class model
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
     int enemyLife;
     int enemyBulletPower;
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
    bool playermove(char dir);
    bool playerbulletshoot();
    bool gamereset();
   // bool gamepause();
   // bool gamequit();
    bool skilluse(int sk_index);
    bool changeBulletPosition(Bullet * bullet, int newX, int newY);

    std::shared_ptr<MyPlane> GetMyPlane();
    std::shared_ptr<SCORE> GetPlayerScore();
    std::shared_ptr<vector<Bullet *>> GetBullets();
    std::shared_ptr<vector<EnemyPlane *>> GetEnemiesPlane();
    std::shared_ptr<int> GetPlayerLife();
    std::shared_ptr<int> GetPlayerSkill();

};

#endif
