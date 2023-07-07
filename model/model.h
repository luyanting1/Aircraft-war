#ifndef MODEL_H
#define MODEL_H
#include <memory>
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

     std::shared_ptr<int> score; //得分
     std::shared_ptr<int> myBulletType;//是否使用技能

public:
    model();

    bool framerun();
    bool playermove(std::string dir);
    bool gamereset();
    bool gamepause();
    bool gamequit();
    bool skilluse(int sk_index);

    std::shared_ptr<POS> GetPlayerPosx();
    std::shared_ptr<POS> GetPlayerPosy();
    std::shared_ptr<SCORE> GetPlayerScore();
    std::shared_ptr<POSES> GetBulletPosX();
    std::shared_ptr<POSES> GetBulletPosY();
    std::shared_ptr<BULLETTYPES> GetBulletType();
    std::shared_ptr<POSES> GetEmemiePosX();
    std::shared_ptr<POSES> GetEmemiePosY();
    std::shared_ptr<ENEMYTYPES> GetEmemieType();
    std::shared_ptr<int> GetPlayerLife();
    std::shared_ptr<int> GetPlayerSkill();

};

#endif
